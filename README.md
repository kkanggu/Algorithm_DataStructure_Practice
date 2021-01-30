Algorithm_DataStructure_Practice
================================

Personal study for Algorithm &amp; Data Structure

Book : "뇌를 자극하는 알고리즘"



# Status of Study

Day 1
>Data Structure 'List' end. Single, double, circular.   
>List is good at that lots of add / delete / insert, less detection   
>e.g. At DB, dealing with records viewed sequentially.
>
Day 2
>Implement Double Linked List with C style   
>Basic.h is a collection of basic headers like stdio.h, stdlib.h, etc.
>
Day 3
>Data Structure 'Stack' end.   
>Modify Double Linked List with C style   
>Implement Stack with two version.   
>First version is Stack using Array with C style   
>Second version is Stack using Single Linked List with C style

Day 4
>Data Structure 'Queue' end.   
>Queue is suitable for Queue processing.   
>Circular Queue has good performance, but hard to handle.   
>Linked Queue is easy to implement, but performance is slower than Circular Queue.   
>Implement Queue with two version.   
>First version is Circular Queue with array, C style.   
>Second version is Linked Queue with Single Linked List, C style.   
>For separation, change .cpp to .c file.

Day 5
>Data Structure 'Tree' half end.   
>The contents of the book are over, but it don't handle all of trees.   
>So I expressed 'half end'   
>I already know Binary Tree, but Left Child Right Sibling Tree is first got to know.   
>Implement LCRS Tree and Binary Tree with C style.

Day 6
>Algorithm 'Sort' half end.   
>At book show only 3 sorting algorithms. Bubble, Insertion, Quick.   
>Last cemester, I studied 3 more sorting algorithms. Selection, Merge, Heap.   
>Bubble is worst, and average time of Insertion is better than Bubble.   
>Quick used Divide-and-Conquer, so it's very fast. To avoid worst-case, add one short condition.   
>If data array has 3 more datas, then use the middle value of first 3 datas.   
>Selection has similar performance as Bubble and Insertion.   
>Merge and Heap has similar performance as Quick, and I know that Heap is faster than others.

Day 7
>Algorithm 'Searching' half end.   
>Understand Sequential Search & Binary Search Tree.   
>Understand Red Black Tree, but code at the book is incomprehensible.   
>Finally, I implemented upper two code, but I couldn't implement Red Black Tree.   
>And code at the book didn't work well.

Day 8
>Modify Red Black Tree, half end.   
>I fixed the insert problem by modifying the code.   
>But remove is still unresolved.   
>When removing red node, sometimes min node color for the right child node is BLACK.   
>If that node comes up to removed node, then the count of black nodes root through leaf is not the same.

Day 9
>Finally modified Red Black Tree   
>In conclusion, remove is simple.   
>If I removed the node that have lots of childs, copy the min node value for the right child node.   
>Then it will excute the code as if I removed the copied min node.

Day 10
>Data Structure 'Heap' and 'Priority Queue' end.   
>At the book, these are located at algorithm section. But I think this is some kind of Data Structure.   
>Heap is very useful. Can use this to HeapSort, or Priority Queue, and so on.   
>Implement Heap, and Priority Queue using Heap.

Day 11
>Algorithm 'Hash Table' end.   
>Hash is very useful. At this section, I learn only Hash Table.   
>Also used in search string and encryption. At this book, I'll learn Hash Table and search string. But now, I'll learn Hash Table first.   
>Hash Table is better than Binary Search. In the sophomore Algorithm lecture, I couldn't learn how good Hash Table is and passed it lightly.   
>I implement two Hash Table, chaining and double hashing.

Day 12
>Data Structure 'Graph' end.   
>At the book, these are located at algorithm section. But I think Graph is Data Structure.   
>In the field of theory, I learned Graph, Adjacent List and Array, DFS, BFS, Topological Sorting, Minimum Spanning Tree, and algorithm Prim, Kruskal, Dijkstra.   
>Today I implement only Graph with Adjacent List and Array.

Day 13
>Graph Algorithm half end.   
>I implemented Single Linked List, DisjointSet, and Topological Sort.   
>I'm modifying Prim's Algorithm.   
>I'm not feeling good, the rest will be end tomorrow.

Day 14
>Algorithm 'Prim' end.   
>The code at the book use Priority Queue, but I didn't use it.   
>Because of Graph, I had to use lot memory.   
>To get good performance, I have to modify Graph code.

Day 15
>Algorithm 'Kruskal' and 'Dijkstra' end.   
>I made a wrong approach to Prim's algorithm.   
>If I use Priority Queue, then it's more easy to implement, and it can be easier code.   
>Unlike Prim, Kruskal and Dijkstra is very easy to implement.   
>The code at the book used Priority Queue when implementing Dijkstra.   
>But I think Queue is more suitable, so I used it.

Day 16 & 17
>String search Algorithm end.   
>At this chapter, there are three popular algorithms.   
>I tried to implement all of this, but I couldn't.   
>I unserstanded the principles, but I couldn't make it into code.
>I implemented RabinKarp, but I just copied KMP & Boyer-Moore algorithm.

Day 18
>Chapter 'Analyzing algorithm performance' end.   
>This chapter is about anlyzing algorithm performance.   
>Asymptotic Notation includes O, Ω, θ.   
>And it shows how to analyze recursion algorithm, and Master theorem.   
>I already learned almost everything, and Master theorem is hard to understand that the book says.   
>But the way to analyze recursion algorithm that the book shows is very informative.

Day 19
>Chapter 'Divide and Conquer' end.   
>This chapter is about divide and conquer.   
>There are three codes that this chapter says. Merge sort, Fibonacci, Matrix.   
>To show proper example for divide and conquer, merge sort is appeared at this chapter.   
>In the sophomore Algorithm lecture, Fibonacci problem is solved by dynamic programming.   
>But at this book, this problem is solved by divide and conquer using Matrix.   
>Fibonacci is expressed using Matrix, so it's easy to calculate.   
>Upper algorithms have a time complexity of O(logn).

Day 20
>Chapter 'Dynamic Programming' end.   
>This chapter is about dynamic programming.   
>'Divide and Conquer' is Top-down, get solution from top to go down.   
>'Dynamic Programming' is Bottom-up, get solution from bottom to go up.   
>There are two codes, Fibonacci and LCS algorithm.   
>I already learned this chapter at sophomore Algorithm lecture, but LCS is very useful to me.   
>I understood LCS almost half, and I finally understand LCS with this book.   
>Thanks to the table, it's easy to understand.   
>LCS algorithm with dynamic programming has a time complexity of O(mn).

Day 21
>Chapter 'Greedy Algorithm' end.   
>This chapter is about greedy algorithm.   
>Former algorithm 'Dijkstra' is also greedy algorithm.   
>I learned Huffman algorithm, and it's very useful.