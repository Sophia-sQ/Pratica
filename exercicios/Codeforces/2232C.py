def s():
    h=int(input())
    for _ in range(h):
        n, t, s=map(int, input().split())
        am=input()
        total=t*s
        mesas=[0]*t
        for i in range(len(am)):
            if sum(mesas)==total:
                  break
            if am[i]=='I':
                try:
                    mesas[mesas.index(0)]+=1
                except ValueError:
                    continue
            elif am[i]=='E':
                for mesa in range(len(mesas)):
                    #print(f"E: {mesas[mesa]}<{s}")
                    if sum(mesas)==0:
                        break
                    if mesas[mesa]>0 and mesas[mesa]<s:
                        mesas[mesa]+=1
                        break
                        #print("pri cond")
                    else:
                        if mesa>0 and mesas[mesa]+2<=s:
                            #print(f"{mesa}, {mesas[mesa]+2<=s}")
                            mesas[mesa]+=2
                            mesas[mesa-1]-=1
                            break
            else:
                for mesa in range(len(mesas)):
                    #print(f"A: {mesas[mesa]}<{s}")
                    if mesas[mesa]<s:
                        try:
                          if am[i+1]=='E' and mesas[mesa]==s-1 and mesas.count(0)==1:
                              mesas[mesas.index(0)]+=1
                              #print("amb viu ext")
                              break
                          else:
                            #print("amb normal")
                            mesas[mesa]+=1
                            break
                        except IndexError:
                            mesas[mesa]+=1
                            break
                        
            #print(mesas)
        print(sum(mesas))
        
s()