#include "ft_ls.h"
#include <dirent.h>
#include <sys/stat.h>

/* Reads folder content and returns a linked list of files */
static t_file *read_folder(const char *path, const char *name, int options) {
    t_file *begin = NULL;
    DIR *folder = opendir(path);
    
    if (!folder) { // Handle error if the folder cannot be opened
        ls_error((char *)name, 0);  // Cast to char *
        return NULL;
    }
    
    struct dirent *entry;
    while ((entry = readdir(folder))) { // Iterate over folder contents
        if (entry->d_name[0] != '.' || (options & LS_A)) // Skip hidden files unless LS_A is set
            add_new_file((char *)path, entry->d_name, &begin);  // Cast to char *
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
int display_all(t_file *begin, int flags, t_bool first, int n) {
    if (!(flags & LS_RR) && !first) // Stop if recursive flag is not set and not the first call
        return 1;
    
    for (t_file *file = begin; file; file = file->next) {
        if (S_ISDIR(file->mode) && (first || (strcmp(file->name, ".") && strcmp(file->name, "..")))) {
            display_full_path(file->full_path, n, (int *)&first); // Cast first to int *
            t_file *subdir = read_folder(file->full_path, file->name, flags); // Read subdirectory
            if (subdir) {
                display_list(&subdir, flags); // Pass address of subdir (fix)
                display_all(subdir, flags, 0, -1); // Recursively process subfolders
                free_list_content(&subdir); // Free memory
            }
        }
    }
    return 1;
}
