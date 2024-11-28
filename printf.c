#include"main.h"
#include<stdio.h>
//* texte à rajouter

int _printf(const char *format, ...);
{
va_list args;
int count = 0;
const char *ptr;

va_start(args, format);

for (ptr = format; *ptr != '/0'; ptr++)
{
if (*ptr == '%')
{
ptr++;
if (*ptr == 'c')
{
char ch = (char) va_arg(args, int);
putchar(ch);
count++;
}
else if (*ptr == 's')
{
char *str = va_arg(args, char*)
if (str != NULL)
{
while (*str)
{
putchar(*str++);
count++;
}
}
else
{

fputs("(null)", stdout);

"(null)"
count += 6;

}
{
else if (*ptr == '%')
{
putchar('%');
count++;
}
}
else
{
putchar(*ptr);
count++;
}
}

va_end(args);
return (count);
}

int main(void)
{

int printed = _printf("Bonjour, %s! Caractère : %c, Pourcentage : %%\n", "Monde", 'A');
printf("Nombre de caractères imprimés : %d.\n", printed);
return (0);
}
