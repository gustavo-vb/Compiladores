//Feito por: Diana Vitória & Gustavo Vilas Boas
#include <stdio.h>
#include <stdlib.h>

#define NUM 256

char c;
int PassByNumber;
int linha = 1;

void ErroLexico()
{
    printf("\nERRO LEXICO NA LINHA %d", linha);
    exit(0);
}

int AnalisadorLexico()
{
    do{
        c = getchar();
        if(c == '\n')
            linha++;
    }while(c == ' ' || c == '\t' || c == '\n');

    if(c == EOF)
        return EOF;

    if(c >= '0' && c <= '9')
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
                if(c == '\n')
                    linha++;
                else if(c != EOF)
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
    return 0;
}
