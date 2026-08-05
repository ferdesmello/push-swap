# Python Complexity Analysis

This folder contains the Python tooling used to benchmark `push_swap` and
analyze how the number of generated operations grows with input size and input
disorder.

It is intentionally separate from the main project documentation, but it
depends on the compiled `push_swap` executable in the repository root.

## What it does

The scripts in this folder can:

- run repeated benchmarks against the available sorting strategies
- measure the initial disorder of each generated permutation
- store benchmark results as CSV files
- generate graphs that summarize average complexity, variance, and performance
- print a simple complexity fit table for the collected data

## Folder contents

- `benchmark.py`: runs the benchmark suite and writes `results/benchmark.csv`
- `analyze.py`: reads `results/benchmark.csv` and generates graphs in `graphs/`
- `config.py`: central configuration for paths, sizes, trials, and algorithms
- `disorder.py`: computes the disorder metric used by the benchmark
- `generators.py`: helper functions that create input permutations

## Requirements

The scripts use Python together with the following packages:

- `numpy`
- `pandas`
- `matplotlib`
- `scipy`
- `tqdm`

The benchmark also requires a compiled `push_swap` binary at the repository
root, because `config.py` points to `../push_swap` from this folder.

## Setup

From the repository root, install the Python dependencies in the environment of
your choice. For example:

```sh
python3 -m pip install numpy pandas matplotlib scipy tqdm
```

Then build the project so the `push_swap` executable exists:

```sh
make
```

## Running the benchmark

Run the benchmark from the repository root:

```sh
python3 python_complexity/benchmark.py
```

This executes each configured strategy over the configured sizes and trial
count, then writes the collected data to:

```text
python_complexity/results/benchmark.csv
```

## Running the analysis

After a benchmark file exists, generate the graphs and complexity summary with:

```sh
python3 python_complexity/analyze.py
```

This reads `python_complexity/results/benchmark.csv` and writes plots to:

```text
python_complexity/graphs/
```

The analysis script currently produces:

- average operations per size and algorithm
- standard deviation plots
- normalized complexity plots
- per-algorithm performance maps and hexbin summaries

It also prints a small table with goodness-of-fit values for candidate growth
models such as `O(n)`, `O(n log n)`, `O(n√n)`, and `O(n²)`.

## Configuration

Most benchmark settings live in `config.py`:

- `TRIALS`: number of random permutations per size and strategy
- `SIZES`: list of input sizes to test
- `ALGORITHMS`: strategies passed to `push_swap`
- `SEED`: random seed used for reproducible runs

If you want to change the benchmark scope, edit `config.py` instead of the
scripts themselves.

## Notes

- Run the scripts from the repository root so the relative paths in
  `config.py` resolve correctly.
- The outputs in `results/` and `graphs/` are generated artifacts and can be
  regenerated at any time.