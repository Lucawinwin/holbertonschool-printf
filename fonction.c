#ifndef'MAIN.H'
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Fonction personnalisée d'impression formatée
 * @format: Chaîne de format avec spécificateurs de conversion
 * 
 * Retourne : Nombre de caractères imprimés
 */
int _printf(const char *format, ...)
{
    va_list arguments;
    int caracteres_imprimes = 0;

    va_start(arguments, format);

    while (*format)
    {
        // Gestion des caractères ordinaires
        if (*format != '%')
        {
            write(1, format, 1);
            caracteres_imprimes++;
            format++;
            continue;
        }

        // Passer le '%'
        format++;

        // Gestion des spécificateurs de conversion
        switch (*format)
        {
            case 'c':
            {
                char caractere = va_arg(arguments, int);
                write(1, &caractere, 1);
                caracteres_imprimes++;
                break;
            }
            case 's':
            {
                char *chaine = va_arg(arguments, char*);
                if (chaine == NULL)
                    chaine = "(nul)";
                
                int longueur = 0;
                while (chaine[longueur])
                    longueur++;
                
                write(1, chaine, longueur);
                caracteres_imprimes += longueur;
                break;
            }
            case '%':
            {
                write(1, "%", 1);
                caracteres_imprimes++;
                break;
            }
            default:
                // Pour les spécificateurs non pris en charge
                write(1, "%", 1);
                write(1, format, 1);
                caracteres_imprimes += 2;
                break;
        }

        format++;
    }

    va_end(arguments);
    return caracteres_imprimes;
}
