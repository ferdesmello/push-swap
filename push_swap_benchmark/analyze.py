"""
Analyze benchmark results.

Creates several graphs from benchmark.csv.
"""

from pathlib import Path

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import binned_statistic_2d
import matplotlib.colors as mcolors

from config import (
    RESULTS_DIR,
    GRAPHS_DIR,
)

CSV = RESULTS_DIR / "benchmark.csv"

# ---------------------------------------------------------
# Load data
# ---------------------------------------------------------

df = pd.read_csv(CSV)

#print(df.groupby("algorithm")["operations"].describe())
#print(df.groupby("algorithm")["operations"].mean())

df["disorder"] = df["disorder"].clip(0, 1)

print(df.head())

global_min = df["operations"].min()
global_max = df["operations"].max()

bins = np.arange(0, 1.05, 0.05)

df["disorder_bin"] = pd.cut(
    df["disorder"],
    bins=bins,
    include_lowest=True
)

# ---------------------------------------------------------
# 2D histogram with letters
# ---------------------------------------------------------

def plot_classified_hexbin(df, algorithm, output_dir):
    subset = df[df["algorithm"] == algorithm].copy()
    
    # 1. Calculate the grade color code for each raw row first
    # 3 = Excellent, 2 = Good, 1 = Pass, 0 = Fail
    hex_classes = []
    for s, o in zip(subset["size"], subset["operations"]):
        if s <= 100:
            if o < 700:    hex_classes.append(3)
            elif o < 1500: hex_classes.append(2)
            elif o < 2000: hex_classes.append(1)
            else:          hex_classes.append(0)
        elif s >= 500:
            if o < 5500:   hex_classes.append(3)
            elif o < 8000: hex_classes.append(2)
            elif o < 12000:hex_classes.append(1)
            else:          hex_classes.append(0)
        else:
            if o < 5500:   hex_classes.append(3)
            elif o < 8000: hex_classes.append(2)
            elif o < 12000:hex_classes.append(1)
            else:          hex_classes.append(0)
            
    subset["performance_class"] = hex_classes

    # 2. Build the discrete visualization
    plt.figure(figsize=(10, 8))
    
    colors = ["#d62728", "#FEBE10", "#90EE90", "#006400"] # Red, Yellow, Light-Green, Dark-Green
    cmap = mcolors.ListedColormap(colors)
    bounds = [-0.5, 0.5, 1.5, 2.5, 3.5]
    norm = mcolors.BoundaryNorm(bounds, cmap.N)
    
    # 3. Plot the hexbin layer
    # reduce_C_function=np.median handles multiple points inside the same hexagon
    hb = plt.hexbin(
        subset["size"],
        subset["disorder"],
        C=subset["performance_class"], 
        reduce_C_function=np.median,     
        gridsize=45, # Adjust this number higher to make hexagons even smaller
        cmap=cmap,
        norm=norm,
        edgecolors="white",           
        linewidths=0.3,
        mincnt=1
    )
    
    # 4. Formatting legend bar and layout labels
    cb = plt.colorbar(hb, ticks=[0, 1, 2, 3], label="Performance Grade")
    cb.ax.set_yticklabels(["Fail", "Pass", "Good", "Excellent"])
    
    plt.xlabel("Number of parameters (Size)")
    plt.ylabel("Disorder")
    plt.title(f"{algorithm.capitalize()} Algorithm - Hexagonal Performance Map")
    plt.grid(True, linestyle=":", alpha=0.4)
    
    plt.tight_layout()
    plt.savefig(output_dir / f"performance_hexbin_{algorithm}.png", dpi=300)
    plt.close()

algorithms = df["algorithm"].unique()
for algorithm in algorithms:
    plot_classified_hexbin(df, algorithm, GRAPHS_DIR)

# ---------------------------------------------------------
# 2D histogram
# ---------------------------------------------------------

def plot_2d_histogram(df, algorithm, output_dir):
    """
    Plot a 2D histogram of operations using median aggregation.
    X axis: number of parameters (size)
    Y axis: disorder
    Color: median number of operations
    """
    subset = df[df["algorithm"] == algorithm]
    
    plt.figure(figsize=(10, 8))
    
    # gridsize=(X_bins, Y_bins). Adjust numbers to match your data density.
    # C passes the Z-values, and reduce_C_function defines the aggregation.
    hb = plt.hexbin(
        subset["size"], 
        subset["disorder"], 
        C=subset["operations"], 
        reduce_C_function=np.median, 
        gridsize=(50, 50), 
        cmap="viridis",
        vmin=global_min,
        vmax=global_max,
        extent=[df["size"].min(), df["size"].max(), 0, 1] # Forces uniform axes limits
    )
    
    # Add colorbar and labels
    cb = plt.colorbar(hb, label="Median Operations")
    
    plt.xlabel("Number of parameters (Size)")
    plt.ylabel("Disorder")
    plt.title(f"{algorithm.capitalize()} Algorithm - Median Operations")
    plt.grid(True, linestyle="--", alpha=0.5)
    
    plt.tight_layout()
    plt.savefig(
        output_dir / f"2d_histogram_hexbin_{algorithm}.png", 
        dpi=300
    )
    plt.close()

algorithms = df["algorithm"].unique()
for algorithm in algorithms:
    plot_2d_histogram(df, algorithm, GRAPHS_DIR)

# ---------------------------------------------------------
# Heatmap
# ---------------------------------------------------------

def plot_heatmap(df, algorithm, output_dir):
    """
    Plot a heatmap of operations.

    X axis: number of parameters
    Y axis: disorder
    Color: number of operations
    """

    subset = df[df["algorithm"] == algorithm]

    heatmap = subset.pivot_table(
        index="disorder_bin",
        columns="size",
        values="operations",
        aggfunc="mean",
		observed=False
    )

    x = range(len(heatmap.columns))
    y = range(len(heatmap.index))

    plt.figure(figsize=(10, 8))

    heatmap = heatmap.sort_index()

    heatmap = heatmap.reindex(
        sorted(heatmap.columns),
        axis=1
    )

    mesh = plt.pcolormesh(
        heatmap.values,
        shading="nearest",
        cmap="viridis",
        edgecolors="white",
        linewidth=0.2,
        vmin=global_min,
        vmax=global_max
    )

    plt.grid(True, linestyle="--", alpha=0.5)

    plt.colorbar(mesh, label="Operations")

    """plt.xticks(
       [i + 0.5 for i in x],
       heatmap.columns,
       rotation=90
    )

    plt.yticks(
        [i + 0.5 for i in y],
        [f"{d:.2f}" for d in heatmap.index]
    )"""

    plt.xlabel("Number of parameters")
    plt.ylabel("disorder")
    plt.title(f"{algorithm.capitalize()} algorithm")

    plt.tight_layout()

    plt.savefig(
        output_dir / f"heatmap_{algorithm}.png",
        dpi=300
    )

    plt.close()

"""algorithms = df["algorithm"].unique()

for algorithm in algorithms:
    plot_heatmap(df, algorithm, GRAPHS_DIR)"""

# ---------------------------------------------------------
# Complexity fit table
# ---------------------------------------------------------

def r2_score(y, y_pred):
    ss_res = np.sum((y - y_pred) ** 2)
    ss_tot = np.sum((y - np.mean(y)) ** 2)
    return 1 - ss_res / ss_tot

def fit_model(x, y, basis):

    coeff = np.polyfit(basis, y, 1)

    prediction = coeff[0] * basis + coeff[1]

    return r2_score(y, prediction)

avg = (
    df.groupby(["algorithm", "size"])["operations"]
      .mean()
      .reset_index()
)

print("\n")
print("=" * 72)
print("Complexity goodness of fit (R²)")
print("=" * 72)

header = (
    f"{'Algorithm':<12}"
    f"{'O(n)':>12}"
    f"{'O(n log n)':>14}"
    f"{'O(n√n)':>12}"
    f"{'O(n²)':>12}"
)

print(header)
print("-" * len(header))

for algorithm in avg["algorithm"].unique():

    data = avg[avg["algorithm"] == algorithm]

    n = data["size"].to_numpy(dtype=float)
    y = data["operations"].to_numpy(dtype=float)

    models = {
        "size": n,
        "nlogn": n * np.log2(n),
        "nsqrtn": n * np.sqrt(n),
        "n2": n ** 2,
    }

    r2_linear = fit_model(n, y, models["size"])
    r2_log = fit_model(n, y, models["nlogn"])
    r2_sqrt = fit_model(n, y, models["nsqrtn"])
    r2_quad = fit_model(n, y, models["n2"])

    print(
        f"{algorithm:<12}"
        f"{r2_linear:>12.4f}"
        f"{r2_log:>14.4f}"
        f"{r2_sqrt:>12.4f}"
        f"{r2_quad:>12.4f}"
    )

# ---------------------------------------------------------
# Grade function
# ---------------------------------------------------------

def classify(size, operations):
    if size <= 100:
        if operations < 700: return "E"   # Excellent
        if operations < 1500: return "G"  # Good
        if operations < 2000: return "P"  # Pass
        return "F"                        # Fail
    if size >= 500:
        if operations < 5500: return "E"
        if operations < 8000: return "G"
        if operations < 12000: return "P"
        return "F"
    return "U"                            # Unknown


df["grade"] = [
    classify(s, o)
    for s, o in zip(df["size"], df["operations"])
]

# ---------------------------------------------------------
# Average operations
# ---------------------------------------------------------

# Mapeamento fixo para garantir que cada algoritmo tenha sempre a mesma cor
ALGORITHM_COLORS = {
    "simple": "#FEBE10",   # Yellow
    "medium": "#90EE90",   # Light-Green
    "complex": "#006400",  # Dark-Green
	"adaptive": "#0000FF", # Blue
    # Adicione os outros algoritmos do seu benchmark aqui se houver mais
}
# Cor padrão caso apareça algum algoritmo novo não listado acima
DEFAULT_COLOR = "#7f7f7f"  # Cinza

plt.figure(figsize=(10, 6))

for algorithm in algorithms:
    subset = df[df["algorithm"] == algorithm]
    grouped = (
        subset
        .groupby("size")["operations"]
        .mean()
    )

	# Busca a cor do dicionário, usa a cinza como alternativa segura
    algo_color = ALGORITHM_COLORS.get(algorithm, DEFAULT_COLOR)

    plt.plot(
        grouped.index,
        grouped.values,
        marker="o",
        label=algorithm,
		color=algo_color
    )

plt.xlabel("Number of parameters")
plt.ylabel("Average operations")
plt.title("Average operations")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()

plt.savefig(
    GRAPHS_DIR / "average_operations.png",
    dpi=200
)

plt.close()

# ---------------------------------------------------------
# Standard deviation
# ---------------------------------------------------------

plt.figure(figsize=(10, 6))

for algorithm in algorithms:
    subset = df[df["algorithm"] == algorithm]
    grouped = (
        subset
        .groupby("size")["operations"]
    )

    mean = grouped.mean()
    std = grouped.std()

	# Busca a cor mapeada para o algoritmo atual
    algo_color = ALGORITHM_COLORS.get(algorithm, DEFAULT_COLOR)

    plt.errorbar(
        mean.index,
        mean.values,
        yerr=std.values,
        capsize=3,
        label=algorithm,
		color=algo_color
    )

plt.xlabel("Number of parameters")
plt.ylabel("Operations")
plt.title("Mean ± Standard deviation")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()

plt.savefig(
    GRAPHS_DIR / "variance.png",
    dpi=200
)

plt.close()

# ---------------------------------------------------------
# Normalized complexity plot
# ---------------------------------------------------------

avg = (
    df.groupby(["algorithm", "size"])["operations"]
      .mean()
      .reset_index()
)

fig, ax = plt.subplots(figsize=(12, 7))

for algorithm in avg["algorithm"].unique():

    algo_color2 = ALGORITHM_COLORS.get(algorithm, DEFAULT_COLOR)
    data = avg[avg["algorithm"] == algorithm].copy()

    n = data["size"].to_numpy()
    ops = data["operations"].to_numpy()

    if algorithm == "simple":
        normalized = ops / (n ** 2)
        label = "simple / n²"

    elif algorithm == "medium":
        normalized = ops / (n * np.sqrt(n))
        label = "medium / (n√n)"

    elif algorithm == "complex":
        normalized = ops / (n * np.log2(n))
        label = "complex / (n log₂ n)"

    elif algorithm == "adaptive":
        # Adaptive has no single theoretical complexity.
        # Normalizing by n log n is a reasonable default.
        normalized = ops / (n * np.log2(n))
        label = "adaptive / (n log₂ n)"

    ax.plot(
        n,
        normalized,
        marker="o",
        linewidth=2,
        markersize=4,
        label=label,
		color=algo_color2
    )

ax.set_title("Normalized operation count")
ax.set_xlabel("Number of parameters")
ax.set_ylabel("Normalized operations")
ax.grid(True, linestyle="--", alpha=0.5)
ax.legend()

plt.tight_layout()
plt.savefig(GRAPHS_DIR / "normalized_operations.png")
plt.close()


print()

print("Graphs saved to")

print(GRAPHS_DIR)