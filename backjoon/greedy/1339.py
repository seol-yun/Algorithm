from collections import deque
from itertools import combinations

n = int(input())
a = []
d = [0]*26
for i in range(n):
    s = input()
    for i in range(len(s)):
        d[ord(s[i])-65]+=10**(len(s)-i-1)
        
d.sort(reverse=True)
for i in range(len(d)):
    d[i]*=(9-i)
        
print(sum(d))
