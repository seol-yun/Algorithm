import sys
from collections import deque
# input = sys.stdin.readline()

n, m = map(int, input().split())
arr = [[0]*n for _ in range(m)]
q = deque([])
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


for i in range(m):
    arr[i] = list(map(int, input().split()))
    for j in range(n):
        if arr[i][j]==1:
            q.append([i, j])

while q:
    x, y = q.popleft()
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]
        if nx>=0 and nx<m and ny>=0 and ny<n:
            if arr[nx][ny]==0:
                arr[nx][ny]=arr[x][y]+1
                q.append([nx, ny])

ans=0
flag=0
for i in range(m):
    for j in arr[i]:
        if j==0:
            flag=1
        ans=max(ans, j)

if flag==1:
    print(-1)
else:
    print(ans-1)

