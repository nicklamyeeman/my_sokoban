/*
** EPITECH PROJECT, 2018
** my is prime
** File description:
** check if number is prime
*/

static int is_prime(int mod, int nb)
{
    if (mod != nb) {
        if (nb % mod != 0)
            return (is_prime(mod + 1, nb));
        return (0);
    }
    return (1);
}

int my_is_prime(int nb)
{
    int mod = 2;
    
    if (nb < 2)
        return (0);
    return (is_prime(mod, nb));
}
