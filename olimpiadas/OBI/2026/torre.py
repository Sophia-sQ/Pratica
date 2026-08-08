N = input()
if (len(N)<4):
    N=list(N)
    N.reverse()
    while(len(N)<4):
        N.append('0')
    N.reverse()
    N="".join(N)

torre=[]
torre.append(int(N))

while (True):
    print(int(N))
    x1, x2=sorted(str(N)), sorted(str(N), reverse=True)
    x1, x2="".join(x1), "".join(x2)
    x1, x2 = int(x1),int(x2)
    #print(f"x1: {x1}, x2: {x2}")
    if (x2-x1) not in torre:
        torre.append(x2-x1)
        N=(x2-x1)
        N=str(N)
        if (len(N)<4):
            N=list(N)
            N.reverse()
            while(len(N)<4):
                N.append('0')
            N.reverse()
            N="".join(N)
    else:
        break