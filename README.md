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