#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
int get_numbase_len(unsigned int num, unsigned int base);

/**
 * get_int - gets character pointer to the new string containing the int
 * @num: the number to convert to the string
 * Return: character pointer to the newly created string
 * and NULL if malloc fails
 */

char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;

    temp = _abs(num);
    length = get_numbase_len(temp, 10);

    if (num < 0 || num_l < 0)
        length++;
    ret = (char *)malloc(length + 1);
    if (!ret)
        return NULL;

    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';

    return ret;
}

/**
 * _abs - get absolute value of integer
 * @i: the integer to get the absolute value of
 * Return: unsigned integer abs rep of i
 */

unsigned int _abs(int i)
{
    if (i < 0)
        return (unsigned int)(-i);
    return (unsigned int)i;
}

/**
 * get_numbase_len - get length of the buffer needed for unsigned int
 * @num: the number to get the length needed
 * @base: the base of the number representation used by the buffer
 * Return: integer containing the length of the buffer needed
 * must not contain NULL
 */

int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1;

    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return len;
}

/**
 * fill_numbase_buff - fills the buffer with the correct number up to base 36
 * @num: the number to convert to the strings given base
 * @base: the base of the number used in the conversion only works up to base 36
 * @buff: the buffer to fill with the result of the conversion
 * @buff_size: the size of the buffer in the bytes
 * Return: void always
 */

void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
    int rem, i = buff_size - 1;

    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ascii val representation */
            buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
