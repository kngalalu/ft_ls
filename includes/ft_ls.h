#ifndef FT_LS_H
# define FT_LS_H

/*
** Include necessary headers
** - libft.h: Custom library for utility functions
** - Standard headers for directory operations, file stats, user/group info, etc.
*/
# include "libft.h"
# include <dirent.h>    // Directory entries
# include <sys/stat.h>  // File stats
# include <pwd.h>       // User info
# include <grp.h>       // Group info
# include <time.h>      // Time functions
# include <sys/types.h> // Data types
# include <limits.h>    // PATH_MAX
# include <sys/ioctl.h> // Terminal width

/*
** Error codes for ls_error function
*/
enum {
    ERRNO,    // System error
    USAGE,    // Usage error
    MALL_ERR  // Memory allocation error
};

/*
** Flag definitions for command-line options
** - Each flag is represented by a unique bit in an integer
*/
# define LS_A   1   // -a: Show hidden files
# define LS_L   2   // -l: Long listing format
# define LS_RR  4   // -R: Recursive directory listing
# define LS_R   8   // -r: Reverse sort order
# define LS_T   16  // -t: Sort by modification time
# define LS_D   32  // -d: List directories themselves, not their contents
# define LS_G   64  // -G: Enable colorized output
# define LS_ONE 128 // -1: List one file per line
# define LS_SS  256 // -S: Sort by file size
# define LS_S   512 // -s: Display file size in blocks

/*
** Typedefs for convenience
*/
typedef struct stat     t_stat;     // File stats
typedef struct dirent   t_dirent;   // Directory entry
typedef struct passwd   t_passwd;   // User info
typedef struct group    t_group;    // Group info

typedef struct s_file t_file;

/*
** Struct to represent a file or directory
** - Contains file metadata and a pointer to the next file in the list
*/
typedef struct          s_file {
    blkcnt_t            st_blocks; // Number of blocks allocated
    mode_t              mode;      // File type and permissions
    nlink_t             st_nlink;  // Number of hard links
    uid_t               st_uid;    // User ID of owner
    gid_t               st_gid;    // Group ID of owner
    off_t               size;      // File size in bytes
    dev_t               st_rdev;   // Device ID (if special file)
    time_t              time;      // Last modification time
    long                ntime;     // Nanoseconds for modification time
    char                *name;     // File name
    char                full_path[PATH_MAX]; // Full path of the file
    struct s_file       *next;     // Pointer to the next file in the list
}                       t_file;

/*
** Function prototypes
*/

// Parsing command-line arguments
int                     parsing(int ac, char **av, int *flags);
int                     parse_options(char *s, int *flags);
int                     ls_error(char *s, int error);

// File list initialization and management
t_file                  *init_files_list(char **av, int ac, int first);
void                    only_files(t_file **begin);
int                     add_new_file(char path[PATH_MAX], char *name, t_file **begin);

// Display functions
int                     display_all(t_file *begin, int flags, int recursive, int no_files);
int                     display_list(t_file **begin, int options);
int                     display_detailed_list(t_file *begin, int flags);
void                    display_name(t_file *l, int flags, int blocks_len);

// Sorting functions
int                     sort_list(t_file **begin, short flags);
t_file                  *ft_reverse_lst(t_file *lst);

// Utility functions
t_file                  *lst_swap(t_file *p1, t_file *p2);
// int                     lst_maxlen(t_file *lst);
int                     free_list_content(t_file **lst);
int                     integer_len(int n);
int                     ft_sort_tab(char **tab, int size, int (*f)(const char*, const char*));


size_t lst_maxlen(t_file *lst);

#endif