"""
Disorder calculation.

This reproduces the same metric used by push_swap.

Disorder = inversions / maximum possible inversions
"""

from typing import List

# ------------------------------------------------------------

def count_inversions(values: List[int]) -> int:
    """
    Counts inversions using the naive O(n²) algorithm.

    This matches the implementation in push_swap.
    """

    inversions = 0

    n = len(values)

    for i in range(n):
        for j in range(i + 1, n):
            if values[i] > values[j]:
                inversions += 1

    return inversions

# ------------------------------------------------------------

def compute_disorder(values: List[int]) -> float:
    """
    Returns disorder between 0 and 1.
    """

    n = len(values)

    if n < 2:
        return 0.0

    maximum = n * (n - 1) / 2
    inversions = count_inversions(values)

    return inversions / maximum