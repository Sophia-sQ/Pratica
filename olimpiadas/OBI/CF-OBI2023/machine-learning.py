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

#N = int(input()) #numero de topico/palavras
#
#dicionario = {} #Armazena palavra: tópico
#cont = {} #Armazena o tópico como chave e o número de ocorrências no artigo como valor
#
#for _ in range(N):
#    line = input().split() #linha tópico/palavras
#    S = line[0] #tópico
#    k = int(line[1]) #o numero de palavras relacionadas
#    
#    cont[S] = 0 #chave é o topico cont[chave] é o número de ocorrências para esse tópico
"""Faz a atribuição de cada palavra como chave e tópico como valor """
#    for i in range(2, len(line)): #pula tópico e o inteiro e vai direto para as palavras atreladas
#        word = line[i] #word=palavra
#        dicionario[word] = S #dicionario-valor = tópico
#
#X = int(input()) #número de palavras no artigo
#maior_valor = 0
#topico_do_artigo = ""
#
#artigo = input().split()
#
#for word in artigo:
#    #verifica se existe a chave word no dicionario
#    if word not in dicionario:
#        continue
#    #word é uma palavra no artigo
"""a chaves de dicionario são as palavras relacionadas e o valor, os tópicos,
quando retornar um valor com dicionario[word], essa é uma chave de cont""" 
#    cont[dicionario[word]] += 1
#    #se é o maior numero e o topico do artigo e se topico artigo depois que chave (na ordem alfabética)
#    if cont[dicionario[word]] > maior_valor or (cont[dicionario[word]] == maior_valor and topico_do_artigo > dicionario[word]):
#        maior_valor = cont[dicionario[word]]
#        topico_do_artigo = dicionario[word]
#
#print(topico_do_artigo)
