import sys

def s():
    input_data=sys.stdin.read().split()
    N=int(input_data[0])
    
    idx=1
    for mask in range((1<<N)-1):
        total=0
        for i in range(N):
            if (mask>>i)&1:
                #print(f"soma {int(input_data[i+1])} em {total}")
                total+=int(input_data[i+1])
            else:
                #print(f"sobtrai {int(input_data[i+1])} em {total}")
                total-=int(input_data[i+1])

        #print(total)
        if total%360==0:
            print("YES")
            return
    print("NO")
    
    
s()