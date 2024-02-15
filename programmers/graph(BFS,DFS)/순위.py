def solution(n, results):
    answer = 0
    d = [[0]*101 for _ in range(101)]
    for result in results:
        d[result[0]][result[1]]=1
        d[result[1]][result[0]]=-1

    for i in range(1, n+1):
        for j in range(1, n+1):
            for k in range(1, n+1):
                if i==j or j==k or i==k:
                    continue
                elif d[i][k]==1 and d[k][j]==1:
                    d[i][j]=1
                    d[j][i]=-1
                elif d[i][k]==-1 and d[k][j]==-1:
                    d[i][j]=-1
                    d[j][i]=1
    for i in range(1, n+1):
        for j in range(1, n+1):
            print(d[i][j] ,end=" ")
        print()
    for i in range(1, n+1):
        cnt=1
        for j in range(1, n+1):
            if i==j:
                continue
            else:
                if d[i][j]==1 or d[i][j]==-1:
                    cnt+=1
        if cnt==n:
            answer+=1
    return answer 
