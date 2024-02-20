from collections import deque
graph = [[] for _ in range(20001)]
check = [False]*20001
distance = [0]*20001

def solution(n, edge):
    answer = 0
    for i in edge:
        graph[i[0]].append(i[1])
        graph[i[1]].append(i[0])
    q = deque()
    q.append((1, 0))
    check[1]=True
    while(q):
        x, cnt = q.popleft()
        distance[x]=cnt
        for i in graph[x]:
            if check[i]==False:
                check[i]=True
                q.append((i, cnt+1))
        
        
    distance.sort(reverse=True)
    for i in distance:
        if i==distance[0]:
            answer+=1            
    return answer
