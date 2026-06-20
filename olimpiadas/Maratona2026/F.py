class Pessoa:
    def __init__(self, nome, pai=False):
        self.nome=nome
        self.pai=pai
    

def Procurar(pessoa):
    for obj in todos:
        if obj.nome==pessoa:
            return obj.pai
    return -1

n=int(input())    
todos=[]

for i in range(n):
    p1, p2 = input().split()

    if Procurar(p1)==-1:
        todos.append(Pessoa(p1))

    if Procurar(p2)==-1:
        todos.append(Pessoa(p2, p1))    
        
casamento=list(input().split())
casamento[2]=int(casamento[2])

flag=0
nome=casamento[1]
i=0
while(i<casamento[2]):
    if nome==casamento[0]:
        flag=1
        print("NÃO PODEM CASAR")
        break
    else:
        nome=Procurar(nome)
        i+=1

nome=casamento[0]

i=0
while(i<casamento[2] and flag==0):
    if nome==casamento[1]:
        print("NÃO PODEM CASAR")
        break
    else:
        nome=Procurar(nome)
        i+=1
if i>=casamento[2]:
    print("PODEM CASAR")