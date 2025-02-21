# FT_LS Project

My own implementation of the famous Unix command: **ls**.

---

## Project Overview

**FT_LS** is a project aimed at recreating the functionality of the Unix `ls` command. The goal is to mimic how `ls` works in Unix-based systems, including handling file and directory listings, managing system calls, and implementing sorting options. This project provides a deeper understanding of file system operations, memory management, and working with command-line utilities at a low level.

---

## Features

### Mandatory Features
The following options are implemented to mimic the behavior of the original `ls` command:

1. **`-l`**: Use a long listing format (displays detailed information about files and directories).
2. **`-R`**: List subdirectories recursively.
3. **`-a`**: Include hidden files (those starting with `.`) in the listing.
4. **`-r`**: Reverse the order of the sort.
5. **`-t`**: Sort by modification time (newest first).

### Bonus Features
The following additional options are implemented as bonuses:

1. **`-c`**: Enable colorized output for directories, files, and symbolic links.
2. **`-1`**: List one file per line.
3. **`-d`**: List directories themselves, not their contents.

---

## Installation

1. **Clone the repository**:
   git clone <repository-url>
   cd ft_ls

2. **Build the project**:
    make

3. **Run the executable**:
    ./ft_ls [options] [file/directory]

4. **Usage**: 
*Basic Usage*
To list files and directories in the current directory:
    ./ft_ls

*Options*
You can combine multiple options to customize the output. For example:

Long listing format with hidden files:
    ./ft_ls -la

Recursive listing with colorized output:
    ./ft_ls -Rc

Sort by modification time in reverse order:
    ./ft_ls -tr

List one file per line:
    ./ft_ls -1

List directories themselves, not their contents:
    ./ft_ls -d

Specifying Files or Directories
You can specify specific files or directories to list:
    ./ft_ls -l /path/to/directory
    ./ft_ls file1.txt file2.txt

## Examples
List all files (including hidden files) in long format:
./ft_ls -la

Recursively list files in a directory with colorized output:
./ft_ls -Rc /path/to/directory

Sort files by modification time (newest first) and display one file per line:
./ft_ls -t1

List directories themselves, not their contents:
./ft_ls -d dir1 dir2

## Resources
Man Page for ls: http://man7.org/linux/man-pages/man1/ls.1.html

Stack Overflow: http://stackoverflow.com/questions/4674006/set-specific-bit-in-byte

## Project Structure
srcs/: Contains the source code for the project.

includes/: Contains header files.

libft/: Contains the custom library used for utility functions.

Makefile: Builds the project and manages dependencies.

README.md: This file, providing an overview and usage instructions.

---
