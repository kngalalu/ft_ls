#include "ft_ls.h"

int error101(char *s1)
{
	FILE * pFile;
	int i;
	pFile=fopen (s1,"rb");
	i = 0;
	if (pFile==NULL)
	{
			i++;
	}
	else
	{ 
		fclose (pFile);
	}
	return (i);	
}
