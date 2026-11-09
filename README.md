# Push Swap - 42 Barcelona

Push Swap is an algorithmic sorting project from the 42 Barcelona curriculum. The objective is to sort a set of random integer values in ascending order using two stacks (Stack A and Stack B) and a strictly limited set of stack operations, producing the minimal possible sequence of instructions. The project implements a cost-optimized mechanical Turk sorting algorithm that evaluates rotation costs dynamically to minimize instruction volume. The bonus program (checker) reads instruction sequences from standard input and verifies whether they properly sort the input integers without errors.

# Prerequisites

To compile and execute Push Swap, you will need:

- A C compiler: gcc or clang
- GNU Make
- Standard C library
- POSIX-compliant operating system (Linux or macOS)

# Configuration

1. Clone the repository:
```bash
git clone https://github.com/adrmarqu/push_swap.git
cd push_swap
```

No external dependencies are required. The project includes a bundled copy of Libft.

# Execution

### Compilation

Compile the sorting program:
```bash
make
```

Compile the bonus checker:
```bash
make bonus
```

### Running Push Swap

Run push_swap by providing integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
This prints the exact sequence of stack instructions needed to sort the stack.

### Counting Generated Operations

Pipe the instruction list into wc -l:
```bash
./push_swap 2 1 3 6 5 8 | wc -l
```

### Validating Sorting with Checker (Bonus)

Verify that the generated instructions sort the numbers correctly:
```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```
If properly sorted, the checker prints:
```
OK
```
If the numbers remain unsorted or in the wrong stack, it prints:
```
KO
```

### Testing with 100 and 500 Random Integers

```bash
# 100 random numbers test
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l

# 500 random numbers test
ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l
```

# Project Structure

```
push_swap/
├── Makefile                 # Build orchestration for push_swap and checker
├── en.subject.pdf           # 42 School official project specification
├── include/                 # Header files
│   └── push_swap.h          # Node structures, prototypes, and macros
├── libft/                   # Bundled custom C utility library
└── src/                     # Source files
    ├── main/                # push_swap entrypoint
    ├── bonus/               # checker entrypoint
    ├── check.c              # Input validation, integer overflow, duplicate checks
    ├── sort.c               # Sorting algorithms (2, 3 elements, and large stacks)
    ├── cost.c               # Rotation cost calculation between stacks
    ├── init_a.c             # Target node search and cheapest node selection
    ├── init_b.c             # Stack B node indexing and preparation
    ├── move.c               # Synchronized dual rotations (rr, rrr) and execution
    ├── push.c               # Push operations (pa, pb)
    ├── swap.c               # Swap operations (sa, sb, ss)
    ├── rotate.c             # Shift up operations (ra, rb, rr)
    ├── reverse.c            # Shift down operations (rra, rrb, rrr)
    ├── utils.c              # Linked list utilities, min/max node finders
    └── print.c              # Stack visualization and error reporting
```

# Commands and Makefile Targets

- make or make all: Compiles libft and the push_swap sorting binary
- make bonus: Compiles libft and the checker validation binary
- make clean: Removes compiled object files (.o)
- make fclean: Removes object files and both compiled executables (push_swap, checker, libft.a)
- make re: Rebuilds both programs from scratch

# Allowed Stack Operations

- sa / sb / ss: Swap the first two elements at the top of Stack A, Stack B, or both simultaneously
- pa / pb: Push the top element from one stack onto the top of the other stack
- ra / rb / rr: Shift up all elements of a stack by 1 (the first element becomes the last)
- rra / rrb / rrr: Shift down all elements of a stack by 1 (the last element becomes the first)

# Sorting Algorithm Highlights

- Mechanical Turk Strategy: Dynamically scans every element in Stack A, calculates the cheapest number of joint rotations (rr or rrr) and single rotations (ra, rb, rra, rrb) required to place it into its target position in Stack B, and moves the most economical node.
- Push Back & Final Alignment: Once Stack A is reduced to 3 sorted elements, elements in Stack B are pushed back into their exact position in Stack A, followed by a final rotation to bring the smallest integer to the top.
- Benchmark Performance: Consistently sorts 100 integers in under 600 operations and 500 integers in under 5500 operations, well within the highest evaluation tier of the 42 curriculum.

# Author Details

Author: Adrià Márquez Nebot
Github: https://github.com/adrmarqu
LinkedIn: https://www.linkedin.com/in/adria-marquez
Portfolio: https://adrmarqu.github.io
