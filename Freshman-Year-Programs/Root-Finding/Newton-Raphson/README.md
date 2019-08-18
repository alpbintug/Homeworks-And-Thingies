In this method, we use Newton-Raphson method to find the root of given function.

This method is an iterative method which will repeat itself until reaching the desired error levels, because of iteration, it is hard to find the exact value of the root so we find an approximate value, for this we need an error level.

Basic operation will look like this;

x(n+1) = x(n) - f(x(n))/f'(x(n))
We use this operation to find next value. We repeat this until we reach reasonable levels of error.

By error we mean difference between x(n+1) and x(n). If those two results are close enough to eachother, we can say that we found the root.

So loop this operation will look like this

while(|x(n+1)-x(n)| > ε)
  x(n) = x(n+1)
  x(n+1) = x(n) - f(x(n))/f'(x(n))

Where ε is desired error level and f'(x(n)) is first derivative of the given function.


For more information about Newton-Raphson method check;
http://www.wikizero.biz/index.php?q=aHR0cHM6Ly9lbi53aWtpcGVkaWEub3JnL3dpa2kvTmV3dG9uJ3NfbWV0aG9k
http://www.sosmath.com/calculus/diff/der07/der07.html
