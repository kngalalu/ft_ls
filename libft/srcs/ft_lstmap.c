#include "libft.h"

// Apply a function to each element of a list and create a new list
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *list;  // Pointer to the new list

    // Allocate memory for the new list node
    if (!(list = (t_list *)malloc(sizeof(t_list))))
        return NULL;  // Return NULL if allocation fails

    // Check if the function and input list are valid
    if (f && lst)
    {
        // Apply the function to the current element
        list = f(lst);
        // Recursively map the rest of the list
        list->next = ft_lstmap(lst->next, f);
        return list;  // Return the new list
    }
    return NULL;  // Return NULL if input is invalid
}
