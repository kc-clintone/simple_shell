/**
 * atoi_fn - This function casts a string to integer.
 * @str: Target string.
 * Return: Casted string.
*/
int atoi_fn(char *str)
{
unsigned int x = 0;

do {
if (*str == '-')
{
return (-1);
}
else if ((*str < '0' || *str > '9') &&
*str != '\0')
{
return (-1);
}
else if (*str >= '0'  && *str <= '9')
{
x = (x * 10) + (*str - '0');
}
else if (x > 0)
{
break;
}
} while (*str++);
return (x);
}
