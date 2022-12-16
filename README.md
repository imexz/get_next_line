# get_next_line
This project is about programming a function that returns a line read from a file descriptor.
Its goal is to add an essential function to the libft library and introduce to the concept of static variables in C programming.

## Usage

- include **get_next_line.h** header file, where you want to use `get_next_line()`
- compile your code as follows: `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<number> <files>.c`

---

Function prototype:  `char *get_next_line(int fd);`

The returned line includes the terminating \n character,
except if the end of file was reached and the returned line does not end with a \n character.
Returns NULL in case of an error or if there is nothing else to read.
