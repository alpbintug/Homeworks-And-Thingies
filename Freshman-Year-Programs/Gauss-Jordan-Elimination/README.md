## Gauss Jordan Elimination

This code uses Gauss-Jordan elimination algorithm to solve given equations.
Gauss-Jordan elimination algorithm is used to solve given equations using Matrix.
Equations may have only one value. Unaccepted equations;
``
x+y=5z+3t
x=4t+3z
``

Accepted equations;
```
x+y-5z=3t
x-4t=3z
x+y+t=z
```
A simple example;
``
x+y=3
x-y=5
``
Created matrix will me like this;
``
[ 1, 1, 3]
[ 1,-1, 5]
``
We seperate this array into two parts; Variables and values
``
[ 1, 1| 3]
[ 1,-1| 5]
``
If we add second raw to the first
``
[ 2, 0| 8]
[ 1,-1| 5]
``
Divide the first raw by two to get the value of x
``
[ 1, 0| 4]
[ 1,-1| 5]
``
Multiply the second raw with -1
``
[ 1, 0| 4]
[-1, 1|-5]
``
Add the first raw to the second
``
[ 1, 0| 4]
[ 0, 1|-1]
``
And now we have the value of the variables
``
x + 0*y = 4, x=4
0*x + y = -1, y=-1
``
If you get results like 1.00#INDO00 this means your equation cannot be solved.
Some examples for unsolveable equations;
``
x1+x2=3
x1+x2=5
``
```
x1-x2=3
x1-2x2=3
x1+0x2=4
```
To understand Gauss-Jordan Elimination please check;
https://www.mathsisfun.com/algebra/matrix-inverse-row-operations-gauss-jordan.html
https://www.convict.lu/Jeunes/Math/Gauss_Jordan_Elimination.htm
