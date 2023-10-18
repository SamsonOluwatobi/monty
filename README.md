
# 0x19. C - Stacks, Queues - LIFO, FIFO



# General

What do LIFO and FIFO mean
What is a stack, and when to use it
What is a queue, and when to use it
What are the common implementations of stacks and queues
What are the most common use cases of stacks and queues
What is the proper way to use global variables
Copyright - Plagiarism
You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
You are not allowed to publish any content of this project.
Any form of plagiarism is strictly forbidden and will result in removal from the program.


Tests
We strongly encourage you to work all together on a set of tests

The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
# Monty Byte Code Interpreter

This project is a Monty Byte Code Interpreter, which is a program that reads Monty byte code files and interprets them. Monty is a scripting language that is first compiled into Monty byte codes. It relies on a unique stack, with specific instructions to manipulate it.

## Monty Byte Code Files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard, but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account.

## The Monty Program

Usage: `monty file`, where `file` is the path to the file containing Monty byte code.

If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.

If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`, where `<file>` is the name of the file.

If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`, where `<line_number>` is the line number where the instruction appears. Line numbers always start at 1.

The Monty program runs the bytecodes line by line and stops if either:
- It executed properly every line of the file.
- It finds an error in the file.
- An error occurred.

## Tasks

### 0. push, pall

Implementing the `push` and `pall` opcodes.

#### The push opcode

The opcode `push` pushes an element to the stack.

Usage: `push <int>`, where `<int>` is an integer.



#### The pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

Usage: `pall`

Format: see example

If the stack is empty, don’t print anything.

### 1. pint

Implement the `pint` opcode.

#### The pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

Usage: `pint`

If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`.

### 2. pop

Implement the `pop` opcode.

#### The pop opcode

The opcode `pop` removes the top element of the stack.

Usage: `pop`

If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`.

### 3. swap

Implement the `swap` opcode.

#### The swap opcode

The opcode `swap` swaps the top two elements of the stack.

Usage: `swap`

If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.

### 4. add

Implement the `add` opcode.

#### The add opcode

The opcode `add` adds the top two elements of the stack.

Usage: `add`

If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.

The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
- The top element of the stack contains the result.
- The stack is one element shorter.

### 5. nop

Implement the `nop` opcode.

#### The nop opcode

The opcode `nop` doesn’t do anything.

Usage: `nop`


# AUTHOR

## SAMSON OLUWATOBI
