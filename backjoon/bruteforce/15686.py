from collections import deque
from itertools import combinations

n, m = map(int, input().split())

a = []
chicken = []
house = []

for i in range(n):
    a.append(list(map(int, input().split())))
    
for i in range(n):
    for j in range(n):
        if a[i][j]==1:
            house.append((i, j))
        elif a[i][j]==2:
            chicken.append((i, j))
            


minlen = -1
for chick in combinations(chicken, m):
    sumlen = 0
    for home in house:
        anslen = -1
        for chi in chick:
            length = abs(home[0]-chi[0]) + abs(home[1]-chi[1])
            if anslen ==-1:
                anslen = length
            else:
                anslen = min(anslen, length)
        sumlen += anslen
    if minlen == -1:
        minlen = sumlen
    elif minlen>sumlen:
        minlen = sumlen


print(minlen)        
