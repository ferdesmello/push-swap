"""
Input generators for push_swap benchmarking.

All generators return a permutation of range(n).
"""

import random


# ------------------------------------------------------------
# Basic generators
# ------------------------------------------------------------

def sorted_list(n):
    """Already sorted."""

    return list(range(n))


def reverse_sorted(n):
    """Reverse sorted."""

    return list(range(n - 1, -1, -1))


def random_permutation(n):
    """Completely random permutation."""

    values = list(range(n))
    random.shuffle(values)
    return values


# ------------------------------------------------------------
# Exact inversion generator
# ------------------------------------------------------------

def exact_disorder_permutation(n, disorder):
    """
    Construct a permutation with approximately the requested
    disorder.

    Disorder must be between 0 and 1.

    The construction is deterministic and produces the exact
    requested inversion count (up to integer rounding).
    """

    if n <= 1:
        return [0]

    disorder = max(0.0, min(1.0, disorder))

    max_inv = n * (n - 1) // 2
    target = round(disorder * max_inv)

    values = list(range(n))

    result = []

    remaining = target

    #
    # We process the largest numbers first.
    #
    # If remaining >= k,
    # place k at the beginning.
    #
    # Otherwise,
    # insert it so it contributes exactly
    # "remaining" inversions.
    #

    for value in range(n - 1, -1, -1):

        max_here = len(result)

        contribution = min(remaining, max_here)

        insert_pos = max_here - contribution

        result.insert(insert_pos, value)

        remaining -= contribution

    return result[::-1]