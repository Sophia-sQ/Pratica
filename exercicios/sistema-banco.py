#Objetivo
#Criar uma conta bancária básica.
#
#Requisitos
#struct Conta
#número
#titular (string)
#saldo

#Funções:
#criarConta()
#depositar()
#sacar()
#mostrarConta()
#
#Regras
#Não permitir saque maior que saldo.
#Não permitir depósito negativo.#
sistema=[]
def criar_conta():
    
    titular=input("De o nome do titular da conta: ")
    saldo=float(input("faça um primeiro deposito: "))
    novo_usuario={"nome": titular, "saldo":saldo }
    
    print(novo_usuario["nome"], novo_usuario["saldo"] )

criar_conta()