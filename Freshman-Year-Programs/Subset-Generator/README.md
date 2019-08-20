# Subset Generator

This was a homework from my Numerical Analysis class in second semester.

Our goal was to create all the subsets of a given set using C.

After working on this programs for several hours I found out how things works and the algorithm I used to solve this problem was like this (I don't know if this is super-optimised)

If we have 3 elements for example, there will be 8 subsets for this
```
For x,y,z
Subset: {},{x},{y},{z},{x,y},{y,z},{x,z},{x,y,z}
```

If we give our elements weight like x=1, y=2, z=4 which is val(n)=2^(n-1) we can print our subset based on those values, and this will make our job to run this on a computer will ease.
```
For val x=1,y=2,z=4
Subset val: {}=0, {x}=1, {y}=2, {y,x}=3, {z}=4, {z,x}=5, {z,y}= 6, {z,y,x}= 7
```

We use these values to create our code, now you can freely go to the source code and enjoy your "How is this garbage working??" moment.
