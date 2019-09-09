#include "libft.h"

// Create a new list node with the given content and content size
t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *lst;  // Pointer to the new node

    // Allocate memory for the new node
    if (!(lst = (t_list *)malloc(sizeof(t_list))))
        return NULL;  // Return NULL if allocation fails

    // Handle NULL content
    if (!content)
    {
        lst->content = NULL;  // Set content to NULL
        lst->content_size = 0;  // Set content size to 0
    }
    else
    {
        // Allocate memory for the content
        if (!(lst->content = malloc(content_size)))
            return NULL;  // Return NULL if allocation fails
        // Copy the content into the new node
        ft_memmove(lst->content, content, content_size);
        lst->content_size = content_size;  // Set the content size
    }

    lst->next = NULL;  // Initialize the next pointer to NULL
    return lst;  // Return the new node
}