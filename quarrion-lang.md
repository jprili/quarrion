# Quarrion
This document serves as the language definition for
Quarrion.

## What is Quarrion?
Quarrion is another word for a cockatiel,
I have one as a pet, her name is Tofu, and this language
is named after her species of parrot.

This language is interpreted and functional.
Inspired by assembly syntax and Lambda calculus,
this language is a mix of both of them.

# Definitions
A quarrion program is composed of
data, statements, and functions.

The language is defined as
```
statement := function data;
data      := function | literal;
function  := /[_\w]/ {/[_\w\d]/};
literal   := int | float | char | list | "null";
int       := ["-"] /0-9/ {/0-9/};
float     := int ["." {/0-9/}];
char      := """/\w/""";
list      := "[" value {"," value} "]";
```

All `data` in this language are immutable.
However, passing `data` into a function copies it.
