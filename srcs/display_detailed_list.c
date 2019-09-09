#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/sysmacros.h> // Needed for major() and minor()

/* Function Prototypes */
static int get_row_size(t_file *file, int size[7], int *blocks);
static void display_list_items(t_file *lst, int size[7], int flags);

/* Reads folder content and returns a linked list of files */
static t_file *read_folder(const char *path, const char *name, int options) {
    t_file *begin = NULL;
    DIR *folder = opendir(path);
    
    if (!folder) { // Handle error if the folder cannot be opened
        ls_error((char *)name, 0);
        return NULL;
    }
    
    struct dirent *entry;
    while ((entry = readdir(folder))) { // Iterate over folder contents
        if (entry->d_name[0] != '.' || (options & LS_A)) // Skip hidden files unless LS_A is set
            add_new_file((char *)path, (char *)entry->d_name, &begin);
    }
    
    closedir(folder); // Close the folder stream
    return begin;
}

/* Displays the full path to a folder before listing its contents */
static void display_full_path(const char *full_path, int number, int *first) {
    if (number > 1) {
        ft_printf((*first == 2) ? "%s:\n" : "\n%s:\n", full_path);
        *first = 1;
    }
}

/* Recursively displays folders and their content */
int display_all_detailed(t_file *begin, int flags, t_bool first, int n) {
    if (!(flags & LS_RR) && !first) // Stop if recursive flag is not set and not the first call
        return 1;
    
    for (t_file *file = begin; file; file = file->next) {
        if (S_ISDIR(file->mode) && (first || (strcmp(file->name, ".") && strcmp(file->name, "..")))) {
            display_full_path(file->full_path, n, &first); // Print folder name
            t_file *subdir = read_folder(file->full_path, file->name, flags); // Read subdirectory
            if (subdir) {
                display_list(&subdir, flags); // Display contents (Fixed pointer mismatch)
                display_all_detailed(subdir, flags, 0, -1); // Recursively process subfolders
                free_list_content(&subdir); // Free memory (Fixed pointer mismatch)
            }
        }
    }
    return 1;
}

/* Prints detailed file list with -l option */
int display_detailed_list(t_file *lst, int flags) {
    int size[7] = {0};
    int blocks = 0;
    int first = 1;

    get_row_size(lst, size, &blocks); // Get column widths and total blocks
    while (lst) {
        if (first && !(flags & LS_D)) {
            ft_printf("total %d\n", blocks);
            first = 0;
        }
        display_list_items(lst, size, flags); // Print file details
        ft_putchar('\n');
        lst = lst->next;
    }
    return 1;
}

/* Calculates column widths for displaying detailed list */
int get_row_size(t_file *file, int size[7], int *blocks) {
    int len;
    size[5] = size[6] = 3;
    
    while (file) {
        size[0] = MAX(integer_len(file->st_blocks), size[0]);
        size[1] = MAX(integer_len(file->st_nlink), size[1]);
        size[2] = MAX((int)strlen(getpwuid(file->st_uid)->pw_name), size[2]); // Fixed type casting
        size[3] = MAX((int)strlen(getgrgid(file->st_gid)->gr_name), size[3]); // Fixed type casting
        
        if (!S_ISCHR(file->mode)) {
            len = integer_len(file->size);
        } else {
            size[5] = MAX(integer_len(major(file->st_rdev)), size[5]); // Fixed missing function
            size[6] = MAX(integer_len(minor(file->st_rdev)), size[6]); // Fixed missing function
            len = size[5] + size[6] + 2;
        }
        
        size[4] = MAX(len, size[4]);
        *blocks += file->st_blocks;
        file = file->next;
    }
    size[5] = MAX(size[4] - size[6] - 1, size[5]);
    return 1;
}

/* Returns the number of digits in an integer */
int integer_len(int n) {
    int len = 1;
    while (n /= 10) len++;
    return len;
}

/* Dummy implementation for missing function */
static void display_list_items(t_file *lst, int size[7], int flags) {
    (void)size;  // Suppress unused parameter warning
    (void)flags; // Suppress unused parameter warning

    // Placeholder function since it's undefined
    // Implementation should print file details in a structured format
    ft_printf("Displaying details for %s\n", lst->name);
}

