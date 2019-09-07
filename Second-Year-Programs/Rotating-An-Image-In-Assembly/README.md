## Rotating an image in Assembly (80x86) programming language

In this homework, we are asked to write two functions who will turn an image to the left or to the right. Program is given to us and we are asked to write those two functions using inline assembly in Visual Studio.

The image is in Black and White format and the length of the both edges are same. So we are using N x N matrix to store our image.

Rotate-Left.asm and Rotate-Right.asm files are also in main.cpp, I posted them separately to reading clearity.

### Algorithm

In order to rotate a matrix to left or right, we have to find the transpose of the matrix.

#### Transpose of a matrix;

```
[1, 4, 5]       [1, 3, 2]
[3, 1, 8]  ==>  [4, 1, 7]
[2, 7, 9]       [5, 8, 9]
```

What happened here is; Rows and Columns changed. 1st Column became the 1st raw etc.

Both rotating to right or left functions require Transpose.


We can rotate a matrix to the left or right, but there is a little problem, arrays in assembly language is one dimensional, so we cannot use a matrix (Atleast, directly), so what we need to do is, turning a matrix into an array, this process is simple.

An matrix with NxN size would look like this;

```
[1, 2, 3, ..., n]
[n+1, n+2, ..., 2n]
.
.
.
[n^2-n+1, n^2-n, ..., n^2]
```

We can transform this matrix into an one dimensional array;

```
[1, 2, 3, ..., n^2]
```

When we convert our matrix into a one dimensional array we see a pattern like this;

```
[1][1], [1][2], [1][3], ..., [1][n]                     [1], [2], [3], ..., [n]
            .                                                     .
            .                               ===>                  .
            .                                                     .
[n][1], [n][2], [n][3], ..., [n][n]                     [n^2-n+1], [n^2-n+2],...,[n^2]

```

The translation here is;
```
array[(raw index) * (number of columns) + (column index)] = matrix[raw index][column index]
```
Pseudo code;

```
for(i=0;i<n;i++)
{
  for(j=i;j<n;j++)
  {
    tmp=a[i*n+j]
    a[i*n+j]=a[j*n+i]
    a[j*n+i]=tmp
  }
}
```
#### Rotating Right
After we get the transpose of the matrix, we have to turn it left, what we need to achieve is;

```
[1, 4, 5]       [2, 3, 1]
[3, 1, 8]  ==>  [7, 1, 4]
[2, 7, 9]       [9, 8, 5]
```

Turning a matrix without finding the transpose of that matrix seems too hard, finding the index change is harder. Let's see what will it look like when we get the transpose

```
Original        Transpose         Rotated to Left
[1, 4, 5]       [1, 3, 2]         [2, 3, 1]
[3, 1, 8]  ==>  [4, 1, 7]   ==>   [7, 1, 4]
[2, 7, 9]       [5, 8, 9]         [9, 8, 5]
```
It looks fairly easy now. Nth item in every single row changed the indexes with the first item. (N-1)th item changed with 2nd, etc.


Pseudo Code (after Transpose);

```
for(i=0;i<n;i++) 
{
  for(j=0;j<n/2;j++)
  {
    tmp=a[i*n+j]
    a[i*n+j]=a[(i+1)*n-j-1]
    a[(i+1)*n-j-1]=tmp
  }
}
```

#### Rotating Left

Rotating left is nearly the same with rotating right, what we need to achieve is;

```
[1, 4, 5]       [5, 8, 9]
[3, 1, 8]  ==>  [4, 1, 7]
[2, 7, 9]       [1, 3, 2]
```

Again, it looks complex without transpose, lets see what we really need to do;

```
Original        Transpose       Rotated to left
[1, 4, 5]       [1, 3, 2]       [5, 8, 9]
[3, 1, 8]  ==>  [4, 1, 7]  ==>  [4, 1, 7] 
[2, 7, 9]       [5, 8, 9]       [1, 3, 2]
```

Similar to rotating right, now Nth item in every column exchanged indexes with 1st item in that column.

Pseudo code (After transpose);

```
for(i=0;i<n/2;i++)
{
  for(j=0;j<n;j++)
  {
    tmp=a[i*n+j]
    a[i*n+j]=a[n*(n-i-1)+j]
    a[n*(n-i-1)+j]=tmp
  }
}
```




