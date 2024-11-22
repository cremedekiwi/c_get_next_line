# get_next_line
The `get_next_line` project is a popular programming exercise in the C programming language. The aim of the project is to create a function that reads and returns a single line from a file descriptor, handling file reading efficiently and correctly regardless of the file size or content.

## Features
- Reads and returns one line at a time from a file descriptor.
- Handles multiple file descriptors simultaneously (e.g., reading from different files or standard input at the same time).
- Handles lines of arbitrary length, even across multiple buffer reads.
- Memory-efficient design with dynamic allocation.

## Requirements
The `get_next_line` function must conform to the following rules:

- Function prototype:  
  ```c
  char *get_next_line(int fd);
  ```
- **Return values**:
  - Returns the next line from the file descriptor, including the newline character.
  - Returns `NULL` when there is nothing more to read or if an error occurs.
- Must use a buffer for efficient reading from the file descriptor, defined as `BUFFER_SIZE` during compilation.

## Installation
To include `get_next_line` in your project, follow these steps:

1. Clone or download the repository containing the implementation files.
2. Add the `.c` and `.h` files into your project directory.
3. Compile your program with the necessary files and define the `BUFFER_SIZE` during compilation:
   ```sh
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_program.c -o your_program
   ```

## Usage
Here is a basic example of how to use `get_next_line`:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Files
The project typically includes the following files:

- **`get_next_line.h`**: Header file with function prototypes, necessary includes, and macros.
- **`get_next_line.c`**: Contains the main logic of the `get_next_line` function.
- **`get_next_line_utils.c`**: Contains helper functions like memory management, string manipulation, and buffer handling.

## Implementation Details
1. **Buffer Management**:
   - The function reads chunks of data from the file descriptor using a statically sized buffer (`BUFFER_SIZE`).
   - The buffer content is stored and reused to minimize system calls.

2. **Dynamic String Management**:
   - Lines are dynamically allocated and grow as needed to accommodate data from the buffer.

3. **Handling Multiple File Descriptors**:
   - File descriptors are managed independently using static variables or arrays.

4. **Edge Cases**:
   - Empty files or files without newlines are handled gracefully.
   - Memory is cleaned up properly in case of errors.

## Testing
To test the function:

1. Create several text files with varying content (e.g., empty files, long lines, multiple lines).
2. Use `get_next_line` to read each file and ensure correctness.
3. Test edge cases, such as invalid file descriptors or reading from standard input.

## Limitations
- The function does not handle binary files well unless newline characters (`\n`) are expected.
- Memory leaks may occur if not freed correctly after use.

## Notes
- Ensure `BUFFER_SIZE` is optimized for the expected use case.
- Follow good coding practices like checking for memory leaks using tools like `valgrind`.
