def retgen(empregado):
    if len(empregados[empregado]["gerente"]):
        idades.append(empregados[empregado]["idade"])
        for i in range(0, len(empregados[empregado]["gerente"])):
            retgen(empregados[empregado]["gerente"][i])
    else:
        idades.append(empregados[empregado]["idade"])
        return
    
N, M, I = map(int, input().split())
empregados={}
for i, idade in enumerate(map(int, input().split())):
    empregados[i+1]={"idade": idade, "gerente": [], "subordinados": []}
    
for _ in range(M):
    x, y=map(int, input().split())
    empregados[y]["gerente"].append(x)
    empregados[x]["subordinados"].append(y)
    
for i in range(I):
    a = list(input().split())
    x=0
    y=0
    if len(a)<3:
        x=int(a[1])
        idades=[]
        for i in range(0, len(empregados[x]["gerente"])):
            retgen(empregados[x]["gerente"][i])
        try:
            print(min(idades))
        except ValueError:
            print("*")
    else: ##erro revizar
        x=int(a[1])
        y=int(a[2])
        for sub in empregados[x]["subordinados"]:
            empregados[sub]["gerente"] = [
                y if a == x else a
                for a in empregados[sub]["gerente"]
            ]
        for sub in empregados[y]["subordinados"]:
            empregados[sub]["gerente"] = [
                x if a == y else a
                for a in empregados[sub]["gerente"]
            ]

        empregados[x]["gerente"], empregados[y]["gerente"] = empregados[y]["gerente"], empregados[x]["gerente"]
        empregados[x]["subordinados"], empregados[y]["subordinados"] = empregados[y]["subordinados"], empregados[x]["subordinados"]
        
        