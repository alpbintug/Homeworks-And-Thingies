## Quick Sort In Assembly (80x86) Programming language

In this homework, we were asked to get a array of integers from user and sort it using Quick Sort algorithm

#### Algorithm

Quicksort is a "Divide and Conquer" algorithm, like Merge Sort.  It also is an recursive algorithm. You select a "Pivot" in your array (This can be a random value), after that you group lesser values to the one part, and higher values to the other, when your process is done, your pivot will find it's place in the array, after this you will have two sub-arrays, and you will call "Quicksort" for both parts, when there is only one element in a sub-array, this means you are done and that part of the array is sorted.

#### Example

Let's sort given array; `6, 11, -3, 5, 8, 18, 1`
```
Select a pivot: 11
6 < 11, it will stay on the left
11 = 11, no changes
-3 < 11, it will go to the left, new array: 6, -3, 11, 5, 8, 18, 1
