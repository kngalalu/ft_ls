# ft_ls

    Introduction
    Objectives
    Mandatory Part
    How To Use
    SUPPORTED FLAGS
 

ft_ls - This project is a recreation of the command ls that lists all the functions in a directory
Introduction

The ls command is one of the first commands you have learned to use with shell. It is also one you are using the most. Perhaps you have already asked yourself how is this function coded? Thanks to this project, you will soon find out.

To Recode ls and some of its options will allow you to find out how to interact with the file system using C. After all, you already know how to open, read, write and close a file. But, what about the directories? Special files? Rights, dates or sizes of the files?

And while I am on the topic, the quality of your libft will make the difference between a pleasant project experience and an abominable one. For example, if you add ft_printf to your libft, your life will be more enjoyable. It is possible to complete the ft_ls project without the ft_printf function.
Objectives

The project ft_ls opens the path to the Unix branch of the sphere system. For the first time, you will have to face the one libc functions that will allow you to do other things than just read or write on a file descriptor (this is to simplify of course). You will discover a sub-system of functions of operating system’s API, the associated data structures, as well as the management of memory allocation and the associated data.
Mandatory Part

    You must recode the system’s command ls.
    Its behavior must be identical to the original ls command with the following variations:
    Amongst the numerous options available, we are asking you to create the following: -l, -R, -a, -r and -t.
    We strongly recommend that you account for the implications of the option -R from the very beginning of your code...
    You do not have to deal with the multiple column format for the exit when the option -l isn’t in the arguments.

How To Use

• Run the Makefile, e.g make, cMake etc • Call ft_ls as by invoking this call './ft_ls' • Append any flags that you may desire (see below for more), e.g ./ft_ls -Rl
SUPPORTED FLAGS

    -A - Shows all files (including hidden files), but doesn't show the "."
    and ".." directories. (Bonus)
    -R - Shows all files recursively.
    -a - Shows all files including "." and "..".
    -l - Shows files in long format.
    -r - Reverses the output.
    -t - Sorts files according to time.
