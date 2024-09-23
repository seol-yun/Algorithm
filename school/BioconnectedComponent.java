import java.util.*;

// 간선 클래스
class Edge {
    int u, v;
    public Edge(int u, int v) {
        this.u = u;
        this.v = v;
    }
    //간선 출력
    public String toString() {
        return u + " " + v ;
    }
}

class biconnected {
    private List<Integer>[] adjList;  // 인접 리스트
    private boolean[] visited;  // 방문 여부를 저장
    private int sequence = 0;  // dfs할때 정점을 방문한 순서를 저장
    private int[] dfsnum, lownum;  // dfs 순서와 low 값 저장
    private Stack<Edge> stack;  // dfs를 할 때 방문한 간선 저장

    // biconnected 객체를 초기화하는 생성자
    public biconnected(List<Integer>[] adjLists) {
        int N = adjLists.length;
        adjList = adjLists;
        visited = new boolean[N];
        dfsnum = new int[N];
        lownum = new int[N];
        stack = new Stack<>();
    }

    // dfs를 수행하면서 이중 연결 요소를 찾기
    public void bc(int v, int parent) {
        visited[v] = true;
        dfsnum[v] = lownum[v] = ++sequence;  // dfs 방문 순서와 low 값을 초기화

        for (int w : adjList[v]) {
            if (!visited[w]) {  // 방문하지 않은 이웃이면
                stack.push(new Edge(v, w));  // 간선을 스택에 저장
                bc(w, v);  // 재귀적으로 탐색

                // 자식 노드의 서브트리가 조상에 연결되었는지 확인
                lownum[v] = Math.min(lownum[v], lownum[w]);

                // v가 단절점이라면
                if (lownum[w] >= dfsnum[v]) {
                    //스택에서 간선을 팝해서 이중 연결 요소를 출력
                    while (stack.peek().u != v || stack.peek().v != w) {
                        System.out.println(stack.pop().toString());
                    }
                    System.out.println(stack.pop().toString());
                    System.out.println("----------------------");
                }
            } else if (w != parent && dfsnum[w] < dfsnum[v]) {
                // 역방향 간선이 있을 경우 low 값을 수정
                lownum[v] = Math.min(lownum[v], dfsnum[w]);
                stack.push(new Edge(v, w));  // 역방향 간선을 스택에 저장
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int N = 4; //정점 수
        // 인접리스트
        List<Integer>[] adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }

        // 그래프에 정점 연결
        adjList[0].add(1);
        adjList[1].add(0);

        adjList[1].add(2);
        adjList[2].add(1);

        adjList[1].add(3);
        adjList[3].add(1);

        adjList[2].add(3);
        adjList[3].add(2);

        //이중연결 객체 생성
        biconnected b = new biconnected(adjList);

        // 이중연결 요소를 찾기위해 함수 호출
        b.bc(0, -1);
    }
}




