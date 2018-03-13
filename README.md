> # *C++! THIS IS THE LAST OF MY PARENTHESES! TAKE IT FROM MEEEEEEE!*

[![GPLv3 license](https://img.shields.io/badge/License-GPLv3-blue.svg)](http://perso.crans.org/besson/LICENSE.html)
[![Open Source Love svg2](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)


[![Made with Secret Alien Technology](https://img.shields.io/badge/Made%20with-Secret%20Alien%20Technology-green.svg?longCache=true&style=for-the-badge&colorB=82ce82)](https://common-lisp.net/)


[![Knights of the Lambda Calculus](https://img.shields.io/badge/Knights%20of-the%20lambda%20Calculus-brightgreen.svg?longCache=true&style=for-the-badge)](http://catb.org/jargon/html/K/Knights-of-the-Lambda-Calculus.html)


# LICPP
Lisp Flavoured C++

## About
A tiny library that implements some basic Lisp (mainly Common Lisp) utilities as a DSL, currently just a toy.

## Usage
At least C++ 14 is required.

You may expect everything to work similarly to what you know in Common Lisp (although there will be limitation because of the differences between C++ and Lisp).

For the details of symbols defined in LICPP, check out [SYMBOLS.md](SYMBOLS.md).

## Note
`tlist` stands for the type `List<T>` which does not have an equivalance in Common Lisp, you may think this is `(type t) => [t]` in Haskell.

## Contributing
All functions should be (preferably) implemented in the same way as its corresponding definition in [CLHS](http://www.lispworks.com/documentation/lw70/CLHS/Front/X_AllSym.htm).

## License
GPLv3+
