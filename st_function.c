#include "shell.h"

/**
 *_puts - prints a string
 *@str: A pointer to an int that will be updated
 *
 *Return: void
 */
void _puts(char *str)
{
	int t;

	for (t = 0 ; str[t] != '\0' ; t++)
	{
		_putchar(str[t]);
	}
	_putchar('\n');
}

/**
 * _strlen - returns a string
 * @s: integer to be used
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}


/**
 * _strdup - copy a string to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
	int k, l;
	char *s = NULL;

	if (str == NULL)
		return (0);
	for (k = 0; str[k]; k++)
		;
	k++;
	s = malloc(k * sizeof(char *));
	if (!s)
		return (NULL);
	for (l = 0; l < k; l++)
	{
		s[l] = str[l];
	}
	return (s);
}

/**
 * _itoa - integer to ascii
 * @num: num
 * @b: base
 * Return: char
 **/
char *_itoa(int num, int b)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * _putchar - writes c to stdout
 * @c: character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set .
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *str_concat - point back a pointer to array
 *@s1: Array one
 *@s2: Array two
 *Return: Always an array dynamic
 */
char *str_concat(char *s1, char *s2)
{
	char *dst;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*count size total*/
	size = (_strlen(s1) + _strlen(s2) + 1);

	/*malloc*/
	dst = (char *) malloc(size * sizeof(char));

	if (dst == 0)
	{
		return (NULL);
	}

	/*Concat arrays*/
	for (i = 0; *(s1 + i) != '\0'; i++)
		*(dst + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(dst + i) = *(s2 + j);
		i++;
	}
	dst[i] = '\0';

	return (dst);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: returns an integer less  than,  equal  to,  or
 * greater  than zero if s1 is found, respectively, to be
 * less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	char *p3 = s1;
	char *p4 = s2;

	while (*p3 != '\0' && *p4 != '\0' && *p3 == *p4)
	{
		p3++;
		p4++;
	}
	return (*p3 - *p4);
}