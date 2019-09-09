int ft_clamp(int n, int min, int max)
{
    // Clamp 'n' to be within the range [min, max]
    if (n < min)
        return min;  // Return 'min' if 'n' is less than 'min'
    else if (n > max)
        return max;  // Return 'max' if 'n' is greater than 'max'
    return n;  // Return 'n' if it is within the range
}