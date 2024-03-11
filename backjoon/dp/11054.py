import sys
from collections import deque
from queue import PriorityQueue
import heapq
# input = sys.stdin.readline()

# n , m= map(int, input().split())
# graph = [list(map(int, input())) for _ in range(n)]
# check = [[[0]*2 for _ in range(m)] for _ in range(n)]
# dist = [[0 for _ in range(m)] for _ in range(n)]

n = int(input())
a = list(map(int,input().split()))
increase = [1]*n
decrease = [1]*n

for i in range(n):
    for j in range(i+1, n):
        if a[i]<a[j]:
           increase[j]=max(increase[j], increase[i]+1) 
        
for i in range(n-1, -1, -1):
    for j in range(i, -1, -1):
        if a[i]<a[j]:
           decrease[j]=max(decrease[j], decrease[i]+1)

ans=0
for i in range(n):
    ans = max(ans, increase[i]+decrease[i]-1)

print(ans)

