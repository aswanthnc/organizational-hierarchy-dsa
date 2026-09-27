# Organizational Hierarchy using General Tree

## Assignment Objective

Represent the given company hierarchy using a suitable tree structure,
construct it in C, display it using level-order traversal, and compare
linear search and binary search for department names.

## Organizational Hierarchy

```text
CEO
├── HR
├── Finance
└── IT
    ├── Development
    │   ├── Frontend
    │   └── Backend
    └── Testing
```

## Data Structure

A General Tree is used with First Child-Next Sibling representation.

## Operations

1. Tree construction
2. Level-order traversal
3. Tree height calculation
4. Linear search
5. Binary search
6. Search comparison counting

## Search Data

Linear search uses:

```text
HR, Finance, IT, Development, Testing, Frontend, Backend
```

Binary search uses the sorted list:

```text
Backend, Development, Finance, Frontend, HR, IT, Testing
```

## Sample Search Results

| Department | Linear | Binary |
|------------|-------:|-------:|
| HR | 1 | 2 |
| Development | 4 | 3 |
| Finance | 2 | 3 |
| Backend | 7 | 3 |

## Tree Analysis

- Height: 3 edges
- Number of levels: 4
- Level-order traversal: O(n)
- Level-order auxiliary space: O(n)
- Height calculation: O(n) time and O(h) recursion space

## Search Complexity

| Algorithm | Best | Average | Worst | Extra Space |
|-----------|------|---------|-------|-------------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |

## Tree Construction Complexity

The provided addChild implementation may scan siblings, so worst-case
construction can be O(n^2). Tree storage is O(n).

## Conclusion

The General Tree is suitable for organizational reporting because it
preserves parent-child relationships. For scalable department-name
searching, Binary Search on a sorted array provides logarithmic search
time, while Linear Search remains simple and useful for small or unsorted
datasets.

## Compilation

### GCC

```bash
gcc src/organizational_hierarchy.c -o organizational_hierarchy
./organizational_hierarchy
```

### Windows MinGW

```bash
gcc src/organizational_hierarchy.c -o organizational_hierarchy.exe
organizational_hierarchy.exe
```

## Repository Contents

- `src/` - C source code
- `input/` - input data
- `output/` - executed output
- `trace/` - trace tables
- `analysis/` - complexity and comparison analysis
- `conclusion/` - final conclusion
