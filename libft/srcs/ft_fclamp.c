float	ft_fclamp(float n, float min, float max)
{
	if (n < min)
		return (min);
	return (n > max ? max : n);
}
