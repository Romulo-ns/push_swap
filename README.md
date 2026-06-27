*This project has been created as part of the 42 curriculum by romdo-na and willpere.*

# Push Swap

## Description

Push Swap is an algorithmic project whose objective is to sort a stack of integers using
only a restricted set of stack operations.

The challenge is not only to sort the numbers correctly, but also to minimize the number
of generated operations.

This project explores:

- Algorithm complexity
- Data structures
- Stack manipulation
- Runtime strategy selection
- Performance optimization

The program receives a list of integers, computes the disorder of the input, selects an
appropriate sorting strategy (unless one is explicitly forced), and outputs the sequence
of Push Swap operations required to sort the stack.

---

# Features

- Integer parsing
- Error handling
- Duplicate detection
- Overflow detection
- Four sorting strategies
- Adaptive strategy selection
- Benchmark mode
- Memory leak free
- Norm compliant

---

# Instructions

## Compilation

```bash
make
```

Available rules:

```bash
make
make clean
make fclean
make re
```

---

## Usage

Default (Adaptive):

```bash
./push_swap 5 2 8 1 3
```

Force a strategy:

```bash
./push_swap --simple 5 2 8 1 3

./push_swap --medium 5 2 8 1 3

./push_swap --complex 5 2 8 1 3

./push_swap --adaptive 5 2 8 1 3
```

Benchmark mode:

```bash
./push_swap --bench --adaptive 5 2 8 1 3
```

The benchmark displays (stderr):

- Computed disorder
- Selected strategy
- Complexity class
- Total operations
- Number of each operation

---

# Allowed Operations

```
sa
sb
ss
pa
pb
ra
rb
rr
rra
rrb
rrr
```

---

# Algorithms

The project implements the four mandatory strategies required by the subject.

---

## 1. Simple Strategy (O(n²))

The Simple Strategy is intended for very small or nearly sorted datasets.

Algorithm used:

- Insertion Sort adaptation

Idea:

Elements are inserted into their correct position one by one using Push Swap
operations.

Complexity:

Time:
O(n²)

Space:
O(1)

---

## 2. Medium Strategy (O(n√n))

The Medium Strategy divides the input into √n chunks.

Algorithm used:

- Chunk-based sorting

Idea:

- Divide the ranks into chunks.
- Push one chunk at a time to stack B.
- Reinsert elements in sorted order.

Complexity:

Time:
O(n√n)

Space:
O(n)

---

## 3. Complex Strategy (O(n log n))

This strategy is designed for highly disordered inputs.

Algorithm used:

- Radix Sort adaptation

Idea:

- Compress values into ranks.
- Sort each bit independently.
- Move elements between stacks according to each bit.

Complexity:

Time:
O(n log n)

Space:
O(n)

---

## 4. Adaptive Strategy

The Adaptive Strategy is the default mode.

Before any move, the disorder metric is computed as required by the subject.

The disorder is calculated by counting inversions:

```
disorder =
mistakes /
total_pairs
```

where

- disorder = 0 → already sorted
- disorder = 1 → completely reversed

The strategy selection is:

| Disorder | Strategy |
|----------|----------|
| < 0.20 | Simple |
| 0.20 ≤ d < 0.50 | Medium |
| ≥ 0.50 | Complex |

### Rationale

Low disorder inputs require only a few corrections, making an O(n²) algorithm
competitive due to its very small constant factors.

Medium disorder inputs benefit from chunk partitioning, reducing unnecessary
operations.

Highly disordered inputs are handled by Radix Sort, providing O(n log n)
performance.

This follows the mandatory adaptive requirements described in the subject.

---

# Benchmark

When executed with:

```bash
--bench
```

The following information is printed to stderr:

- Disorder (%)
- Selected strategy
- Complexity class
- Total operations
- Count of every operation

The operation stream remains on stdout.

---

# Error Handling

The program detects:

- Non-integer arguments
- Integer overflow
- Duplicate values
- Invalid flags
- Empty arguments

Errors print:

```
Error
```

to stderr.

---

# Project Structure

```
include/
src/
operations/
algorithms/
utils/
parsing/
Makefile
README.md
```

---

# Contributors

| Login | Contribution |
|--------|--------------|
| romdo-na | Parsing, stack operations, algorithms, benchmark |
| <partner-login> | Validation, checker, optimization, testing |

---

# Resources

## Documentation

- The C Programming Language – Kernighan & Ritchie
- Introduction to Algorithms – Cormen, Leiserson, Rivest & Stein
- https://en.cppreference.com
- https://man7.org/linux/man-pages/

## Push Swap References

- 42 Subject
- Big-O Cheat Sheet
- Radix Sort
- Insertion Sort
- Chunk Sorting

## AI Usage

Artificial Intelligence was used only as a learning assistant.

It was used for:

- Understanding algorithm complexity
- Discussing optimization ideas
- Explaining data structures
- Reviewing documentation
- Improving README formatting

All implementation decisions, code, debugging and testing were performed and
validated manually by the project contributors.

---

# License

This project is part of the 42 curriculum and is intended for educational purposes only.