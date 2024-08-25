# The solver of quadratic equations

It's a solver of quadratic equations.
You can enter your own coefficients and get an answer.
``` sh
Enter a: 1
Enter b: -5
Enter c: 4
Answer: x1 = 4, x2 = 1
```
Здесь а - это коэффициент при x^2 b - при x и c это свободный член

There's also a test built into this program. It checks if solver is working correctly.
You can run it if you type --test on the command line.

``` bash
nothing --test
```
при этом будет отображаться, что тест запушен

``` sh
Tests are performed
```
Если в программе есть ошибка, то при запуске теста вы её увидите вот так:
``` sh
ErrorTest9: x2 = 0
Expected: x2 = -1 or x2 = 9
Error in tests
```


Если вы введёте что-то другое или вообще ничего, то тест не запуститься и вы увидите вот это

``` sh
Tests were not performed
```

