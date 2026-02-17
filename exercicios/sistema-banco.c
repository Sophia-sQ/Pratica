#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void criar_conta();
void menu();
void mostrar_conta();

int ativo = 1;

typedef struct
{
    int numero;
    char titular[50];
    float saldo;
} sistema;

sistema conta;

int main(int argc, char const *argv[])
{
    system("cls");
    while (ativo == 1)
    {
        menu();
    }

    /* Objetivo
    Criar uma conta bancária básica.

    Requisitos
    struct Conta
    número
    titular (string)
    saldo

    Funções:
    criarConta()
    depositar()
    sacar()
    mostrarConta()

    Regras
    Não permitir saque maior que saldo.
    Não permitir depósito negativo.*/
    return 0;
}

void criar_conta()
{
    srand(time(NULL));

    printf("Nome do titular da conta: ");
    fflush(stdin);
    scanf("%s", conta.titular);
    conta.numero = rand() % 10000;
    printf("O numero dessa conta e: %04d\n\n*Aperte qualquer tecla para ir para a proxima guia. . .", conta.numero);
    getchar();
    menu();
}

void menu()
{
    printf("Bem-vindo!\n\n");
    printf("(1) Ja sou cliente\n(2) Criar uma conta\n(3) Sou um colaborador\n(4) Sair\n\n");
    int escolha = 0;
    fflush(stdin);
    scanf("%d", &escolha);
    int num_conta = 0;

    switch (escolha)
    {
    case 1:
        
        printf("Digite o numero de 4 digitos referente a sua conta: ");
        fflush(stdin);
        scanf("%d", &num_conta);
        if (num_conta == conta.numero)
        {
            system("cls");
            mostrar_conta();
            //DESENVOLVIMENTO
        }
        break;
    case 2:
        system("cls");
        criar_conta();
        break;

    case 3:
        system("cls");
        printf("Digite sua senha: \n\nAREA EM DESENVOLVIMENTO");
        break;

    case 4:
        system("cls");
        printf("F E C H A N D O .   .   .");
        ativo=0;
        break;

    default:
        break;
    }
}

void mostrar_conta()
{
    printf("Olá, %s\n\n", conta.titular);
    printf("Numero da conta: %d\nSaldo atual: %.2f\n\n", conta.numero, conta.saldo);

    //DESENVOLVIMENTO
}