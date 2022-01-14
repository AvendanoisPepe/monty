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

### Compilation
Your code will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty`

To run the program type: `./monty <file>`.

## Use

The second argument '<file>' is mandatory because it is the file containing the Monty language bytecodes which normally contains the extension ".m".

### Return:

- If it works correctly - (EXIT_SUCCESS).
- If there is an error in the file - (EXIT_FAILURE)
- An error has occurred - (EXIT_FAILURE)   

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

## Repository functions:

|  Archives | Functions   | Description |
| ------------ | ------------ | ------------ |
| monty.c | main(int argc, char *argv[]) | Monty file interpreter. |
| monty.c | is_opt(char *buffer, stack_t **head, unsigned int line) | Validates the options found in the lines of the file .m |
| functions_2.c | check_push(char *op, __attribute__((unused))unsigned int line) | Validates that the push argument is an integer. |
| functions_2.c | pint(stack_t **stack, unsigned int line_number) | prints the value at the top of the stack. |
| functions_2.c | empty_str(char *str) | Checks whether the string is a space or a linear jump. |
| functions_2.c | err_push(unsigned int line) | Exit by error. |
| functions.c | push(__attribute__((unused))stack_t **head,	__attribute__((unused))unsigned int line) | Checks the value to be entered into the double linked list. |
| functions.c | pall(__attribute__((unused))stack_t **head,	__attribute__((unused))unsigned int line) | function print doublylinked list |
| functions.c | *add_dnodeint(stack_t **head, const int n) | Add new nod doublylinked list |
| functions.c | print_dlistint(const stack_t *h) | Print doublylinked list |
| functions.c | free_dlistint(stack_t *head) | Free doubly link list. |
| more_funtions.c | delete_dnodeint_at_index(stack_t **head, unsigned int index) | Removes the indicated node from the double linked list. |
| more_funtions.c | pop(stack_t **head, unsigned int line) | Validates the node to be deleted. |
| more_funtions.c | swap(stack_t **stack, unsigned int line_number) | swaps the top two elements of the stack |
| more_funtions.c | add(stack_t **stack, unsigned int line_number) | adds the top two elements of the stack |
| more_funtions.c | nop(stack_t **stack, unsigned int line_number) | do nothing |
| more_funtions2.c | sub(stack_t **stack, unsigned int line_number) | subs the top two elements of the stack. |
| more_funtions2.c | divi(stack_t **stack, unsigned int line_number) | divs the top two elements of the stack. |
| more_funtions2.c | mul(stack_t **stack, unsigned int line_number) | muls the top two elements of the stack |
| more_funtions2.c | mod(stack_t **stack, unsigned int line_number) | mods the top two elements of the stack. |
| more_funtions2.c | pchar(stack_t **stack, unsigned int line_number) | The numerical value is printed in its char value. |
| more_funtions3.c | pstr(stack_t **stack, unsigned int line_number) | prints the string starting at the top of the stack |
| more_funtions3.c | rotl(stack_t **stack, unsigned int line_number) | rotates the stack to the top |
| more_funtions3.c | rotr(stack_t **stack, unsigned int line_number) | rotates the stack to the bottom. |

------------

## Example of the push and pall function:

```
vagrant@ubuntu-focal:~/monti/monty$ cat -e bytecodes/001.m
push 1$
push 2$
push 3$
pall$
vagrant@ubuntu-focal:~/monti/monty$ ./monty bytecodes/001.m
3
2
1
```

------------
# Authors

## Hugo Machacon: 
- Git: https://github.com/hmachacom
- Twitter: https://twitter.com/hmachacom
- Linkedin: https://www.linkedin.com/in/hugo-machacon-5262711bb/

## Juan Sebastian Avendaño Gonzalez:
- Git: https://github.com/AvendanoisPepe
- Twitter: https://twitter.com/Sebastian_Aven
- Linkedin: https://www.linkedin.com/in/juan-sebastian-avenda%C3%B1o-gonz%C3%A1lez-8b1185200/
------------


![](https://scontent.fbog4-2.fna.fbcdn.net/v/t39.30808-6/269979152_3079620875635955_1447984171838636696_n.jpg?_nc_cat=108&_nc_rgb565=1&ccb=1-5&_nc_sid=730e14&_nc_ohc=CAiQW7lFwA0AX_Bsj0u&_nc_ht=scontent.fbog4-2.fna&oh=00_AT8SINudsczyjmtt5FufG1BFt-3EYn7XiEQ3t3Cx8dgc9Q&oe=61E4D79E)