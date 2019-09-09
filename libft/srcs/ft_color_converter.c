#include "libft.h"

// Convert a hex color to RGB
t_rgb ft_hex2rgb(int hex)
{
    t_rgb rgb;

    rgb.r = (hex >> 16) & 0xFF;  // Extract red component
    rgb.g = (hex >> 8) & 0xFF;   // Extract green component
    rgb.b = hex & 0xFF;          // Extract blue component
    return rgb;
}

// Convert RGB to a hex color
int ft_rgb2hex(t_rgb rgb)
{
    return ((int)rgb.r << 16) + ((int)rgb.g << 8) + rgb.b;  // Combine RGB into hex
}

// Convert HSB (HSV) to RGB
t_rgb ft_hsb2rgb(t_hsb hsb)
{
    t_rgb rgb;
    t_vector i;

    i.w = (int)(hsb.h / 60);  // Calculate sector
    i.w = (hsb.h / 60) - i.w; // Fractional part of hue
    i.x = 0xff * (hsb.b * (1 - hsb.s));  // Calculate intermediate values
    i.y = 0xff * (hsb.b * (1 - i.w * hsb.s));
    i.z = 0xff * (hsb.b * (1 - (1 - i.w) * hsb.s));
    hsb.b *= 0xff;  // Scale brightness to 0-255
    hsb.h = (int)(hsb.h / 60);  // Determine hue sector

    // Assign RGB values based on hue sector
    if (hsb.h == 0)
        rgb = (t_rgb){.r = hsb.b, .g = i.z, .b = i.x};
    else if (hsb.h == 1)
        rgb = (t_rgb){.r = i.y, .g = hsb.b, .b = i.x};
    else if (hsb.h == 2)
        rgb = (t_rgb){.r = i.x, .g = hsb.b, .b = i.z};
    else if (hsb.h == 3)
        rgb = (t_rgb){.r = i.x, .g = i.y, .b = hsb.b};
    else if (hsb.h == 4)
        rgb = (t_rgb){.r = i.z, .g = i.x, .b = hsb.b};
    else if (hsb.h == 5)
        rgb = (t_rgb){.r = hsb.b, .g = i.x, .b = i.y};
    else
        rgb = (t_rgb){.r = 0, .g = 0, .b = 0};  // Default to black
    return rgb;
}

// Convert HSB (HSV) to hex color
int ft_hsb2hex(t_hsb hsb)
{
    return ft_rgb2hex(ft_hsb2rgb(hsb));  // Convert HSB to RGB, then to hex
}

// Shade a color by a factor (darken or lighten)
int ft_shade_color(int c, double n)
{
    t_rgb rgb;

    n = (1 - ft_fclamp(n, 0, 1));  // Clamp factor and invert for shading
    rgb.r = ((int)(n * ((c >> 16) & 0xff)) << 16);  // Shade red component
    rgb.g = ((int)(n * ((c >> 8) & 0xff)) << 8);   // Shade green component
    rgb.b = n * (c & 0xff);                        // Shade blue component
    return rgb.r + rgb.g + rgb.b;  // Combine shaded components into hex
}