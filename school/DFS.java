import java.util.*;

//Edge 클래스
class Edge{
    int adjvertex;
    public Edge(int v){
        adjvertex = v;
    }
}
class DFS {
    int N; // 정점의 개수
    List<Edge>[] graph; // 그래프의 인접 리스트
    private boolean [] visited;// 방문한것을 체크하기위한 bool array
    public DFS(List<Edge>[] adjList ) {
        N = adjList.length;
        graph = adjList;
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            visited[i] = false;// visited 초기화
        }
        for (int i = 0; i < N; i++) {
            if (!visited[i])
                dfs(i);// dfs 실시
        }
    }
    private void dfs(int i) {
        //방문한것으로 체크
        visited[i] = true;
        System.out.print(i + " "); //vertex 출력

        //인접 vertex로 dfs 재귀
        for (Edge e : graph[i]) {
            int adj = e.adjvertex;
            if (!visited[adj]) { //방문하지 않았다면 dfs실행
                dfs(adj);
            }
        }
    }
}
public class Main {
    public static void main(String[] args ){
        int N = 10;
        List<Edge>[] adjList = new List[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new LinkedList<>(); //인접리스트 생성
        }
        //10개의 vertex로 구성된 그래프 생성
        Edge e0 = new Edge(0);
        Edge e1 = new Edge(1);
        Edge e2 = new Edge(2);
        Edge e3 = new Edge(3);
        Edge e4 = new Edge(4);
        Edge e5 = new Edge(5);
        Edge e6 = new Edge(6);
        Edge e7 = new Edge(7);
        Edge e8 = new Edge(8);
        Edge e9 = new Edge(9);
        adjList [0].add(e2);
        adjList [0].add(e1);
        adjList [1].add(e3);
        adjList [1].add(e0);
        adjList [2].add(e3);
        adjList [2].add(e0);
        adjList [3].add(e9);
        adjList [3].add(e8);
        adjList [3].add(e2);
        adjList [3].add(e1);
        adjList [4].add(e5);
        adjList [5].add(e7);
        adjList [5].add(e6);
        adjList [5].add(e4);
        adjList [6].add(e7);
        adjList [6].add(e5);
        adjList [7].add(e6);
        adjList [7].add(e5);
        adjList [8].add(e3);
        adjList [9].add(e3);

        print_graph_Matrix(adjList, N); //인접 리스트를 배열로 출력하는 함수
        System.out.printf("DFS: ");
        DFS d = new DFS(adjList);
        System.out.println();
    }
    public static void print_graph_Matrix(List<Edge>[] adjList, int N) {
        //인접 행렬
        int[][] matrix = new int[N][N];

        // 행렬을 0으로 초기화
        for (int i = 0; i < N; i++) {
            Arrays.fill(matrix[i], 0);
        }

        // 간선이 있는 부분을 1로 채우기
        for (int i = 0; i < N; i++) {
            for (Edge edge : adjList[i]) {
                int adj = edge.adjvertex;
                matrix[i][adj] = 1; // 인접한 정점에 대해 1로 설정
            }
        }

        // 인접 행렬 출력
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
