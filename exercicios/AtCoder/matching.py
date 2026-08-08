import sys

def s():
  input_data=sys.stdin.read().split()
  p=[]
  N=int(input_data[0])
  v=input_data[1:]
  
  for i in range(N):
    linha=list(map(int, v[i*N:(i+1)*N]))
    p.append(linha)
  
  001
  
s()