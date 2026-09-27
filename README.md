# Organizational Hierarchy using General Tree

## Data Structures and Algorithms Assignment

This project implements an organizational hierarchy using a **General Tree** and performs **Level-Order Traversal**. It also compares **Linear Search** and **Binary Search** for searching department names.

The complete implementation is written in **C**.

---

## 1. Problem Statement

A company has the following organizational hierarchy:

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

The objectives of this assignment are:

1. Represent the organizational hierarchy using a suitable tree.
2. Implement the tree in C.
3. Perform Level-Order Traversal.
4. Determine the height of the tree.
5. Implement Linear Search for department names.
6. Implement Binary Search for department names.
7. Record important intermediate steps using trace tables.
8. Compare the performance of both searching algorithms.
9. Determine time and space complexity.
10. Justify the suitable approach based on execution results and complexity analysis.

---

## 2. Data Structure Used

A **General Tree** is used because a node can have more than two children.

For example:

```text
CEO
├── HR
├── Finance
└── IT
```

The tree is implemented using the **First Child-Next Sibling** representation.

```c
struct Node {
    char name[30];
    struct Node *firstChild;
    struct Node *nextSibling;
};
```

### Node Components

- `name` — stores the department or position name.
- `firstChild` — points to the first child.
- `nextSibling` — points to the next child of the same parent.

---

## 3. Technologies Used

- **Language:** C
- **Data Structure:** General Tree
- **Tree Representation:** First Child-Next Sibling
- **Traversal:** Level-Order Traversal
- **Searching:** Linear Search and Binary Search
- **Compiler:** GCC / MinGW
- **Platform:** GitHub

---

## 4. Organizational Hierarchy

The hierarchy is:

```text
                         CEO
                      /   |   \
                    HR  Finance  IT
                              /      \
                       Development   Testing
                       /          \
                  Frontend       Backend
```

Or:

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

---

## 5. Program Operations

The C program performs the following operations:

### Tree Construction

Creates all nodes and establishes the parent-child relationships.

### Level-Order Traversal

Traverses the tree level by level using a queue.

### Tree Height

Calculates the height of the organizational hierarchy.

### Linear Search

Searches department names sequentially in an unsorted array.

### Binary Search

Searches department names using a sorted array.

### Comparison Counting

Counts the number of comparisons required for each search.

---

## 6. Level-Order Traversal

The tree is processed level by level.

### Level 0

```text
CEO
```

### Level 1

```text
HR  Finance  IT
```

### Level 2

```text
Development  Testing
```

### Level 3

```text
Frontend  Backend
```

### Final Traversal

```text
CEO → HR → Finance → IT → Development → Testing → Frontend → Backend
```

---

## 7. Tree Height

The longest path from the root to a leaf is:

```text
CEO
 ↓
IT
 ↓
Development
 ↓
Frontend
```

Therefore:

```text
Tree Height = 3 edges
Number of Levels = 4
```

---

## 8. Searching

The following department list is used for Linear Search:

```text
HR
Finance
IT
Development
Testing
Frontend
Backend
```

For Binary Search, the data is sorted:

```text
Backend
Development
Finance
Frontend
HR
IT
Testing
```

### Search Test Cases

The following departments are searched:

```text
HR
Development
Finance
Backend
```

---

## 9. Search Comparison

| Department | Linear Search | Binary Search |
|------------|--------------:|--------------:|
| HR | 1 | 2 |
| Development | 4 | 3 |
| Finance | 2 | 3 |
| Backend | 7 | 3 |

### Observation

Linear Search checks elements one by one, so the number of comparisons depends on the position of the required element.

Binary Search repeatedly divides the search range into smaller parts, making it more efficient for larger sorted datasets.

---

## 10. Trace Table

The Level-Order Traversal trace is:

| Step | Deleted Node | Children Added | Queue After Step | Output |
|------|--------------|----------------|------------------|--------|
| 1 | CEO | HR, Finance, IT | HR, Finance, IT | CEO |
| 2 | HR | None | Finance, IT | HR |
| 3 | Finance | None | IT | Finance |
| 4 | IT | Development, Testing | Development, Testing | IT |
| 5 | Development | Frontend, Backend | Testing, Frontend, Backend | Development |
| 6 | Testing | None | Frontend, Backend | Testing |
| 7 | Frontend | None | Backend | Frontend |
| 8 | Backend | None | Empty | Backend |

Detailed search traces are available in `trace_table.txt`.

---

# 11. Complexity Analysis

## Level-Order Traversal

Every node is visited once.

**Time Complexity:**

```text
O(n)
```

**Space Complexity:**

```text
O(n)
```

because a queue is used.

---

## Tree Height

Every node can be visited while calculating the height.

**Time Complexity:**

```text
O(n)
```

**Space Complexity:**

```text
O(h)
```

where `h` is the height of the tree.

---

## Linear Search

### Best Case

```text
O(1)
```

### Average Case

```text
O(n)
```

### Worst Case

```text
O(n)
```

### Space Complexity

```text
O(1)
```

---

## Binary Search

Binary Search requires sorted data.

### Best Case

```text
O(1)
```

### Average Case

```text
O(log n)
```

### Worst Case

```text
O(log n)
```

### Space Complexity

```text
O(1)
```

because the implementation is iterative.

---

# 12. Complexity Comparison

| Operation | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Level-Order Traversal | O(n) | O(n) | O(n) | O(n) |
| Tree Height | O(n) | O(n) | O(n) | O(h) |

---

# 13. Tree Construction Complexity

The `addChild()` function may traverse existing sibling nodes while adding a new child.

Therefore, the worst-case construction complexity can be:

```text
O(n²)
```

The space required to store the tree is:

```text
O(n)
```

---

# 14. Linear Search vs Binary Search

## Linear Search

### Advantages

- Simple to implement.
- Does not require sorted data.
- Suitable for small datasets.
- Easy to use when data changes frequently.

### Disadvantages

- May need to check every element.
- Worst-case complexity is O(n).
- Becomes slower as the dataset grows.

---

## Binary Search

### Advantages

- Faster for large sorted datasets.
- Worst-case complexity is O(log n).
- Reduces the search range by approximately half at each step.

### Disadvantages

- Requires sorted data.
- Maintaining sorted data may require additional processing.
- Less convenient when data changes frequently.

---

# 15. Execution Result

```text
ORGANIZATIONAL HIERARCHY
=========================

Level Order Traversal:
CEO HR Finance IT Development Testing Frontend Backend

Tree Height = 3 edges
Number of Levels = 4

SEARCH COMPARISON
=================
Department      Linear          Binary
---------------------------------------------
HR              1               2
Development     4               3
Finance         2               3
Backend         7               3
```

---

# 16. Result Analysis

From the execution:

- `HR` is found quickly using Linear Search because it is the first element.
- `Backend` requires more comparisons using Linear Search because it is at the end of the unsorted list.
- Binary Search requires fewer comparisons for several of the tested departments.
- The exact number of comparisons depends on the position of the target in the sorted array.

For a small dataset, the difference may not be significant. As the dataset becomes larger, the `O(log n)` complexity of Binary Search makes it more scalable when the data is sorted.

---

# 17. Suitable Approach

The organizational hierarchy is best represented using a:

```text
General Tree
```

because it naturally represents parent-child relationships.

For department-name searching, a:

```text
Sorted Array + Binary Search
```

is suitable when the department list is relatively stable and efficient searching is important.

Linear Search is still useful when the dataset is small, unsorted, or changes frequently.

---

# 18. Final Conclusion

The organizational hierarchy was successfully represented using a **General Tree with First Child-Next Sibling representation**.

Level-Order Traversal was implemented using a queue and successfully displayed the hierarchy level by level:

```text
CEO → HR → Finance → IT → Development → Testing → Frontend → Backend
```

The tree has a height of **3 edges** and **4 levels**.

Linear Search and Binary Search were implemented and compared using multiple department names.

Linear Search has a worst-case time complexity of:

```text
O(n)
```

while Binary Search has a worst-case time complexity of:

```text
O(log n)
```

when the data is sorted.

Therefore, the General Tree is suitable for representing the organizational hierarchy, while Binary Search on a sorted array provides better scalability for department-name searching.

---

# 19. Repository Contents

```text
organizational-hierarchy-dsa/
│
├── organizational_hierarchy.c
├── input.txt
├── output.txt
├── trace_table.txt
├── analysis.md
└── README.md
```

| File | Description |
|------|-------------|
| `organizational_hierarchy.c` | Complete C source code |
| `input.txt` | Input hierarchy and search data |
| `output.txt` | Program execution output |
| `trace_table.txt` | Traversal and search trace tables |
| `analysis.md` | Complexity and comparison analysis |
| `README.md` | Project documentation |

---

# 20. How to Compile and Run

## GCC

Compile:

```bash
gcc organizational_hierarchy.c -o organizational_hierarchy
```

Run on Linux/macOS:

```bash
./organizational_hierarchy
```

Run on Windows:

```bash
organizational_hierarchy.exe
```

---

# 21. Repository Information

**Repository Name:**

```text
organizational-hierarchy-dsa
```

**Language:**

```text
C
```

**Subject:**

```text
Data Structures and Algorithms
```

---

## Author

**Aswanth NC**

Data Structures and Algorithms Assignment

---

## Topics Covered

- General Tree
- First Child-Next Sibling Representation
- Tree Construction
- Level-Order Traversal
- Queue
- Tree Height
- Linear Search
- Binary Search
- Time Complexity
- Space Complexity
- Algorithm Comparison
- Performance Analysis
