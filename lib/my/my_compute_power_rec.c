/*
** EPITECH PROJECT, 2018
** my compute power rec
** File description:
** power in recursivity mod
*/

static int power_rec(int pow, int nb, int p)
{
    if (p > 1)
        return(power_rec(pow * nb, nb, p - 1));
    return (pow);
}

int my_compute_power_rec(int nb, int p)
{
    int pow = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (power_rec(pow, nb, p));   
}