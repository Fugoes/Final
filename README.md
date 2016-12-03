# Introduction

`Final` is a recursive acronym for `Final is not another lisp`. `Final` is a language, and this project is its interpreter. It is developed to hand in as homework...

# Build

```
$ git clone https://github.com/Fugoes/Final.git
$ cd Final
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```

You could set the complier by passing the `-G` option.

To get release version, use `cmake -DCMAKE_BUILD_TYPE=Release ..` instead of `cmake ..`, and `cmake --build . --config Release` instead of `cmake --build .`.

The binary file will be `Final` under linux and `Final.exe` under Windows.

# Grammar

## Basic

* `(+ <expressions>)`

  For example:

  ```
  >>> (+ 1 2 3)
  6
  >>> (+ (+ 1 2) 1)
  4
  ```

  Note that the number of parameters can be arbitrary.

* `(* <expressions>)`

  Similar to `+`.

* `(- <expression1> <expression2>)`

  Only accept two parameters and return `<expression1> - <expression2>`.

* `(> <expression1> <expression2>)`, `(< <expression1> <expression2>)`, `(= <expression1> <expression2>)`

  Compare two expressions value.

* `(if <expression1> <expression2> <expression3>)`

  if `<expression1>` is true, execute `<expression2>` and return its value, else execute `<expression3>` and return its value.

* `(begin <expression1> ... <expressionn>)`

  Execute `<expression1>` to `<expressionn>` one by one, and return the last expression's value.

* `(print <expression1> ... <expressionn>)`


## Use variable

* `(assign a 5)`

  Assign a to 5. Similar to `=` in python.

In `Final`, each bracket has its own variable scope, for example:

```
>>> (assign a 2)
true
>>> (print a)
2
true
>>> (begin (print a))
2
true
>>> (begin (assign a 3) (print a))
3
true
>>> (print a)
2
true
```

## Define function

Here is an example:

```
>>> (function (fbi n)
...           (if (= n 0)
...               (+ 1)
...               (if (= n 1)
...                   (+ 1)
...                   (+ (fbi (- n 1)) (fbi (- n 2))))))
true
>>> (fbi 10)
89
```

In function, you cannot use variable define outside the function.

# License

`Final` is licensed under the [WTFPL](http://www.wtfpl.net/). Note that you shall not hand it in as your homework...