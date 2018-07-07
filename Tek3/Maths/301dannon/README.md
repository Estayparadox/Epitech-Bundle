# 301dannon
## What's that ?
This is a benchmark of different sorting algorithms that compare their execution speed, or rather the number of effectuated operations (in order to be independent of the machine and its power).
## Algorithm
### Selection Sort
The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element, and moving the sublist boundaries one element to the right.</br>
![image1](http://codingconnect.net/wp-content/uploads/2016/09/Selection-Sort.gif)
### Insertion Sort
Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.</br>
![image2](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
### Bubble Sort
Bubble sort is a simple sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.</br>
![image3](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)
### Fusion Sort
Fusion sort works as follows:
First, it divides the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted) and repeatedly merges sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.</br>
![image4](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)
### Quick Sort
Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays.</br>
![image5](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif)
## How to use it ?
```
./301dannon -h 
USAGE
           ./301dannon file
DESCRIPTION
           file file that contains the numbers to be sorted, seperated by spaces
```
### Example
```
>>> cat list
3.3 5 9.89 -6
>>> ./301dannon list
4 elements
select sort: 6 comparisons
insertion sort: 4 comparisons
bubble sort: 6 comparisons
fusion sort: 5 comparisons
quicksort: 4 comparisons
```
