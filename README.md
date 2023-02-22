# get_next_line
This project is about programming a function that returns a line read from a file descriptor.
Its goal is to add an essential function to the libft library and introduce to the concept of static variables in C programming.

## Usage

- Include **get_next_line.h** header file, where you want to use the `get_next_line()` function.
- Make sure macro `BUFFER_SIZE` is set. For example using `-D BUFFER_SIZE=<integer>` during compilation with gcc.
- Compile with `-D GNL_V1` for usage of the first version.

---

Function prototype:  `char *get_next_line(int fd);`

The returned line includes the terminating `\n` character,
except if the end of file was reached and the returned line does not end with a `\n` character.
Returns NULL in case of an error or if there is nothing else to read.
