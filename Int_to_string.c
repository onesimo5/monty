#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);



/**
 * get_int - Gets a character pointer.
 * @num: Convert number to a string.
 * Return: (0) if malloc fails.
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
    ret = malloc(length + 1);
    if (!ret)
        return (NULL);


    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - Absolute value of an integer.
 * @i: int to get absolute value of.
 * Return: unsigned int of i.
 */


unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}



/**
 * get_numbase_len - gets length of buffer needed for an unsigned int.
 * @num: Print length needed in num.
 * @base: buffer base number.
 * Return: int.
 */



int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1;


    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fill_numbase_buff - fill buffer
 * @num: convert number to string base
 * @base: conversion of number
 * @buff: fill buffer with result of conversion
 * @buff_size: buffer size in bytes
 * Return: void.
 */



void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, i = buff_size - 1;


    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9)
            buff[i] = rem + 87;
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
