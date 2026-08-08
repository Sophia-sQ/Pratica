for sub in empregados[y]["subordinados"]:
            empregados[sub]["gerente"] = [
                x if a == y else a
                for a in empregados[sub]["gerente"]
            ]
            print(empregados[sub]["gerente"])