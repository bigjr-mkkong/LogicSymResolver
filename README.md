# Logical Expression Resolver

An Logical Expression Resolver for those people who doesn't want to waste their precious time on solving BORING Logical Expression by hand

Clone the whole repository and run `make` in terminal to compile the source code

# Usage
Remember always use round bracket ( "(" and ")" ) to include input expression even if you do not need to do so.

- "&": Conjunction (AND LOGIC)
- "|": Disjunction (OR LOGIC)
- ">": Implication(IF...THEN...)
- "~": Negation (NOT LOGIC)

Proposition in this program should only be **A SINGLE UPPER CASE LETTER**

# Input/Output example:
```
Input:
    (A|B)
Output:
    A:1 B:1          Result: True
    A:0 B:1          Result: True
    A:1 B:0          Result: True
    A:0 B:0          Result: False

Input:
    (A&~A)
Output:
    A:1 A:1          Result: False
    A:0 A:1          Result: False
    A:1 A:0          Result: False
    A:0 A:0          Result: False
```

# How to Install
If you are using Linux, just clone the repo and run `make` in terminal, you'll see `symbol_res.out` as an ELF file

If **YOU ARE NOT USING LINUX**, you should download an cpp compiler(both clang or g++ should be fine), and execute:
```
g++ symbol_res.cc -o symbol_res.exe
```
in your terminal, then you will see an executable file output(replace g++ with clang if you're using clang).
