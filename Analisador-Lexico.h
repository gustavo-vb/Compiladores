//Feito por: Diana Vitória & Gustavo Vilas Boas

#include <stdio.h>
#include <stdlib.h>

#define NUM 256
#define ID 257

char c;
int PassByNumber;

void ErroLexico()
{
    printf("\nErro Lexico!\n");
    exit(1);
}

int AnalisadorLexico()
{
    do
    {
        c = getchar();
    }while(c == ' ' || c == '\t' || c == '\n');

    if(c >= 'a' && c <= 'z' || (c >= 'A' && c <= 'Z'))
        return ID;
    else if(c >= '0' && c <= '9')
    {
        PassByNumber = c - 48;

        while(1)
        {
            c = getchar();

            if(c >= '0' && c <= '9')
            {
                PassByNumber = PassByNumber * 10 + (c - 48);
            }
            else
            {
                ungetc(c, stdin);
                break;
            }
        }

        return NUM;
    }
    else if(c == '+')
        return '+';
    else if(c == '-')
        return '-';
    else if(c == '*')
        return '*';
    else if(c == '/')
        return '/';
    else if(c == '(')
        return '(';
    else if(c == ')')
        return ')';
    else if(c == ';')
        return ';';

    ErroLexico();
}
