*This project has been created as part of the 42 curriculum by iscarval and ferde-so.*

# Push_swap

## Description

**Push_swap** is an algorithmic sorting project from the 42 curriculum.

The objective is to sort a sequence of integers using two stacks, `a` and `b`,
and a restricted set of operations while generating as few Push_swap
instructions as possible.

At the beginning:

- Stack `a` contains all input integers.
- Stack `b` is empty.
- The first argument represents the top of stack `a`.

The program outputs the sequence of Push_swap operations required to sort
stack `a` in ascending order.

This implementation provides four sorting modes:

- Simple — `O(n²)`
- Medium — `O(n√n)`
- Complex — `O(n log n)`
- Adaptive

The Adaptive strategy analyzes the initial disorder of the input and
automatically selects one of the three sorting strategies.

The project also provides a `--bench` mode that reports the initial disorder,
selected strategy, complexity class, total number of operations and individual
operation counts.

---

# Instructions

## Compilation

Compile the project with:

```sh
make
```

The project is compiled using:

```text
-Wall -Wextra -Werror
```

Available Makefile rules:

```sh
make
make clean
make fclean
make re
```

## Basic Usage

```sh
./push_swap 5 2 8 1 3
```

The program prints one Push_swap instruction per line.

If no strategy flag is provided, the Adaptive strategy is used by default.

## Strategy Selection

Simple:

```sh
./push_swap --simple 5 2 8 1 3
```

Medium:

```sh
./push_swap --medium 5 2 8 1 3
```

Complex:

```sh
./push_swap --complex 5 2 8 1 3
```

Adaptive:

```sh
./push_swap --adaptive 5 2 8 1 3
```

Benchmark mode can be combined with a strategy:

```sh
./push_swap --bench --complex 5 2 8 1 3
```

---

# Push_swap Operations

The following operations are available:

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the first element of `b` to `a` |
| `pb` | Push the first element of `a` to `b` |
| `ra` | Rotate stack `a` |
| `rb` | Rotate stack `b` |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | Execute `rra` and `rrb` simultaneously |

---

# Sorting Strategies

The project implements different sorting strategies with different
operation-growth classes.

In this project, complexity refers to how the number of generated Push_swap
operations grows as the input size `n` increases.

---

## Small Inputs

Inputs containing five elements or fewer are handled by specialized functions
instead of the general sorting strategies.

### Two elements

For two elements, the program checks whether the values are reversed and
performs `sa` when necessary.

### Three elements

For three elements, the maximum value is located and rotations are used to
position it correctly. A final swap is performed when required.

### Four and five elements

The smallest elements are moved to stack `b` until three elements remain in
stack `a`.

The remaining three elements are sorted and the stored minimum elements are
pushed back to `a`.

Specialized sorting avoids applying a larger general-purpose algorithm to very
small inputs.

---

# Simple Strategy — O(n²)

The Simple strategy is based on repeated minimum extraction.

For each iteration:

1. Find the minimum value in stack `a`.
2. Find its position.
3. Rotate or reverse rotate `a` using the shortest direction.
4. Push the minimum to stack `b`.
5. Repeat until `a` is empty.
6. Push all elements back to `a`.

For each of the `n` elements, positioning the next minimum can require a number
of operations proportional to `n`.

Therefore, the upper bound grows quadratically:

```text
n × n = n²
```

Resulting in:

```text
O(n²)
```

This strategy is straightforward and is used by the Adaptive mode for inputs
with low initial disorder.

---

# Medium Strategy — O(n√n)

The Medium strategy uses a **chunk-based approach**.

Before sorting, each node receives an index corresponding to its position in
the fully sorted sequence.

The algorithm then:

1. Groups indexed values into ranges or chunks.
2. Searches stack `a` from both the top and bottom for values belonging to the
   current range.
3. Moves the selected element to the top using the shortest direction.
4. Pushes the element to stack `b`.
5. Uses rotations in `b` to improve its internal distribution.
6. Repeats until all elements have been moved to `b`.
7. Finds the largest remaining index in `b`.
8. Moves it to the top.
9. Pushes it back to `a`.
10. Repeats until `b` is empty.

This chunk-based organization reduces the amount of stack traversal compared
with repeated minimum extraction and represents the project's intermediate
complexity class:

```text
O(n√n)
```

The implementation uses chunk sizes selected according to the input ranges
targeted by the project.

---

# Complex Strategy — Binary Radix Sort — O(n log n)

The Complex strategy uses **Binary Radix Sort** over normalized indexes.

Before the algorithm runs, each value receives an index representing its final
sorted position.

For example:

```text
Values:   42   -3   15   100
Indexes:   2    0    1     3
```

The indexes range from `0` to `n - 1`, allowing the algorithm to process them
using their binary representation.

## Number of Bits

The algorithm first determines how many bits are required to represent the
maximum index.

For example, with eight indexes:

```text
0 → 000
1 → 001
2 → 010
3 → 011
4 → 100
5 → 101
6 → 110
7 → 111
```

Three bits are sufficient.

The number of relevant bits grows approximately as:

```text
log₂(n)
```

## Sorting Each Bit

The algorithm processes the indexes one bit at a time, starting from the least
significant bit.

For every element in stack `a`:

- If the current bit is `0`, the element is pushed to `b` using `pb`.
- If the current bit is `1`, stack `a` is rotated using `ra`.

After all elements for the current bit have been processed, every element in
`b` is returned to `a` using `pa`.

The same process is repeated for the next bit until all relevant bits have been
processed.

## Complexity

For each bit, the algorithm processes a number of elements proportional to
`n`.

The number of relevant bits is proportional to:

```text
log₂(n)
```

Therefore:

```text
n elements × log₂(n) bit passes
```

gives the upper-bound class:

```text
O(n log n)
```

The additional `pa` operations used to return elements from stack `b` are also
bounded by a constant multiple of `n` per bit and therefore do not change the
asymptotic complexity.

This makes Binary Radix Sort suitable for the Complex strategy because its
operation-growth bound can be derived directly from the structure of the
algorithm.

---

# Complex Strategy — Benchmark Results

The Binary Radix implementation was tested with different input sizes using
the project's benchmark mode.

Example results:

| Input size | Total operations |
|---:|---:|
| 50 | 467 |
| 100 | 1,084 |
| 200 | 2,468 |
| 400 | 5,536 |
| 500 | 6,784 |
| 800 | 12,272 |

For 500 elements, the operation distribution was:

```text
pa: 2284
pb: 2284
ra: 2216
total: 6784
```

The Binary Radix strategy primarily uses `pb`, `ra` and `pa`.

For 500 elements, indexes range from `0` to `499`, requiring 9 relevant bits.

During each bit pass, every element in stack `a` generates either `pb` or `ra`.

Therefore:

```text
500 elements × 9 bit passes = 4500 operations
```

In the measured execution:

```text
pb + ra
2284 + 2216
= 4500
```

The elements moved to `b` are subsequently returned with `pa`:

```text
4500 + 2284 = 6784
```

This demonstrates how the operation count is produced by the structure of the
Binary Radix implementation.

The observed benchmark growth is consistent with the theoretical
`O(n log n)` operation bound.

The benchmark results provide empirical validation and are not used as a
substitute for the theoretical complexity analysis.

---

# Adaptive Strategy

Adaptive mode is the default behavior when no explicit strategy flag is
provided.

Before sorting begins, the program calculates the initial disorder of stack
`a`.

Based on that value, it selects one of the three strategies.

## Disorder Metric

The disorder metric is based on inversions.

For every pair of elements `(i, j)` where `j > i`, an inversion exists when:

```text
a[i] > a[j]
```

The disorder ratio is calculated as:

```text
number of inversions / total number of pairs
```

Therefore:

```text
0.0 → completely sorted
1.0 → completely reversed
```

A partially ordered input produces a value between these extremes.

## Adaptive Thresholds

| Initial disorder | Selected strategy | Complexity class |
|---|---|---|
| `< 20%` | Simple | `O(n²)` |
| `20% – < 50%` | Medium | `O(n√n)` |
| `>= 50%` | Complex / Binary Radix | `O(n log n)` |

The thresholds allow the program to choose a strategy according to the initial
organization of the input instead of applying the same algorithm to every
sequence.

Low-disorder inputs use the simpler minimum-extraction approach.

Medium-disorder inputs use chunk-based organization.

Highly disordered inputs use Binary Radix Sort, providing a predictable
`O(n log n)` operation-growth bound.

## Extra Empirical Complexity Analysis

We ran all the algorithms for a range of n values up to 5000 and compared the results with three methods:

* $R^{2}$ - We fitted all three O-complexity functions over the data produced for each algorithm and checked which one produced the best $R^{2}$ (closer to 1 is better).
* $k$ exponent - We fitted $n^{k}$ over the data produced for each algorithm and checked if the exponent $k$ is closer to the expectation for that algorithmic complexity.
* Flattening - We divided the data produced for each algorithm by the expected O-complexity functions. If it was the right functions, the results (over large n) would flatten; we would see horizontal lines.

None of the methods is perfect, as the O-complexity gives an upper bound, not a normal operation behavior, and the data used is very limited, as the O-complexity would be better seen when n → ∞. But the results are consistent, with the curve flattening and the fits producing the results below.

Complexity Analysis: Goodness of Fit (R²) & Growth Exponent (k) for n up to 5000
| Algorithm  | O(n)   | O(n log n) | O(n√n) | O(n²)  | Exp (k) | Expected |
|--------|--------|------------|--------|--------|---------|----------|
| adaptive   | 0.9457 | 0.9588     | 0.9400 | 0.9051 | 1.35    |     ?    |
| complex    | 0.9937 | **0.9964**     | 0.9887 | 0.9579 | 1.27    | ~1.0-1.3 |
| medium     | 0.9649 | 0.9775     | **0.9977** | 0.9952 | 1.41    | ~1.5     |
| simple     | 0.9360 | 0.9534     | 0.9876 | **1.0000** | 1.91    | ~2.0     |

---

# Benchmark Mode

Benchmark mode is enabled using:

```sh
--bench
```

For example:

```sh
./push_swap --bench --adaptive 8 3 6 1 7 2 5 4
```

The normal Push_swap instruction stream is written to `stdout`.

Benchmark information is written exclusively to `stderr`.

This separation means benchmark output does not interfere with pipes or the
Push_swap checker.

Example output:

```text
[bench] disorder: 60.71%
[bench] strategy: adaptive -> complex / O(n log n)
[bench] total_ops: ...
[bench] sa: ...
[bench] sb: ...
[bench] ss: ...
[bench] pa: ...
[bench] pb: ...
[bench] ra: ...
[bench] rb: ...
[bench] rr: ...
[bench] rra: ...
[bench] rrb: ...
[bench] rrr: ...
```

Benchmark mode reports:

- Initial disorder percentage
- Selected strategy
- Complexity class
- Total number of generated Push_swap operations
- Individual count of all 11 operations

---

# Complexity Summary

| Strategy | Approach | Operation-growth class |
|---|---|---|
| Simple | Repeated minimum extraction | `O(n²)` |
| Medium | Chunk-based sorting | `O(n√n)` |
| Complex | Binary Radix Sort | `O(n log n)` |
| Adaptive | Disorder-based selection | Depends on selected strategy |

The complexity classes describe asymptotic growth in terms of generated
Push_swap operations.

They do not represent an exact number of operations for every input.

---

# Testing

## Norminette

The source files and header can be checked using:

```sh
norminette *.c push_swap.h
```

The current version passes the Norminette checks for the submitted source
files.

## Checker

The generated instructions can be validated using the provided checker.

Example:

```sh
ARG="8 3 6 1 7 2 5 4"
./push_swap --complex $ARG | ./checker_linux $ARG
```

Expected result:

```text
OK
```

## Random Checker Tests

For example:

```sh
for i in {1..10}; do
	ARG=$(shuf -i 1-1000 -n 100)
	./push_swap --complex $ARG | ./checker_linux $ARG
done
```
ARG=$(shuf -i 1-10000 -n 100)
	./push_swap --bench --complex $ARG | ./checker_linux $ARG
Every valid execution should return:

```text
OK
```

## Operation Count

The Complex strategy was tested with random unique integers.

For 100 integers:

```sh
ARG=$(shuf -i 1-10000 -n 100)
./push_swap --complex $ARG | wc -l
```

Observed result:

```text
1084
```

For 500 integers:

```sh
ARG=$(shuf -i 1-10000 -n 500)
./push_swap --complex $ARG | wc -l
```

Observed result:

```text
6784
```

Because Binary Radix operates on normalized indexes, the operation count for
a given input size is determined primarily by the number of indexes and bits
required rather than by the original integer values.

## Complexity Benchmark

The Complex strategy can be tested across increasing input sizes with:

```sh
for N in 50 100 200 400 500 800; do
	ARG=$(shuf -i 1-100000 -n $N)
	echo "===== N=$N ====="
	./push_swap --bench --complex $ARG > /dev/null
done
```

Observed results:

```text
N=50  → 467 operations
N=100 → 1084 operations
N=200 → 2468 operations
N=400 → 5536 operations
N=500 → 6784 operations
N=800 → 12272 operations
```

The measured growth is consistent with the expected `O(n log n)` behavior of
Binary Radix Sort.

## Benchmark and Checker

Because benchmark information is sent to `stderr`, benchmark mode remains
compatible with the checker:

```sh
ARG=$(shuf -i 1-1000 -n 100)
./push_swap --bench --adaptive $ARG | ./checker_linux $ARG
```

Benchmark information remains visible in the terminal while only Push_swap
operations are piped to the checker.

---

# Memory Testing

Valgrind can be used to verify memory management:

```sh
ARG=$(shuf -i 1-1000 -n 100)

valgrind --leak-check=full --show-leak-kinds=all \
	./push_swap --bench --adaptive $ARG > /dev/null
```

A successful execution should report no memory leaks or memory errors:

```text
in use at exit: 0 bytes in 0 blocks
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

---

# Error Handling

Invalid input prints:

```text
Error
```

to `stderr`.

Examples of invalid input include:

```sh
./push_swap 1 2 2
./push_swap 1 abc 3
./push_swap 2147483648
./push_swap -2147483649
```

The program validates cases including:

- Non-integer arguments
- Duplicate values
- Integer overflow
- Integer underflow
- Invalid argument sequences

---

# Project Structure

```text
├── main.c
├── push_swap.h
├── core
│   ├── flag_parser.c
│   ├── logic.c
│   └── printer.c
├── stack
│   ├── stack_creation.c
│   └── stack_utils.c
├── operations
│   ├── push.c
│   ├── swap.c
│   ├── rotate.c
│   └── reverse_rotate.c
├── algorithms
│   ├── small.c
│   ├── simple.c
│   ├── medium.c
│   └── complex.c
└── configurations
    ├── config.c
    ├── benchmark_print.c
    └── benchmark_strategy.c
```

## Main and Core Logic

- `main.c` — program entry point, configuration and benchmark initialization
- `logic.c` — strategy selection and Adaptive logic
- `flag_parser.c` — strategy flag parsing
- `printer.c` — output utilities
- `push_swap.h` — structures, enums and function prototypes

## Stack

- `stack_creation.c` — stack initialization, input loading and node creation
- `stack_utils.c` — stack utilities and validation

## Operations

- `operation_print.c` — prints the operation on the standard out
- `operation_push.c` — `pa` and `pb`
- `operation_swap.c` — `sa`, `sb` and `ss`
- `operation_rotate.c` — `ra`, `rb` and `rr`
- `operation_reverse_rotate.c` — `rra`, `rrb` and `rrr`

## Algorithms

- `algorithm_small.c` — specialized sorting for up to five elements
- `algorithm_simple.c` — repeated minimum-extraction strategy
- `algorithm_medium.c` — chunk-based strategy
- `algorithm_complex.c` — Binary Radix Sort

## Configurations

- `config.c` — config initialization (mostly for benchmarks), disorder calculation and counters
- `benchmark_print.c` — benchmark output
- `benchmark_strategy.c` — strategy and complexity reporting

---

# Team Contributions

This project was developed collaboratively by **iscarval** and **ferde-so**.

Both members studied the Push_swap requirements, discussed the project
architecture and algorithmic approaches, reviewed each other's work and
participated in testing and debugging throughout the development process.

Although each member had primary responsibility for different parts of the
implementation, the project decisions were continuously discussed and aligned
between both developers.

## iscarval

Main implementation responsibilities included:

- Development of an initial singly linked stack prototype during the study
  phase
- Implementation of the Simple sorting strategy
- Implementation of the initial Medium/chunk sorting strategy
- Implementation and integration of the Binary Radix Complex strategy
- Implementation of the benchmark system
- Integration of benchmark counters into the Push_swap operations
- Benchmark output and operation reporting
- Algorithm testing and operation-count analysis
- Norminette, checker and memory testing
- Project documentation

## ferde-so

Main implementation responsibilities included:

- Development of the doubly linked stack structure adopted by the final
  project
- Implementation of the project's core infrastructure
- Stack creation and management
- Input parsing and validation
- Implementation of the Push_swap operations
- Development of supporting stack utilities
- Optimization of the Medium/chunk strategy
- Implementation of the Adaptive strategy
- Implementation of the disorder measurement used by the Adaptive strategy
- Integration of disorder-based strategy selection
- Performance and complexity testing of candidate Complex strategies
- Empirical growth analysis used to validate the final Binary Radix strategy
- Testing, debugging and code review

## Collaborative Development

Several important decisions were made collaboratively.

Both members:

- Studied the Push_swap subject and its complexity requirements
- Discussed different stack representations before adopting the doubly linked
  implementation
- Studied and discussed the sorting strategies
- Reviewed the Simple, Medium and Complex approaches
- Discussed and reviewed the Medium strategy and its optimizations
- Discussed the design and behavior of the Adaptive strategy
- Analyzed the complexity requirements of each sorting strategy
- Compared alternative approaches for the Complex strategy
- Used theoretical analysis and empirical benchmarks to decide on the final
  Complex implementation
- Reviewed benchmark results and operation counts
- Debugged integration issues
- Performed project validation and code review
- Discussed and reviewed the final project architecture

The project was developed through continuous collaboration rather than as two
isolated sets of tasks. The responsibilities above indicate who primarily
implemented each component, while the reasoning, review and major project
decisions were shared between both members.

Both members understand and are expected to be able to explain the complete
implementation during the project defense.

---

# Resources

The following resources were used during the development and study of the
project:

## 42 Push_swap Subject

Official project requirements, mandatory operations, complexity classes,
benchmark requirements and evaluation criteria.

## Acelera Push Swap — Complete Guide (Notion)

A study guide used to better understand the Push_swap project, its structure,
sorting strategies and implementation concepts.

https://rodsmade.notion.site/Acelera-Push_swap-083ab844f9b44456a176e4e4c875bc73#02105678d6454d8b9f250fd1b5120575

## Push Swap Game

An interactive tool used to visualize and understand how Push_swap operations
affect stacks before implementing them in C.

https://phemsi-a.itch.io/push-swap

## Additional Resources

- C manual pages
- Valgrind documentation
- Git documentation
- Peer discussions and code review

---

# AI Usage

AI tools were used as learning and development support resources.

AI assistance was used for:

- Comparing sorting strategies and complexity classes
- Understanding Big-O notation and algorithmic complexity
- Studying Push_swap algorithms
- Understanding Binary Radix Sort
- Studying chunk-based sorting
- Explaining stack operations and pointer manipulation
- Debugging compilation and Norminette errors
- Designing benchmark tests
- Reviewing edge cases
- Analyzing operation counts
- Reviewing memory-management tests
- Improving project documentation

AI-generated suggestions were reviewed, tested and discussed during
development rather than being treated as automatically correct.

The project members remain responsible for understanding, validating and
defending the submitted implementation.