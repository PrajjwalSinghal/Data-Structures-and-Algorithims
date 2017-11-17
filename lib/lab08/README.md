# Lab 08: Sorting #
Sorting is an important part of computer science and data structures. For most programs you write, you will assume that your data is sorted, but in reality, you data is almost never entered into a system in a sorted manner. We will need to sort our data structures to be able to use them with other programs easier. 

### Lab Instructions ###
For this lab you will be implementing various sorting algorithms to work with your Lab 6 doubly linked list. If that lab isn't working, you need to get it working in order to work on this lab. 

The following sorting algorithms need to be implemented in the `sorts.cpp` file:
* insertion sort
* selection sort
* bubble sort
* cocktail sort
* merge sort
* quick sort
* radix sort

Each of these sorting algorithms will take in a `lab6::doubly_linked_list` and an `int` and will return a `lab6::doubly_linked_list`. The sorting algorithm needs to make a **copy** of the input doubly linked list, and **only** make changes to the copied list. 

The integer input is the number of iterations, or passes the sort algorithm will run on the list before returning the copied linked list. In the real world, you would not hav an integer input for these sorting algorithm, but we need to test if your algorithm is functioning properly.The only way to do that is to stop it at certain places and look at the output data.


### Hints ###
* Use Wikipedia for each of the sorting algorithms. There are sudo code implementations of each of the sorts available.