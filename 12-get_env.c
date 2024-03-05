#include "shell.h"
/**
 * get_env - This function retrieves a value of system env variables.
 * @envn: Name of env variable.
 * Return: Value of env.
*/
{
char *envc, *kvp, **tmpv;

for (tmpv = _genv; *tmpv != NULL; tmpv++)
{
for (kvp = *tmpv, envc = envn;
*kvp == *envc; kvp++, envc++)
{
if (*kvp == '=')
{
break;
}
}
if ((*kvp == '=') && (*envc == '\0'))
return (kvp + 1);
}
return (NULL);
}
