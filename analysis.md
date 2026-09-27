# Complexity Analysis

## Tree Representation
The organizational hierarchy is represented using a General Tree with
First Child-Next Sibling representation.

## Tree Height
Height = 3 edges.
Number of levels = 4.

## Level-Order Traversal
Every node is visited once.

- Time: O(n)
- Auxiliary space: O(n) in the worst case for the queue.

## Tree Height Calculation
Every node can be visited once.

- Time: O(n)
- Auxiliary space: O(h), where h is tree height, because recursion is used.

## Linear Search

- Best case: O(1)
- Average case: O(n)
- Worst case: O(n)
- Extra space: O(1)

## Binary Search

The array must be sorted before searching.

- Best case: O(1)
- Average case: O(log n)
- Worst case: O(log n)
- Extra space: O(1) for the iterative implementation.

## Tree Construction
With the simple addChild implementation, adding a child can scan existing
siblings. Therefore the worst-case construction time can be O(n^2).
The stored tree requires O(n) space.

## Overall Observation
The tree is suitable for representing organizational relationships.
For searching department names, binary search is more scalable when the
department list is maintained in sorted order.


# Comparison Table

| Search Department | Linear Search Comparisons | Binary Search Comparisons |
|-------------------|---------------------------|----------------------------|
| HR                | 1                         | 2                          |
| Development       | 4                         | 3                          |
| Finance           | 2                         | 3                          |
| Backend           | 7                         | 3                          |

## Interpretation

Linear search does not require sorted data and can be useful for small or
frequently changing lists.

Binary search requires sorted data but reduces the search range by roughly
half at every step, giving O(log n) search time.

For this small dataset, individual comparison counts vary by the target's
position. For larger sorted datasets, binary search generally scales much
better.


# Final Conclusion

The organizational hierarchy is best represented using a General Tree
because departments can have multiple children.

The First Child-Next Sibling representation provides a practical linked
representation for a general tree in C.

Level-order traversal successfully displays the organization level by level:

CEO -> HR -> Finance -> IT -> Development -> Testing -> Frontend -> Backend

The tree has a height of 3 edges and 4 levels.

For department searching, linear search works directly on an unsorted
array and has O(n) worst-case time complexity. Binary search requires a
sorted array but has O(log n) worst-case time complexity.

Therefore, the suitable combination is:

- General Tree for organizational reporting.
- Sorted array with Binary Search for scalable department-name searching.

The actual choice between linear and binary search should also consider
whether the department list changes frequently and whether maintaining
sorted data is worthwhile.
