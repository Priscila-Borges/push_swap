*This project has been created as part of the 42 curriculum by bandrade, pride-ol.*

## DESCRIPTION

Push_swap is an algorithmic project at 42 that challenges students to sort a data set on a stack (Stack A) using an auxiliary stack (Stack B) and a restricted set of operations. The primary goal is to calculate and display the shortest possible sequence of instructions to sort the numbers, optimizing performance for various input sizes.
This implementation includes an integrated benchmark system that analyzes the initial "disorder" of the data and measures the efficiency of different strategies in real-time, outputting detailed metrics to the standard error.

## INSTRUCTIONS

### Compilation

make

---
### Usage

./push_swap [flags] <numbers>

Examples:

./push_swap 3 2 1

./push_swap "3 2 1"

./push_swap --simple 5 4 3 2 1

./push_swap --bench 4 67 3 87 23

---

### Error Handling

The program prints:

Error

To stderr in the following cases:

* invalid arguments (non-integers)
* duplicate values
* integer overflow or underflow
* invalid flags
* flags placed after numbers

## ALGORITHMS

The project employs an Adaptive Approach, selecting the most efficient algorithm based on stack size and the calculated initial disorder percentage:

- Small Sort (2, 3, and 5 elements):

Optimized manual logic to ensure the absolute minimum number of moves for tiny stacks.

- Simple Sort: 

Used for small lists or those with very low disorder ($d < 20\%$), focusing on simplicity and stability.

- Chunk Sort:

The core algorithm for medium-to-large sets (e.g., 100 elements). It partitions the stack into "chunks" based on index ranges to minimize the rotation distance for each element.

- Radix Sort:

A bitwise sorting implementation used for massive data sets (500+ elements) to maintain a consistent $O(n \log n)$ complexity.

The sort_handler function calculates the initial_disorder of the stack before execution to decide which strategy to launch.

## TECHNICAL CHOICES JUSTIFICATION

The adaptive strategy was chosen to balance performance across all evaluation scenarios.

* Radix sort performs consistently well on large datasets (500 elements)
* Chunk sort often yields fewer operations on medium datasets (100 elements)
* Simple sort avoids unnecessary overhead on nearly sorted inputs

By analyzing the initial disorder, the program avoids overusing complex algorithms when they are not needed, significantly reducing the total number of operations.

## OPERATIONS

The program uses the following operations:

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

## BENCHMARK MODE

When using `--bench`, the program outputs performance metrics to stderr:

```bash id="y08z5z"
[bench] dis: XX.XX%
[bench] strategy: ...
[bench] total_ops: ...
[bench] sa: ... sb: ... ss: ... pa: ... pb: ...
[bench] ra: ... rb: ... rr: ... rra: ... rrb: ... rrr: ...
```

This mode helps evaluate algorithm efficiency and compare strategies.

## TESTING

### Checker

```bash id="x4t1xy"
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
```
Expected:
OK

### Performance

```bash id="yx4b7k"
./push_swap $ARG | wc -l
```

## RESOURCES

Online platforms such as GeeksforGeeks and Stack Overflow, as well as various articles related algorithmic complexity, sorting strategies and doubly linked list.


## AI USAGE

AI tools were used to:

* understand algorithm complexity
* generate test scenarios
* write this README