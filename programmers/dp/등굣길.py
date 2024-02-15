def solution(m, n, puddles):
    answer = 0
    d = [[0]*m for _ in range(n)]
    d[0][0]=1
    for i in range(n):
        for j in range(m):
            if [j+1, i+1] in puddles:
                continue
            elif i==0 and j==0:
                continue
            elif i==0:
                d[i][j]=d[i][j-1]
            elif j==0:
                d[i][j]=d[i-1][j]
            else:
                d[i][j]=d[i-1][j]+d[i][j-1]
            d[i][j] %= 1000000007
    

    answer = d[n-1][m-1] %1000000007
    return answer
