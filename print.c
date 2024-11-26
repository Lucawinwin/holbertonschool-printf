#include"main.h"

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);
    for (ptr = format; *ptr; ptr++) {
        if (*ptr == '%') {
            ptr++;
            if (*ptr == 'c') {
                putchar(va_arg(args, int));
                count++;
            } else if (*ptr == 's') {
                char *str = va_arg(args, char*);
                if (str) {
                    while (*str) {
                        putchar(*str++);
                        count++;
                    }
                } else {
                    fputs("(null)", stdout);
                    count += 6;
                }
            } else if (*ptr == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*ptr);
            count++;
        }
    }
    va_end(args);
    return count;
}

int main() {
    int printed = _printf("Hello, %s! Char: %c, Percent: %%\n", "World", 'A');
    printf("Printed %d characters.\n", printed);
    return 0;
}

