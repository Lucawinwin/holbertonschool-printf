#include <unistd.h>

/** * _putchar - Displays a character at the standard output.
 * @ch: The character to display.
 * Return: The number of characters printed (always 1).
 */  
int _putchar(char ch)
{
    return write(1, &ch, 1);  // Write a character on the standard output
}
