def buscarpalavra(palavra):
    for key in topicos:
        for i in range(len(topicos[key])):
            if palavra==topicos[key][i]:
                    topicos[key][len(topicos[key])-1]+=1

n = int(input())
topicos = {}
for i in range(n):
    s = list(input().split())
    topicos.update({s[0]: list(s[item] for item in range(2, len(s))) })
    topicos[s[0]].append(0)
    
x = int(input())
x = list(input().split())

for palavra in x:
    buscarpalavra(palavra)

x=[]

for key in topicos:
    x.append(key)

maior=n-1

for item in range(n-1, 0, -1):
    if topicos[x[maior]][len(topicos[x[maior]])-1]>topicos[x[item-1]][len(topicos[x[item-1]])-1]:
        continue
    elif topicos[x[maior]][len(topicos[x[maior]])-1]<topicos[x[item-1]][len(topicos[x[item-1]])-1]:
        maior=item-1
    else:
        if x[maior]<x[item-1]:
            continue
        else:
            maior=item-1
        

print(x[maior])

#SOLUÇÃO

#N = int(input())
#
#dicionario = {}
#cont = {}
#
#for _ in range(N):
#    line = input().split()
#    S = line[0]
#    k = int(line[1])
#    
#    cont[S] = 0
#    for i in range(2, len(line)):
#        word = line[i]
#        dicionario[word] = S
#
#X = int(input())
#maior_valor = 0
#topico_do_artigo = ""
#
#artigo = input().split()
#
#for word in artigo:
#
#    if word not in dicionario:
#        continue
#
#    cont[dicionario[word]] += 1
#
#    if cont[dicionario[word]] > maior_valor or (cont[dicionario[word]] == maior_valor and topico_do_artigo > dicionario[word]):
#        maior_valor = cont[dicionario[word]]
#        topico_do_artigo = dicionario[word]
#
#print(topico_do_artigo)