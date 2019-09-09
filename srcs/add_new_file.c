#include "ft_ls.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* Constructs full file path */
static int get_full_path(char path[PATH_MAX], char *name, char full_path[PATH_MAX]) {
    int i = 0;

    // Copy directory path
    while (path[i] && i < PATH_MAX - 1) {
        full_path[i] = path[i];
        i++;
    }

    // Add separator if needed
    if (i && path[i - 1] != '/' && i < PATH_MAX - 1)
        full_path[i++] = '/';

    // Append filename
    while (*name && i < PATH_MAX - 1) {
        full_path[i] = *name;
        i++;
        name++;
    }

    // Null-terminate safely
    full_path[i] = '\0';

    if (i >= PATH_MAX - 1) {
        errno = ENAMETOOLONG;
        return 0;  // Failure
    }
    return 1;  // Success
}

/* Creates a new file node */
static t_file *new_file(char path[PATH_MAX], char *name, t_stat *stat) {
    t_file *new = (t_file *)ft_memalloc(sizeof(t_file));
    if (!new) {
        ls_error(NULL, 2);  // Handle memory allocation failure
        return NULL;
    }

    // Copy name
    if (!(new->name = ft_strdup(name))) {
        free(new);
        ls_error(NULL, 2);
        return NULL;
    }

    // Initialize metadata
    new->mode = stat->st_mode;
    new->st_nlink = stat->st_nlink;
    new->st_uid = stat->st_uid;
    new->st_gid = stat->st_gid;
    new->size = stat->st_size;
    new->st_rdev = stat->st_rdev;

#ifdef __APPLE__
    new->time = stat->st_mtimespec.tv_sec;
    new->ntime = stat->st_mtimespec.tv_nsec;
#else
    new->time = stat->st_mtime;
    new->ntime = stat->st_mtim.tv_nsec;
#endif

    new->st_blocks = stat->st_blocks;

    // Get full path
    get_full_path(path, name, new->full_path);
    new->next = NULL;

    return new;
}

/* Adds a new file to the linked list */
int add_new_file(char path[PATH_MAX], char *name, t_file **lst) {
    char full_path[PATH_MAX];
    t_stat stat;

    // Get full path
    if (!get_full_path(path, name, full_path)) {
        ls_error(name, 1);
        return -1;
    }

    // Get file metadata
    if (lstat(full_path, &stat) == -1)
        return -1;

    // Add file to list
    if (!*lst)
        *lst = new_file(path, name, &stat);
    else {
        t_file *current = *lst;
        while (current->next)
            current = current->next;
        current->next = new_file(path, name, &stat);
    }

    return 1;
}
