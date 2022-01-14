![](https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png)

# 0x19. C - Stacks, Queues - LIFO, FIFO

------------

## General
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

------------

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
------------
### Monty Byte Code Commands
- push <int> = pushes an element to the stack
- pall = prints all the values on the stack, starting from the top of the stack
- pint = prints the value at the top of the stack, followed by a new line
- pchar = prints the char at the top of the stack, followed by a new line
- pstr = prints the string starting at the top of the stack, followed by a new line
- pop = removes the top element of the stack
- swap = swaps the top two elements of the stack
- rotl = rotates the stack to the top
- add = adds the top two elements of the stack
- sub = subtracts the top element of the stack from the second top element of the stack
- div = divides the second top element of the stack by the top element of the stack
- mul = multiplies the second top element of the stack with the top element of the stack
- mod = computes the rest of the division of the second top element of the stack by the top element of the stack
- nop = doesn’t do anything

## List of poinst.

|  Point | What is done at this point? | level |
| ------------ | ------------ | ------------ |
| 0. push, pall | Implement the push and pall opcodes. | Mandatory |
| 1. pint | Implement the pint opcode. | Mandatory |
| 2. pop | Implement the swap opcode. |  Mandatory |
| 3. swap  | Implement the swap opcode. |  Mandatory |
| 4. add | Implement the add opcode. |  Mandatory |
| 5. nop | Implement the nop opcode. |  Mandatory |
| 6. sub | Implement the sub opcode. |  Advanced |
| 7. div | Implement the div opcode. |  Advanced |
| 8. mul | Implement the mul opcode. |  Advanced |
| 9. mod | Implement the mod opcode. |  Advanced |
| 10. comments | Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything). | Advanced |
| 11. pchar | Implement the pchar opcode. | Advanced |
| 12. pstr | Implement the pstr opcode. | Advanced |
| 13. rotl | Implement the rotl opcode. | Advanced |

------------

## List of repository files:

------------

## Personal comments.

|  Functions | Archives  | Description |
| ------------ | ------------ | ------------ |
| 2 | monty.c | Main file in which we go through the (.m) and select the corresponding functions contained in the (.m). |
| 0 | monty.h | main header file |
| 4 | functions_2.c | File containing functions to control commands and errors. |
| 5 | functions.c | File containing functions to control the commands. |
| 5 | more_funtions.c | File containing functions to control the commands. |
| 5 | more_funtions2.c | File containing functions to control the commands. |
| 3 | more_funtions3.c | File containing functions to control the commands. |
| 0 | 000.m | File (.m) for testing. |
| 0 | 001.m | File (.m) for testing. |


------------

|  Point | comments   | level |
| ------------ | ------------ | ------------ |
|  |  | Advanced |

------------
------------


![](https://scontent.fbog4-1.fna.fbcdn.net/v/t39.30808-6/270559680_3074660106132032_2239355789427321092_n.jpg?_nc_cat=111&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=glmLw4tmzhkAX_jfADW&_nc_ht=scontent.fbog4-1.fna&oh=00_AT-u2fQFzKrqv6G_m5ReUqZGXrdlq5ClN7SiSy-fdGRngg&oe=61E14467)