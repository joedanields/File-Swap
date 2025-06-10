# File Content Swapper

A simple C program that swaps the contents of two text files automatically.

## Overview

This program reads the contents of two predefined text files (`file1.txt` and `file2.txt`), stores them in memory, and then writes the content of the first file to the second file and vice versa. The operation is performed automatically without requiring user input for filenames.

## Features

- **Automatic Operation**: No user input required - simply run the program
- **Memory Management**: Dynamic memory allocation with proper cleanup
- **Error Handling**: Comprehensive error checking for file operations and memory allocation
- **Cross-Platform**: Works on any system with a C compiler
- **Safe Operation**: Validates file access before performing swap operations

## Requirements

- C compiler (GCC, Clang, or any standard C compiler)
- Two text files named `file1.txt` and `file2.txt` in the same directory as the executable
- Sufficient system memory to hold both file contents

## Installation

1. **Download the source code** (`file_swap.c`)

2. **Compile the program**:
   ```bash
   gcc -o file_swap file_swap.c
   ```

   Or with additional warnings (recommended):
   ```bash
   gcc -Wall -Wextra -o file_swap file_swap.c
   ```

## Usage

### Basic Usage

1. **Create test files** (if they don't exist):
   ```bash
   echo "This is content of file 1" > file1.txt
   echo "This is content of file 2" > file2.txt
   ```

2. **Run the program**:
   ```bash
   ./file_swap
   ```

3. **Verify the swap**:
   ```bash
   cat file1.txt  # Should now contain original content of file2.txt
   cat file2.txt  # Should now contain original content of file1.txt
   ```

### Example

**Before running:**
- `file1.txt`: "Hello World!"
- `file2.txt`: "Goodbye World!"

**After running:**
- `file1.txt`: "Goodbye World!"
- `file2.txt`: "Hello World!"

## File Structure

```
project-directory/
├── file_swap.c      # Source code
├── file_swap        # Compiled executable (after compilation)
├── file1.txt        # First file to swap
├── file2.txt        # Second file to swap
└── README.md        # This file
```

## How It Works

1. **File Reading**: Opens both files in read mode and determines their sizes
2. **Memory Allocation**: Dynamically allocates memory to store each file's content
3. **Content Storage**: Reads the entire content of both files into memory buffers
4. **File Writing**: Writes the content of file1 to file2 and content of file2 to file1
5. **Cleanup**: Frees allocated memory and closes all file handles

## Error Handling

The program handles several error conditions:

- **File Not Found**: If either `file1.txt` or `file2.txt` doesn't exist
- **Permission Denied**: If the program lacks read/write permissions
- **Memory Allocation Failure**: If the system runs out of memory
- **File Write Errors**: If writing to files fails

## Customization

To swap different files, modify these lines in the source code:

```c
char *filename1 = "file1.txt";  // Change to your first file
char *filename2 = "file2.txt";  // Change to your second file
```

Then recompile the program.

## Limitations

- **File Size**: Limited by available system memory (entire files are loaded into RAM)
- **File Names**: Currently hardcoded to `file1.txt` and `file2.txt`
- **File Types**: Designed for text files, but works with any file type
- **Backup**: No automatic backup is created - original content is overwritten

## Safety Considerations

⚠️ **Important**: This program will overwrite the original files. Make sure to:
- Create backups of important files before running
- Test with sample files first
- Ensure you have proper file permissions

## Troubleshooting

### Common Issues

**"Cannot open file" error:**
- Ensure `file1.txt` and `file2.txt` exist in the same directory
- Check file permissions (files must be readable and writable)
- Verify the executable is in the correct directory

**"Memory allocation failed" error:**
- Files may be too large for available memory
- Close other applications to free up memory
- Consider processing smaller files

**Compilation errors:**
- Ensure you have a C compiler installed
- Check that the source file `file_swap.c` is present
- Try using different compiler flags

### Debugging

To enable debug information during compilation:
```bash
gcc -g -Wall -Wextra -o file_swap file_swap.c
```

## Contributing

Feel free to enhance this program by:
- Adding command-line argument support for custom filenames
- Implementing backup functionality
- Adding support for binary files
- Improving error messages
- Adding logging capabilities



## Version History

- **v1.0**: Initial release with basic file swapping functionality
- Automatic operation without user input
- Comprehensive error handling
- Memory management with proper cleanup
