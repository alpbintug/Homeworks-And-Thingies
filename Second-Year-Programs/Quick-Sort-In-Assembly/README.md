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
5 < 11, it will go to the left, new array: 6, -3, 5, 11, 8, 18, 1
8 < 11, it will go to the left, new array: 6, -3, 5, 8, 11, 18, 1
18 > 11, it will go to the right, new array: 6, -3, 5, 8, 11, 1, 18
1 < 11, it will go to the left, new array: 6, -3, 5, 8, 1, 11, 18, "11" found it's place in the array, we have to sort left and right side using same steps, I won't be covering it here, It will take too many steps.
```
#### C Code

```
void quicksort(int *number,int first,int last)
{
  int i, j, pivot, temp;
  if(first<last)
  {
    pivot=first;
    i=first;
    j=last;
    while(i<j)
    {
      while(number[i]<=number[pivot]&&i<last)
      i++;
      while(number[j]>number[pivot])
      j--;
      if(i<j)
      {
        temp=number[i];
        number[i]=number[j];
        number[j]=temp;
      }
    }
    temp=number[pivot];
    number[pivot]=number[j];
    number[j]=temp;
    quicksort(number,first,j-1);
    quicksort(number,j+1,last);
  }
}
```
