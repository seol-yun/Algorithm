parent = [0]*101
def find(x):
    if x!=parent[x]:
        x= find(parent[x])
    return x

def union(a, b):
    a = find(a)
    b = find(b)
    if a<b:
        parent[a]=b
    else:
        parent[b]=a
    
def solution(n, costs):
    answer = 0
    costs = sorted(costs, key = lambda x: x[2])
    print(costs)
    for i in range(101):
        parent[i]=i
    for cost in costs:
        a = find(cost[0])
        b = find(cost[1])
        if(a!=b):
            union(cost[0], cost[1])
            answer+=cost[2]
        
    return answer
