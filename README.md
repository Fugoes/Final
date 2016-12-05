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

* `(- <expression1> <expression2>)`

  Only accept two parameters and return `<expression1> - <expression2>`.

* `(* <expressions>)`

  Similar to `+`.

* `(/ <expression1> <expression2>)`

* `(% <expression1> <expression2>)`


* `(> <expression1> <expression2>)`, `(< <expression1> <expression2>)`, `(= <expression1> <expression2>)`

  Compare two expressions value.

* `(if <expression1> <expression2> <expression3>)`

  if `<expression1>` is true, execute `<expression2>` and return its value, else execute `<expression3>` and return its value.

* `(begin <expression1> ... <expressionn>)`

  Execute `<expression1>` to `<expressionn>` one by one, and return the last expression's value.

* `(print <expression1> ... <expressionn>)`

* `(display <expression1> ... <expressionn>)`

* `(runtime)`

  This command will display all variables in your run time.


## Use variable

* `(assign a 5)`

  Assign a to 5. Similar to `=` in python.

* `(set a 5)`

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

The difference between `assign` and `set` could be demonstrated with this example:

```
>>> (assign a 2)
true
>>> (assign b a)
true
>>> (runtime)

name : a
cited: 2
type : Integer
value: 2


name : b
cited: 2
type : Integer
value: 2

true
>>> (set a 4)
true
>>> (runtime)

name : a
cited: 2
type : Integer
value: 4

name : b
cited: 2
type : Integer
value: 4

true
>>> (assign a 2)
true
>>> (runtime)

name : a
cited: 1
type : Integer
value: 2


name : b
cited: 1
type : Integer
value: 4

true
```

What's more, you could only using `set` on an integer.

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

In a function, you cannot use variables defined outside that function.

# License

`Final` is licensed under the [WTFPL](http://www.wtfpl.net/). Note that you shall not hand it in as your homework...
