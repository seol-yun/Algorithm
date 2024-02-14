dict = {}
check = [False]*51
answer = 0
def dfs(begin, n, target, words):
    global dict
    global answer
    if begin == target:
        answer = n
        return
    for word in words:
        cnt =0 
        for i in range(len(word)):
            if word[i]!=begin[i]:
                cnt+=1
        if cnt==1 and check[dict[word]]==False: 
            check[dict[word]]=True
            dfs(word, n+1, target, words)
            check[dict[word]]=False
    
def solution(begin, target, words):
    global answer
    global dict
    for i in range(len(words)):
        dict[words[i]]=i
    dfs(begin, 0, target, words)
    return answer
