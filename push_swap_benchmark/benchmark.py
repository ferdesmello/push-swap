"""
Benchmark push_swap.

Runs every algorithm on random permutations of several sizes and
stores the results in results/benchmark.csv.
"""

import random
import subprocess
import time

import pandas as pd
from tqdm import tqdm

from config import (
    PUSH_SWAP,
    ALGORITHMS,
    SIZES,
    TRIALS,
    RESULTS_DIR,
    SEED,
)

from generators import random_permutation
from disorder import compute_disorder

random.seed(SEED)


def run_push_swap(algorithm, values):
    """
    Executes push_swap.

    Returns:
        operation_count,
        elapsed_time_seconds
    """

    command = [PUSH_SWAP]

    if algorithm != "--adaptive":
        command.append(algorithm)

    command.extend(map(str, values))

    start = time.perf_counter()

    result = subprocess.run(
        command,
        capture_output=True,
        text=True
    )

    elapsed = time.perf_counter() - start

    if result.returncode != 0:
        raise RuntimeError(result.stderr)

    operations = result.stdout.strip().splitlines()

    return len(operations), elapsed


def benchmark():

    rows = []

    total = len(ALGORITHMS) * len(SIZES) * TRIALS

    with tqdm(total=total) as progress:

        for algorithm in ALGORITHMS:

            for size in SIZES:

                for trial in range(TRIALS):

                    values = random_permutation(size)

                    disorder = compute_disorder(values)

                    operations, elapsed = run_push_swap(
                        algorithm,
                        values
                    )

                    rows.append({
                        "algorithm": algorithm.replace("--", ""),
                        "size": size,
                        "trial": trial,
                        "disorder": disorder,
                        "operations": operations,
                        "time": elapsed,
                    })

                    progress.update()

    df = pd.DataFrame(rows)

    output = RESULTS_DIR / "benchmark.csv"

    df.to_csv(output, index=False)

    print()
    print(f"Saved {len(df)} tests")
    print(output)


if __name__ == "__main__":
    benchmark()