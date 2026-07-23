"""
Configuration file for the Push Swap Benchmark.

Modify these values instead of editing the scripts.
"""

from pathlib import Path
import numpy as np

# ------------------------------------------------------------
# Path to push_swap executable
# ------------------------------------------------------------
BASE_DIR = Path(__file__).resolve().parent

PUSH_SWAP = BASE_DIR.parent / "push_swap"

# ------------------------------------------------------------
# Benchmark parameters
# ------------------------------------------------------------

# Number of random tests for each (algorithm, size)
TRIALS = 100

# Sizes to test
SIZES = list(range(5, 501, 5))

# Algorithms to test
ALGORITHMS = [
    "--simple",
    "--medium",
    "--complex",
    "--adaptive"
]

# Disorder levels to test
DISORDERS = np.linspace(0, 1, 21)

# Random seed
SEED = 42

# ------------------------------------------------------------
# Output folders
# ------------------------------------------------------------

RESULTS_DIR = Path("push_swap_benchmark/results")
GRAPHS_DIR = Path("push_swap_benchmark/graphs")

RESULTS_DIR.mkdir(exist_ok=True)
GRAPHS_DIR.mkdir(exist_ok=True)