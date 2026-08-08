import sys

def solve():
    opr=0 #numero de operações realizadas
    input_data=sys.stdin.read().split() #lê tudo de uma vez tipo um arquivo(n sei pq eu usei isso, podia ser um input normal),todos os dados viram uma lista só.
    #lista me ajudou a raciocinar (e só isso), totalmente descartável eu só n quis corrigir
    longcats=[0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 
              16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 
              4194303, 8388607]
    x=int(input_data[0])
    ind=[] #armazena quais foram os longcats usados na operação x^longcat para serem exibidos ao final da execução
    #mask=(1<<N.bit_length()-1)-1   sig=0 outros=1
    for i in range(1, 41): #nao pode começar em 0 e deve rodar no máximo 40 vezes
        if x in longcats: #encerra o laço se x for um longcat
            print(opr)
            if ind:
                #exibição dos longcats
                for i in range(len(ind)):
                    if i+1==len(ind):
                        print(ind[i]) #garante que o output termine com \n
                    else:
                        print(ind[i], sep="", end=" ")
            return
        
        if i%2==0: #em todos os ciclos pares
            x+=1    
            opr+=1
        else: #em todos os ciclos ímpares
            
            #alternativa pela falta de tipo unsigned
            """bit_lenght() retorna o total de bits de x
            do bit menos significativo até o bit ligado (1) mais significativo.
            shift pra direita o total de bits: se x=1010, 1<<4, 10000.
            +(-1) gera o longcat de mesma length de x: 10000-1=1111"""
            mask=(1<<x.bit_length())-1
            
            mask=x^mask #inverso de x (1010 --- 0101)
            for i in longcats: #nem sei pq eu fiz essa parada, dava pra reseolver sem rodar a lista toda e ficar mt melhor, mas fds
                if i&mask==mask: #acha o primeiro longcat que completa x
                #se i=11 e mask=0101, i&mask =0001 
                    ind.append(longcats.index(i)) #guarda o longcat para ser exibido depois
                    x=x^i #substituição e encerramento do looping só quando o longcat correto for encontrado
                    break
            opr+=1

# codigo descobridor de longcats
#for x in range(10000000):
#    if (1<<x.bit_count())-x==1:
#        print(x, sep="", end=", ")
solve()