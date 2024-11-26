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
  } else {  // Si la chaîne est NULL
                    fputs("(null)", stdout);  // Afficher "(null)"
                    count += 6;  // "(null)" a 6 caractères
                }
            } else if (*ptr == '%') {  // Traitement du spécificateur '%%' (pourcentage)
                putchar('%');
                count++;
            }
        } else {  // Si ce n'est pas un '%', on affiche le caractère tel quel
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);  // Libération de la liste des arguments
    return count;  // Retourne le nombre total de caractères imprimés
}

int main() {
    // Exemple d'utilisation
    int printed = _printf("Bonjour, %s! Caractère : %c, Pourcentage : %%\n", "Monde", 'A');
    printf("Nombre de caractères imprimés : %d.\n", printed);  // Affiche le nombre de caractères imprimés
    return 0;
}
