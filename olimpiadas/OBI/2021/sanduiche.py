def s():
    
    N, M = map(int, input().split())
    excluded=set()
    total=0
    check=False
    mask=[0]*M
    for i in range(M):
        x, y = map(int, input().split())
        mask[i]|=1<<(x-1)
        mask[i]|=1<<(y-1)
        
    for i in range(1, 1<<N):
        if i in excluded:
            continue
        
        check=True
        for a in range(M):
            if (mask[a]&i)==mask[a]:
                excluded.add(i)
                check=False
                break
                
        if check:
            total+=1
                
    print(total)

s()

#from itertools import combinations
#N, M = map(int, input().split());
#par=[]
#
#for _ in range(M):
#   par.append(set(map(int, input().split())))
#
#total=[]
#for i in range(1, N+1):
#    total.extend(combinations(range(1, N+1), r=i))
#
#for a in par:
#    total = [com for com in total if not a.issubset(com)]
#
#
#print(len(total))