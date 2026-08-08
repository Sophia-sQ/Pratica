import sys

def ss():
    input_data = sys.stdin.read().split()
    N=int(input_data[0])
    
    idx=1
    for i in range(N):
        a=int(input_data[idx])
        b=int(input_data[idx+1])
        idx+=2
        mask=1
        c=a
        while (c<b):
            if mask>b:
                break
            
            if(c|mask<=b):
                c|=mask
                mask<<=1
            else:
                mask<<=2
            
        print(c)
ss()