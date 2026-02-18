#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// valor na transferencia é sempre 0. verificar

int escolha = 0, ativo = 1, total_clientes = 0;

typedef struct
{
    int numero;
    char titular[50];
    float saldo;
} sistema;

sistema conta[100];

void transferencia(int origem, int conta_destino, float valor)
{
    int destinatario = 0;
    printf("\033[H\033[J");
    destinatario = buscar_conta(conta_destino);
    if (destinatario == -1)
    {
        printf("\nConta nao encontrada\n*aperte qualquer tecla para ir para a proxima guia");
        getchar();
        printf("\033[H\033[J");
        mostrar_conta(origem);
    }
    else if (destinatario == origem)
    {

        printf("\nNao e possivel fazer uma transferencia para si mesmo\n*aperte qualquer tecla para ir para a proxima guia");
        getchar();
        printf("\033[H\033[J");
        mostrar_conta(origem);
    }
    else if (conta_destino == conta[destinatario].numero)
    {
        conta[origem].saldo -= valor;
        conta[destinatario].saldo += valor;
        printf("Tranferencia realizada para %s no valor de R$%f\n*aperte qualquer tecla para ir para a proxima guia", conta[destinatario].titular, valor);
        getchar();
        mostrar_conta(origem);
    }
}

void criar_conta()
{
    srand(time(NULL));

    printf("Nome do titular da conta: ");

    scanf("%s", conta[total_clientes].titular);
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
    int num_conta = 0, senha = 0, indice = 0;
    switch (escolha)
    {
    case 1:
        printf("\033[H\033[J");
        printf("Digite o numero de 4 digitos referente a sua conta: ");

        scanf("%d", &num_conta);

        indice = buscar_conta(num_conta);
        if (indice == -1)
        {
            printf("\nConta nao encontrada\n*aperte qualquer tecla para ir para a proxima guia");
            getchar();
            printf("\033[H\033[J");
        }
        else if (num_conta == conta[indice].numero)
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

        if (senha == 2704)
        {
            // buscar_conta();
        }
        break;

    case 4:
        printf("\033[H\033[J");
        printf("F E C H A N D O .   .   .");
        ativo = 0;
        break;

    default:
        printf("\nValor invalido\n*aperte qualquer tecla para ir para a proxima guia");
        getchar();
        printf("\033[H\033[J");
        break;
    }
}

int buscar_conta(int num_conta)
{
    for (int i = 0; i < total_clientes; i++)
    {
        if (num_conta == conta[i].numero)
        {
            return i;
        }
    }
    return -1;
}

void mostrar_conta(int indice)
{
    int cliente = 0;
    float valor = 0;

    printf("\033[H\033[J");
    printf("Ola, %s.\n\n", conta[indice].titular);
    printf("Numero da conta: %04d\nSaldo atual: %.2f\n\n", conta[indice].numero, conta[indice].saldo);
    printf("(1) Fazer um deposito\n(2) Sacar um valor\n(3) Realizar uma transferencia\n(4) Retornar ao inicio\n\n");
    scanf("%d", &escolha);
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

    case 3: // 0943 1001
        printf("\033[H\033[J");
        printf("Digite o numero da conta do destinatario: ");
        scanf("%d", &cliente);

        printf("Digite o valor da transferencia: ");
        scanf("%f", &valor);

        if (valor > conta[indice].saldo || valor < 0)
        {
            printf("Impossivel efetuar a transferencia.\n\n*Aperte qualquer botao para ir para a proxima guia");
            getchar();
            mostrar_conta(indice);
        }
        else
        {
            transferencia(indice, cliente, valor);
        }
        break;

    case 4:
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
    if (saque > conta[indice].saldo || saque < 0)
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
    strcpy(conta[0].titular, "teste1");
    conta[0].numero = 1111;
    conta[0].saldo = 100;
    total_clientes++;

    strcpy(conta[1].titular, "teste2");
    conta[1].numero = 2222;
    conta[1].saldo = 0;
    total_clientes++;

    printf("\033[H\033[J");
    while (ativo == 1)
    {
        menu();
    }

    return 0;
}