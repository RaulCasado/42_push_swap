# Push Swap

## Overview

![Algorithm Visualization](./push_swap.gif)

**Push Swap** is a project aimed at creating an efficient sorting algorithm using two stacks (`a` and `b`). This challenge is part of the 42 programming school,that sorts integers with minimal operations using a predefined set of "moves".

## Features

- **LIS-Based Approach**: Uses Longest Increasing Subsequence (LIS) to identify the elements to keep in `stack a`, pushing the rest to `stack b`.
- **Cost-Based Strategy**: Implements an efficient cost calculation to determine the optimal order to push elements from `stack b` back into `stack a`.

## Rules and Operations

Sorting is achieved by manipulating two stacks, `a` and `b`, using the following operations:

- `sa` : Swap the first two elements of `a`.
- `sb` : Swap the first two elements of `b`.
- `ss` : Perform `sa` and `sb` simultaneously.
- `pa` : Push the top element of `b` onto `a`.
- `pb` : Push the top element of `a` onto `b`.
- `ra` : Rotate `a` upwards.
- `rb` : Rotate `b` upwards.
- `rr` : Perform `ra` and `rb` simultaneously.
- `rra` : Reverse rotate `a`.
- `rrb` : Reverse rotate `b`.
- `rrr` : Perform `rra` and `rrb` simultaneously.

The goal is to sort all integers in ascending order in `stack a`, leaving `stack b` empty.

## Algorithm

This implementation employs a custom approach combining the LIS with cost-efficient moves:

1. **Extract the LIS**: 
   - Identify the Longest Increasing Subsequence (LIS) in `stack a`. These elements are already in a relatively correct order and will remain in `stack a`.
   - Push all other elements from `stack a` to `stack b`.

2. **Reintegrate Elements from `stack b`**:
   - For each element in `stack b`, calculate the cost to insert it into its correct position in `stack a`.
   - Costs are based on the number of rotations (`ra`, `rb`, `rra`, `rrb`) required for placement.
   - Push the element with the lowest cost first.

3. **Handle Remaining Elements**:
   - After all elements from `stack b` are pushed back to `stack a`, ensure `stack a` is rotated so the smallest element is at the top.

## Performance Goals

The project evaluates sorting efficiency as follows:
- **100 integers**: ≤ 700 operations.
- **500 integers**: ≤ 5,500 operations.



## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/RaulCasado/42_push_swap.git
   cd 42_push_swap
   ```
2. Compile the project:
   ```bash
   make
   ```

## Usage

Run the program with a list of integers to sort:
```bash
./push_swap 4 67 3 87 23
```

You can also use the Python script to generate random numbers meeting the requirements:
```bash
python3 number_generator.py n
```
Where `n` is the number of integers to generate.

### Checker

A bonus program, `checker`, can verify the correctness of the generated instruction sequence:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Acknowledgments

Gratitude to the 42 community and peers for their support and feedback. The LIS-based approach and cost strategy were designed to simplify and optimize the sorting process, ensuring high performance while adhering to project constraints.

## Useful Links

- [Visualizer](https://codepen.io/ahkoh/full/bGWxmVz): A visualizer for the Push Swap algorithm.

- [LIST-Based Approach](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/): GeeksforGeeks article on the Longest Increasing Subsequence (LIS) problem.

- [Turkce Push Swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97): Turkish tutorial on the Push Swap project.

- [Time Complexity](https://www.geeksforgeeks.org/understanding-time-complexity-simple-examples/): Big-O Cheat Sheet for time complexity analysis.

- [Cost Calculation](https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/): GeeksforGeeks article on the minimum number of swaps required to sort an array.