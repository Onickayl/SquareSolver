# The solver of quadratic equations

It's a solver of quadratic equations.
You can enter your own coefficients and get an answer.
``` sh
Enter a: 1
Enter b: -5
Enter c: 4
Answer: x1 = 4, x2 = 1
```
Here _a_ is a coefficient for _x^2_, _b_ is for _x_ and _c_ is a free term.

There's also a test built into this program. It checks if solver is working correctly.
You can run it if you type --test on the command line.

``` bash
nothing --test
```
At the same time, it will be displayed that the test is running

``` sh
Tests are performed
```
If there is an error in the program, then when you run the test, you will see it like this:
``` sh
ErrorTest9: x2 = 0
Expected: x2 = -1 or x2 = 9
Error in tests
```


If you enter something else or don't enter anything at all, the test won't start and you'll see this:

``` sh
Tests were not performed
```
Что-то на русском
