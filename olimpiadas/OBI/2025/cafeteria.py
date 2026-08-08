a = int(input()) #min
b = int(input()) #max
c = int(input())
d = int(input())
resultado='N'
i=1
while(d*i+a<=c):
    if (c - d*i) <= b and (c - d*i) >= a :
        resultado='S'
        break
    i+=1

print(resultado)


#RESOLUÇÕES

# -------- FORÇA BRUTA --------

## OBI 2025 - Fase 1
## Cafeteria
#
#a = int(input())
#b = int(input())
#c = int(input())
#d = int(input())
#
#possivel = False
#doses = 1
#
## testa todas as quantidades de doses
#while doses * d <= c:
#  leite = c - doses * d
#  if a <= leite and leite <= b:
#    possivel = True
#  doses += 1
#
#if possivel:
#  print("S")
#else:
#  print("N")
#


# -------- CÁLCULO MATEMÁTICO --------

# OBI 2025 - Fase 1
# Cafeteria

#a = int(input())
#b = int(input())
#c = int(input())
#d = int(input())
#
## pra ter no minimo a de leite, doses precisam ser no maximo isso
## (divisao inteira arredonda pra baixo)
#max_doses = (c - a) // d
#
## pra ter no maximo b de leite, doses precisam ser no minimo isso
## (soma d - 1 pra divisao inteira arredondar pra cima)
#min_doses = (c - b + d - 1) // d
#
#if min_doses <= max_doses:
#  print("S")
#else:
#  print("N")
