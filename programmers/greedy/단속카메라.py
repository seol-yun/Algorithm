def solution(routes):
    answer = 1
    routes.sort()
    start = -300000
    end = 300000
    for i in range(len(routes)):
        if start<=routes[i][0] and end >= routes[i][0]:
            start = routes[i][0]
        if end >=routes[i][1] and  start<=routes[i][1]:
            end = routes[i][1]
        if end<routes[i][0]:
            start = routes[i][0]
            end = routes[i][1]
            answer+=1
            
    return answer
