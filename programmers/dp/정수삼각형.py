def solution(triangle):
    answer = 0
    l = len(triangle)
    d = [[0] * len(row) for row in triangle] 
    d[0][0]=triangle[0][0]
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            if j==0:
                d[i][j]=d[i-1][j]+triangle[i][j]
            elif j==len(triangle[i])-1:
                d[i][j]= d[i-1][j-1]+triangle[i][j]
            else:
                d[i][j]=max(d[i-1][j-1], d[i-1][j])+triangle[i][j]
                
    answer = max(map(max, d))
    
    return answer
