<div align = "center">
<h1>DSA-Personal-Notes</h1>
<span>This repository will contain all practice codes, simple codes, and notes</span>
</div>

### Confirmed Information:

# Pre-midterm Topics:
- ADT List
- ADT Stack
- ADT Queue

## Mentioned types of Data Structure Implementation 
- Array
- Linked List
- Cursor-based
  - it is like linked list but array implementation and where requesting memory aswell as freeing memory is a function to call.

### ADT List
- a data structure that represents an ordered collection of elements.
- Known List operations include: insert,delete,member,traverse, and etc.
- Implementations:
	1. **Array Implementation(4 versions)**
		- **Version 1**: List is a structure containing an array and variable count, where count represents the actual number of elements in the array
		- **Version 2**: List is a pointer to a structure that contains an array and the variable count
		- **Version 3**: List is a structure containing a pointer variable that points to the beginning address of a dynamic array, and variable count.
		- **Version 4**: List is a pointer to a structure that contains a pointer variable that points to the beginning address of a dynamic array, and variable count.
		- **NOTE**: in representing the total number of elements in ADT List it could be:
			- **Count**: which represent the total number of elements.
			- **Last Index**: which represents that index of the last inserted element in a List.
	2. **Linked List Implementation**
		- Singly Linked List (**focus**)
	3. **Cursor-based Implementation**

### ADT Stack 
- A linear data structure that follows the **Last In, First Out** (*LIFO*) principle. This means that the last element to be inserted in a stack is to be removed first.
- Operations: Top/Peek, Push, Pop, IsEmpty, isFull, and initialize
- Implementations
	1. **Array Implementations** (with in mind the 4 possible versions)
	2. **Linked List Implementation**
	3. **Cursor-based Implementation**

### ADT Queue
- A linear data structure that follows the **First In, First Out** (*FIFO*) principle. This means that the first element added to the queue will be the first one to be removed.
- Operations: Enqueue, Dequeue, Front, isEmpty, isFull and initialize
- Implementations
	1.  **Array Implementation:**
		- Circular Array
			- if empty, front is ahead of rear by 1: (rear+1) % SIZE == front
  			- if full, front is ahead of rear by 2: (rear+2) % SIZE == front
	2. **Linked List Implementation:**
		- front and rear interger variables in a user defined structure datatype
		- Doubly linked list

### IMPORTANT
- Stacks and Queue data structures cannot be traversed based from the given definitions
### for just displaying the elements:
- Stacks: in printing the elements, starts from the top(last inserted) element and transfer the elements to another stack
- Queue: in printing the elements, starts from the front(first inserted) element (not sure)

# Midterm Topics:
- ADT Set
- ADT Dictionary

### ADT Set
- A collection of members(or elements), each member of a set either is itself a set or is a primitive element call an atom. **All members of a set are different**
- No set can contain two copies of the same element.

### ADT's based on Set
- ADT UID (**Union, Intersect, Difference**)
- Dictionary (to be studied)
- Priority Queue (to be studied)

### UID Implementations
- **Array** - static or dynamic
- **Linked List**- single or doubly, and also sorted and unsorted
- **Cursor based**
- **Bit-vector** (NEW)
  - Operators:
    - **'&'** and **'|'**


# Other mentions:
- Hashing
- Dictionary
- Bitwise operators

# Pre-Final Topics
1. **ADT Tree and Implementations** [Source: Data Structure by Aho, Hopcroft, and Ullman]
	- Definition of a tree
	- Basic concepts and terms related to tree
	- Tree Traversals **[Preorder, Inorder, Postorder]**
	- ADT Tree Implementations
		- ***Parent Pointer Implemenation***
		- ***List of Children and Implementation***
	- Binary Tree definition and Implementation
	- Expression Trees
	- Huffman Code

2. **Binary Search Tree (BST)** [Sources: There are many sites in the internet such as Geeks for Geeks]
	- Description and Implementation
	- Operations: Insert, Delete, and Member
	- Similarity and Difference between BST ans AVL trees
	- Binary Search vs Sequential Search

3. ADT Priority Queue
	- Partially Ordered Tree (POT)
	- **Min and Max heap**
		- ***MinHeap*** ==> Operations: insert and deleteMin [Source: Source: Data Structure by Aho, Hopcroft, and Ullman]
		- ***MaxHeap*** ==> Operations: insert and deleteMax [Sources: Internet]
	- **MinHeapify and MaxHeapify**
		- ***Version 1***: Insert all elements in an initially empty Pot [Source: ebook]
		- ***Version 2***: Heapify starting with lowest level parent [Sources: Internet]

4. **Heapsort Sorting Technique** (in place)
	- A sorting algorith is an "in place" sorting algorithm if there is no additional array is used when implementing the sorting process.

# Final Topics
1. **Directed and Undirected Graph** [Source: Data Structure by Aho, Hopcroft, and Ullman]
	- Concepts
	- Graph Implementations:
		- ***Adjacency Matrix*** and 
		- ***Adjacency List***
2. **Graph Algorithms** [Data Structure by Aho, Hopcroft, and Ullman]
	- **Shortest Paths**: *Dijkstra's*, *Floyd's*, and *Warshall's* Algorithms
	- **Traversal**: *Depth First Search (DFS)* and *Breadth First Search (BFS)*
	- **Minimun Cost Spanning Tree**: *Prim's* and *Kruskal's Algorithms*
---

&copy; 2024 Paul France M. Detablan. All rights reserved.
