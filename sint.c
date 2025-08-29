//Feito por: Diana Vitoria & Gustavo Vilas Boas
#include "analex.h"
#include "pilha.h"

int token;
char posfixa[1000];
int posicao = 0;

void S();
void E();
void E_Linha();
void T();
void T_Linha();
void F();
void consome(int t);
void erro_sintatico();

int main()
{
    token = AnalisadorLexico();

    S();

    if(token != ';')
        erro_sintatico();
    consome(';');

    printf("EXPRESSAO CORRETA\n");
    printf("NOTACAO POSFIXA: %s\n", posfixa);
    printf("RESULTADO DA EXPRESSAO: %d\n", topo());

    return 0;
}

void AdicionaNumero(int v){
    posicao += sprintf(posfixa + posicao, "%d ", v);
}

void AdicionarOperador(char op){
    posicao += sprintf(posfixa + posicao, "%c ", op);
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
    printf("ERRO SINTATICO NA LINHA %d", linha);
    exit(0);
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

        int b = pop();
        int a = pop();
        push(a + b);
        AdicionarOperador('+');

        E_Linha();

    }else if(token == '-'){
        consome('-');
        T();

        int b = pop();
        int a = pop();
        push(a - b);
        AdicionarOperador('-');

        E_Linha();
    }
}

void F()
{
    if(token == NUM)
    {
        int valor = PassByNumber;
        consome(NUM);

        push(PassByNumber);
        AdicionaNumero(PassByNumber);

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

        int b = pop();
        int a = pop();
        push(a * b);
        AdicionarOperador('*');

        T_Linha();

    }else if(token == '/'){

        consome('/');
        F();

        int b = pop();
        int a = pop();
        push(a / b);
        AdicionarOperador('/');

        T_Linha();

    }
}
