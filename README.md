# Push Swap

## 📊 Project Overview

Push Swap is a highly efficient sorting algorithm project that uses two stacks and a limited set of operations to sort integers with the minimum number of moves possible. This implementation showcases my understanding of algorithm complexity, data structures, and optimization techniques.

## 🧮 The Challenge

Given a set of integers and two stacks (A and B), the goal is to sort all numbers in ascending order in stack A using only these operations:

- `sa`: swap the first two elements of stack A
- `sb`: swap the first two elements of stack B
- `ss`: perform `sa` and `sb` simultaneously
- `pa`: push the top element from stack B to stack A
- `pb`: push the top element from stack A to stack B
- `ra`: rotate stack A (first element becomes last)
- `rb`: rotate stack B (first element becomes last)
- `rr`: perform `ra` and `rb` simultaneously
- `rra`: reverse rotate stack A (last element becomes first)
- `rrb`: reverse rotate stack B (last element becomes first)
- `rrr`: perform `rra` and `rrb` simultaneously

The challenge is to complete the sort with the *minimum possible number of operations*.

## 🚀 Implementation Features

- **Algorithm Selection**: Implements multiple sorting strategies based on input size
  - Custom algorithm for small sets (2-5 elements)
  - Optimized radix sort for larger datasets

- **Performance Optimized**:
  - Sorts 100 numbers in under 700 operations
  - Sorts 500 numbers in under 5500 operations

- **Memory Efficient**:
  - Minimizes memory allocations
  - Prevents memory leaks

- **Error Handling**:
  - Validates all inputs
  - Detects duplicates and non-integer values
  - Handles integer overflow scenarios

## 🛠️ Technical Components

### Data Structures

- **Stack Implementation**: Custom stack structure with optimized push/pop operations
- **Operation Management**: Efficient operation sequencing and optimization

### Algorithm Design

- **Chunking Strategy**: Pre-sorts numbers into logical chunks before performing the final sort
- **Operation Calculation**: Determines the most efficient path to move elements between stacks
- **Move Optimization**: Combines and reduces operations where possible (e.g., using `rr` instead of separate `ra` and `rb`)

## 💻 Usage

### Compilation

```bash
# Clone the repository
git clone https://github.com/Melis-Pablo/push_swap.git
cd push_swap

# Compile the program
make

# Compile with checker (bonus)
make bonus
```

### Running the Program

```bash
# Sort a list of integers
./push_swap 4 2 8 5 1

# Check the number of operations
ARG="4 2 8 5 1"; ./push_swap $ARG | wc -l

# Verify sorting (with bonus checker)
ARG="4 2 8 5 1"; ./push_swap $ARG | ./checker $ARG
```

### Examples

```bash
# Small dataset
$> ./push_swap 3 1 2
sa
ra

# Medium dataset (sample output - your actual operations may differ)
$> ./push_swap 15 32 4 8 42 16
pb
ra
pb
ra
...

# Using random numbers
$> ARG=$(shuf -i 1-100 -n 100 | tr "\n" " "); ./push_swap $ARG | wc -l
637
```

## 📈 Performance Analysis

| Dataset Size | Average Operations | Maximum Operations | Time Complexity |
|--------------|-------------------|-------------------|-----------------|
| 3 numbers    | 2-3               | 3                 | O(1)            |
| 5 numbers    | 8-12              | 12                | O(1)            |
| 100 numbers  | ~650              | 700               | O(n log n)      |
| 500 numbers  | ~5300             | 5500              | O(n log n)      |

## 🧠 Algorithm Insights

### Sorting Strategy

My implementation uses different approaches based on the input size:

1. **Small Sets (2-5 elements)**:
   - Hardcoded optimal solutions for maximum efficiency
   - Direct calculation of move sequences

2. **Medium to Large Sets**:
   - Initial analysis phase to identify existing patterns
   - Chunking strategy to pre-sort numbers into segments
   - Optimized placement calculations to minimize operations

3. **Operation Optimization**:
   - Combines individual operations where possible
   - Calculates the most efficient rotation direction (clockwise vs. counter-clockwise)
   - Eliminates redundant operations

## 🔍 Learning Outcomes

Through this project, I developed a deeper understanding of:

- Algorithm complexity analysis and optimization
- Data structure selection for specific problems
- Edge case handling in sorting algorithms
- Operation minimization techniques
- Performance benchmarking and testing methodologies

## 📝 Project Structure

```
push_swap/
├── includes/
│   └── push_swap.h       # Main header file
├── srcs/
│   ├── main.c            # Program entry point
│   ├── operations/       # Stack operation implementations
│   ├── sorting/        # Sorting algorithm implementations
│   └── tools/            # Utility functions
├── Makefile              # Build configuration
└── push_swap.md          # Original project requirements
```

## 📚 Resources

For detailed project requirements, see the [push_swap.md](push_swap.md) file.

---

*This project is part of the 42 School Common Core curriculum.*