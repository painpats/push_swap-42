# push_swap-42

`push_swap` requires sorting data in a stack, using a limited set of instructions with as few operations as possible.

## Features

- Sorting of integer arrays.
- Operations on two stacks: `push`, `swap`, and `rotate`.
- Optimization of the number of operations to ensure high performance.
- Error handling for robust program execution.

## Algorithm

The program uses an optimized insertion sort algorithm with a multi-step approach to minimize the number of operations. The main operations are:

- `sa`: Swap the first two elements of stack A.
- `sb`: Swap the first two elements of stack B.
- `pa`: Push the top element of stack B onto stack A.
- `pb`: Push the top element of stack A onto stack B.
- `ra`: Rotate stack A (shift up).
- `rb`: Rotate stack B.
- `rra`: Reverse rotate stack A.
- `rrb`: Reverse rotate stack B.

## Installation

To use `push_swap`, simply clone the repository and compile it:
   ```bash
   git clone https://github.com/your-username/push_swap.git
   cd push_swap-42
   make
   ```

## Usage

```bash
./push_swap [numbers to sort]
```
The program will display the series of instructions needed to sort the numbers.
