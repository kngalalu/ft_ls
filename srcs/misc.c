#include "ft_ls.h"

/*
** swaps two values
*/
t_file	*lst_swap(t_file *p1, t_file *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

/*
** get the longest file name inside the list
*/
#include "ft_ls.h"

/*
** get the longest file name inside the list
*/
size_t lst_maxlen(t_file *lst)
{
    size_t maxlen;
    size_t current;

    maxlen = 0;
    while (lst)
    {
        current = ft_strlen(lst->name);
        maxlen = (current > maxlen) ? current : maxlen;
        lst = lst->next;
    }
    return maxlen;
}


/*
** free list
*/
int		free_list_content(t_file **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free(*lst);
		*lst = (*lst)->next;
	}
	return (1);
}

/*
** sort tab according to function
*/
int		ft_sort_tab(char **tab, int size, int (*f)(const char*, const char*))
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < size)
	{
		i = j - 1;
		tmp = tab[j];
		while (i >= 0 && f(tab[i], tmp) > 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = tmp;
		j++;
	}
	return (1);
}
