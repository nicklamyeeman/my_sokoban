/*
** EPITECH PROJECT, 2018
** my put nbr
** File description:
** print any number
*/

#include "my.h"

static int display_nbr(int nb, char n)
{
    if (nb < 0) {
    	my_putchar('-');
	    n = nb % 10 * -1 + '0';
	    display_nbr(nb / -10, n);
	    my_putchar(n);
    }
    if (nb > 0) {
	    n = nb % 10 + '0';
	    display_nbr(nb / 10, n);
	    my_putchar(n);
    }
    return (0);
}

int my_put_nbr(int nb)
{
    char n = '\0';
    
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    return (display_nbr(nb, n));
}
