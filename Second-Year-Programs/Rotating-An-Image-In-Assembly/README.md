## Rotating an image in Assembly (80x86) programming language

In this homework, we are asked to write two functions who will turn an image to the left or to the right. Program is given to us and we are asked to write those two functions using inline assembly in Visual Studio.

The image is in Black and White format and the length of the both edges are same. So we are using N x N matrix to store our image.

Rotate-Left.asm and Rotate-Right.asm files are also in main.cpp, I posted them separately to reading clearity.

#### Algorithm

In order to rotate a matrix to left or right, we have to find the transpose of the matrix.

Transpose of a matrix;

```
[1, 4, 5]       [1, 3, 2]
[3, 1, 8]  ==>  [4, 1, 7]
[2, 7, 9]       [5, 6, 9]
```

What happened here is; Rows and Columns changed. 1st Column became the 1st raw etc.

Both rotating to right or left functions require Transpose.

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

