# LICPP
Lisp Flavoured C++

## About
A tiny library that implements some basic Lisp (mainly Common Lisp) utilities as a DSL, currently just a toy.

## Usage
At least C++ 14 is required.

You may expect everything to work similarly to what you know in Common Lisp (although there will be limitation because of the differences between C++ and Lisp).

## Note
`tlist` stands for the type `List<T>` which does not have an equivalance in Common Lisp, you may think this is `(type t) => [t]` in Haskell.

## Contributing
All functions should be (preferably) implemented in the same way as its corresponding definition in [CLHS](http://www.lispworks.com/documentation/lw70/CLHS/Front/X_AllSym.htm).

## License
GPLv3+
