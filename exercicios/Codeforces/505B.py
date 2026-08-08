def s():
    n, l, r, x = map(int, input().split())
    d = list(map(int, input().split()))
    
    total=0
    
    
    for i in range((1<<n)+1):
        mask=1
        c=[]
        if i.bit_count()<2:
            continue
        ind=0
        for _ in range(i.bit_length()):
            if (mask&i).bit_count()==1:
                c.append(d[ind])
            mask<<=1
            ind+=1
        
        if (max(c)-min(c))>=x and sum(c)>=l and sum(c)<=r:
            total+=1
    print(total)
s()