import sys
import copy
# sys.setrecursionlimit(10**6)
# input = sys.stdin.readline
from collections import deque
# from queue import PriorityQueue
# import heapq

a = input()
b = input()
d = [[0]*(len(b)+1) for _ in range(len(a)+1)]
for i in range(1, len(a)+1):
    for j in range(1, len(b)+1):
        d[i][j] = max(d[i-1][j], d[i][j-1])
        if a[i-1]==b[j-1]:
            d[i][j] = max(d[i][j], d[i-1][j-1]+1)

print(d[len(a)][len(b)])
