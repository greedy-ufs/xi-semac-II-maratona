n = int(input())
x1 = []
y1 = []
x2 = []
y2 = []
i = 0
while(i < n):
    m = input().split()
    for i in m:
        m[i] = int(m[i])
    
    x1[i] = m[0]
    y1[i] = m[1]
    x2[i] = m[2]
    y2[i] = m[3]
    n -= 1

v1 = 0
v2 = 1
acc = 0
while(v1 < n - 1):
    if(x1[v1]<=x1[v2]and y1[v1]>=y1[v2]and x2[v1]>=x2[v2]and y2[v1]<=y2[v2]):
        acc += 1
    v2+=1
    if(v2 == n - 1):
        v1+=1
        v2=v1+1

print(acc)