# Logical Expression Resolver

An Logical Expression Resolver for those people who doesn't want to waste their precious time on solving BORING Logical Expression by hand

Clone the whole repository and run `make` in terminal to compile the source code

# Usage
Remember always use round bracket ('(') to include input expression even if you do not need to do so.

&: Conjunction (AND LOGIC)
|: Disjunction (OR LOGIC)
>: Implication(If...then...)
~: Negation (NOT LOGIC)

# Input/Output example:
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

# Install:
    If you're using Linux, just clone the whole repo and run make in terminal to get an ELF file called "symbol_res.out"

    IF YOU ARE NOT USING LINUX, you may need to download a c++ compiler and execute following command:
    ```
    g++ symbol_res.cc -o symbol_res.exe
    ```
    under the project directory, then execute the symbol_res.exe in your computer.