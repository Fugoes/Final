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

# Available syntax

# License

`Final` is licensed under the [WTFPL](http://www.wtfpl.net/). Note that you shall not hand it in as your homework...
