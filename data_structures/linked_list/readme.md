# Linked List

A linked list is a linear data structure that stores elements in nodes. Each node contains:
1. Value: the data stored
2. Pointer: a reference to the next node

## Types of Linked Lists

### 1. Singly Linked List
- Each node points to the next node
- Can be traversed in only one direction
```
[10] -> [20] -> [30] -> nullptr
```

### 2. Doubly Linked List
- Each node points to both the next and the previous node
- Can be traversed in both directions
```
nullptr <- [10] <-> [20] <-> [30] -> nullptr
```

### 3. Circular Linked List
- The last node points back to the first node
- Can be singly or doubly linked
```
[10] -> [20] -> [30]
   ^             |
   |-------------|
```

## Linked list vs Array

### Advantages
- Dynamic size
- Efficient insertion and removal at the beginning or middle

### Desavanages
- Random access is slow (O(n))
- Uses more memory