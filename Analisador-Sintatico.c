#include "Analisador-Lexico.h"

void S();
void E();
void T();
void E_Linha();
void F();
void T_Linha();
void consome();

int token;

main()
{
    token = AnalisadorLexico();

    S();

    if(token != ';')
        erro_sintatico();

    printf("\nAnalise concluida!");
}

void consome(int t){
    if(token == t){
        token = AnalisadorLexico();
    }
    else
        erro_sintatico();
}

void erro_sintatico()
{
    printf("\nErro Sintatico!\n");
    exit(1);
}

void S()
{
    E();
}

void E()
{
    T();
    E_Linha();
}

void T()
{
    F();
    T_Linha();
}

void E_Linha()
{
    if(token == '+')
    {
        consome('+');
        T();
        E_Linha();

    }else if(token == '-'){
        consome('-');
        T();
        E_Linha();
    }
}

void F()
{
    if(token == NUM)
    {
        consome(NUM);
    }else if(token == ID){

        consome(ID);

    }else if(token == '('){

        consome('(');
        E();
        consome(')');
    }else{

        erro_sintatico();

    }
}

void T_Linha()
{
    if(token == '*')
    {
        consome('*');
        F();
        T_Linha();

    }else if(token == '/'){

        consome('/');
        F();
        T_Linha();

    }
}
