# get_next_line

A C function that reads a text file line by line.

## 📋 Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Function Prototype](#function-prototype)
- [Files Structure](#files-structure)
- [Compilation](#compilation)
- [Testing](#testing)
- [Technical Details](#technical-details)
- [Memory Management](#memory-management)
- [Edge Cases](#edge-cases)

## 🎯 Description

`get_next_line` is a function that allows you to read a file descriptor line by line. Each call to the function returns the next line from the file, including the newline character `\n` (if present). This project teaches efficient memory management, file I/O operations, and static variables in C.

## ✨ Features

- **Line-by-line reading**: Reads one complete line at a time
- **Multiple file descriptors**: Bonus version supports reading from multiple files simultaneously
- **Configurable buffer size**: Adjustable `BUFFER_SIZE` for different performance needs
- **Memory efficient**: Proper memory allocation and deallocation
- **Edge case handling**: Handles empty files, files without newlines, and very long lines

## 🚀 Installation

1. Clone or download the repository
2. Ensure you have a C compiler (gcc, clang, etc.)

## 📖 Usage

### Basic Implementation

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
        
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free!
    }
    
    close(fd);
    return (0);
}
```

### Bonus Implementation (Multiple File Descriptors)

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    // Read alternately from both files
    line = get_next_line(fd1);
    printf("File1: %s", line);
    free(line);
    
    line = get_next_line(fd2);
    printf("File2: %s", line);
    free(line);
    
    close(fd1);
    close(fd2);
    return (0);
}
```

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: File descriptor to read from

**Return Value:**
- Returns the next line from the file (including `\n` if present)
- Returns `NULL` when end of file is reached or an error occurs
- The caller is responsible for freeing the returned string

## 📁 Files Structure

```
get_next_line/
├── get_next_line.c           # Main implementation
├── get_next_line.h           # Header file
├── get_next_line_utils.c     # Utility functions
├── get_next_line_bonus.c     # Bonus: multiple file descriptors
├── get_next_line_bonus.h     # Bonus header file
├── get_next_line_utils_bonus.c # Bonus utility functions
└── txt/                      # Test files
    ├── empty.txt
    ├── longline.txt
    ├── newline.txt
    └── test.txt
```

## ⚙️ Compilation

### Basic Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```

### Bonus Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_test
```

### Different Buffer Sizes
```bash
# Small buffer (good for testing)
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c -o gnl_test

# Large buffer (better performance)
gcc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c -o gnl_test
```

## 🧪 Testing

The project includes several test files:

- **`test.txt`**: Regular file with multiple lines
- **`empty.txt`**: Empty file
- **`newline.txt`**: File with only newlines
- **`longline.txt`**: File with a very long line (tests buffer management)

### Running Tests

```bash
# Test with different files
./gnl_test < txt/test.txt
./gnl_test < txt/empty.txt
./gnl_test < txt/longline.txt

# Test with different buffer sizes
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c your_test.c
gcc -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c your_test.c
```

## 🔍 Technical Details

### Key Components

1. **Static Buffer**: Maintains state between function calls
2. **Dynamic Memory Management**: Efficient allocation and deallocation
3. **String Manipulation**: Custom implementations of string functions
4. **File I/O**: Proper handling of file descriptors and read operations

### Utility Functions

- `ft_strlen()`: Calculate string length
- `ft_strchr()`: Find character in string
- `ft_strdup()`: Duplicate string
- `ft_strndup()`: Duplicate string up to n characters
- `ft_memcpy()`: Copy memory blocks
- `ft_strjoin()`: Concatenate two strings

### Algorithm Overview

1. Read data from file descriptor in chunks of `BUFFER_SIZE`
2. Store data in a static buffer that persists between calls
3. Extract complete lines (up to `\n` or end of file)
4. Return the line and update the buffer with remaining data
5. Handle memory cleanup automatically

## 🧠 Memory Management

- **Automatic cleanup**: Function manages its own memory
- **Caller responsibility**: Must free the returned line
- **No leaks**: Proper cleanup on errors and end of file
- **Buffer optimization**: Reuses static buffer between calls

### Memory Safety Features

```c
// Automatic null pointer checks
if (!buffer || !line)
    return (NULL);

// Proper cleanup on errors
if (malloc_failed)
    return (free_buffer(&buffer), NULL);

// Safe string operations
buffer[bytes_read] = '\0';  // Always null-terminate
```

## 🎯 Edge Cases

The function handles various edge cases:

- **Empty files**: Returns `NULL` immediately
- **Files without final newline**: Returns the last line without `\n`
- **Very long lines**: Dynamically grows buffer as needed
- **Invalid file descriptors**: Returns `NULL` for negative fd
- **Multiple consecutive newlines**: Each newline is treated as a separate line
- **Binary files**: Handles any file type (stops at first `\n` or EOF)

## 🔧 Configuration

### Buffer Size

The `BUFFER_SIZE` macro controls how much data is read at once:

- **Small values (1-10)**: Good for testing, slower performance
- **Medium values (42-1024)**: Balanced approach
- **Large values (4096+)**: Better performance for large files

```c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1  // Default minimum size
#endif
```

## 📝 Notes

- This project follows the 42 School coding standards (Norminette)
- No global variables are used
- Only allowed functions: `read`, `malloc`, `free`
- The bonus version supports up to 1024 simultaneous file descriptors
