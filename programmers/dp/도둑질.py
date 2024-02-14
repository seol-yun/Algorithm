def solution(money):
    answer = 0
    d = [[0]*2 for _ in range(1000000)]
    d[0][1]=money[0]
    d[1][0]=money[1]
    d[2][1]=money[0]+money[2]
    d[2][0]=money[2]
    for i in range(3, len(money)):
        if i == len(money)-1:
            d[i][0]=max(d[i-2][0], d[i-3][0])+money[i]
        else:
            d[i][0]=max(d[i-2][0], d[i-3][0])+money[i]
            d[i][1]=max(d[i-2][1], d[i-3][1])+money[i]
    
    for i in d:
        for j in i:
            answer = max(j, answer)
    return answer
