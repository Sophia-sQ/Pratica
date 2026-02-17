#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int escolha = 0, ativo = 1, total_clientes = 0;

typedef struct
{
    int numero;
    char titular[50];
    float saldo;
} sistema;

sistema conta[100];

void criar_conta()
{
    srand(time(NULL));

    printf("Nome do titular da conta: ");

    scanf("%s", conta[total_clientes].titular);
    fflush(stdin);
    conta[total_clientes].numero = rand() % 10000;
    printf("O numero dessa conta e: %04d\n\n*Aperte qualquer tecla para ir para a proxima guia. . .", conta[total_clientes].numero);
    getchar();
    total_clientes++;
    menu();
}

void menu()
{
    printf("\033[H\033[J");
    printf("Bem-vindo!\n\n");
    printf("(1) Ja sou cliente\n(2) Criar uma conta\n(3) Sou um colaborador\n(4) Sair\n\n");

    scanf("%d", &escolha);
    fflush(stdin);
    int num_conta = 0, senha = 0, indice=0;
    switch (escolha)
    {
    case 1:
        printf("\033[H\033[J");
        printf("Digite o numero de 4 digitos referente a sua conta: ");

        scanf("%d", &num_conta);
        fflush(stdin);
        indice=buscar_conta(num_conta);

        if (num_conta == conta[indice].numero)
        {
            printf("\033[H\033[J");
            mostrar_conta(indice);
        }

        break;
    case 2:
        printf("\033[H\033[J");
        criar_conta();
        break;

    case 3:
        printf("\033[H\033[J");
        printf("Digite sua senha: \n\n");
        scanf("%d", &senha);
        fflush(stdin);
        if (senha == 2704)
        {
            //buscar_conta();
        }
        break;

    case 4:
        printf("\033[H\033[J");
        printf("F E C H A N D O .   .   .");
        ativo = 0;
        break;

    default:
        break;
    }
}

int buscar_conta(int num_conta)
{
    for (int i = 0; i <= total_clientes; i++)
    {
        if (num_conta == conta[i].numero)
        {
            return i;
        }
    }
}

void mostrar_conta(int indice)
{
    printf("\033[H\033[J");
    printf("Ola, %s.\n\n", conta[indice].titular);
    printf("Numero da conta: %d\nSaldo atual: %.2f\n\n", conta[indice].numero, conta[indice].saldo);
    printf("(1) Fazer um deposito\n(2) Sacar um valor\n(3) Retornar ao inicio\n\n");
    scanf("%d", &escolha);
    fflush(stdin);
    switch (escolha)
    {
    case 1:
        printf("\033[H\033[J");
        depositar(indice);
        break;

    case 2:
        printf("\033[H\033[J");
        sacar(indice);
        break;

    case 3:
        printf("\033[H\033[J");
        menu();
        break;

    default:
        break;
    }
}

void depositar(int indice)
{
    float deposito = 0;
    printf("\nDigite o valor a ser depositado: ");
    scanf("%f", &deposito);
    fflush(stdin);
    if (deposito < 0)
    {
        printf("Impossivel efetuar transacao.\n\n*Aperte qualquer botao para ir para a proxima guia");
        getchar();
    }
    else
    {
        conta[indice].saldo += deposito;
    }
    mostrar_conta(indice);
}

void sacar(int indice)
{
    float saque = 0;
    printf("\nDigite o valor a ser sacado: ");
    scanf("%f", &saque);
    fflush(stdin);
    if (saque > conta[indice].saldo)
    {
        printf("Impossivel efetuar transacao.\n\n*Aperte qualquer botao para ir para a proxima guia");
        getchar();
    }
    else
    {
        conta[indice].saldo -= saque;
    }
    mostrar_conta(indice);
}

int main(int argc, char const *argv[])
{
    printf("\033[H\033[J");
    while (ativo == 1)
    {
        menu();
    }

    return 0;
}
