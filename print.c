#include"main.h"
#include<stdio.h>

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
{  // if the string is null
fputs("(null)", stdout);  // Post "(null)"
count += 6;  // "(null)" a 6 caractères
}
} else if (*ptr == '%') {  //Processing of specifier '%%' (percentage)
putchar('%');
count++;
}
} else
{  // If it is not a '%', the character is displayed as is
putchar(*ptr);
count++;
}
}

va_end(args);  // Releasing the list of arguments
return count;  // Returns the total number of characters printed
}

int main() 
{
// Example of use
int printed = _printf("Bonjour, %s! Caractère : %c, Pourcentage : %%\n", "Monde", 'A');
printf("Nombre de caractères imprimés : %d.\n", printed); // Displays the number of characters printed
return 0;
}
