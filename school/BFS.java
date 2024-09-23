import java.util.*;
class Edge{
    int adjvertex;
    public Edge(int v){
        adjvertex = v;
    }
}

class BFS {
    int N; // 정점의 개수
    List<Edge>[] graph; // 그래프의 인접 리스트
    private boolean[] visited; // 방문한것을 체크하기위한 bool array

    public BFS(List<Edge>[] adjList) {
        N = adjList.length; // 정점의 개수를 저장
        graph = adjList; // 인접 리스트를 그래프에 저장
        visited = new boolean[N];

        // visited 배열 초기화
        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < N; i++) {
            if (!visited[i]) { // 방문하지 않았다면 BFS 실행
                bfs(i);
            }
        }
    }

    private void bfs(int i) {
        Queue<Integer> q = new LinkedList<Integer>(); // bfs를 위한 큐
        q.add(i); // vertex를 큐에 추가
        visited[i] = true; // 방문한것으로 체크

        while (!q.isEmpty()) { // 큐가 끝날때까지 반복
            int current = q.remove(); // 큐에서 vertex 하나 꺼내기
            System.out.print(current+" "); //vertex 출력
            // 현재 vertex에 연결된 모든 vertex 탐색
            for (Edge e : graph[current]) {
                int adj = e.adjvertex;
                if (!visited[adj]) { // 방문하지 않은 vertex라면 큐에 추가
                    q.add(adj);
                    visited[adj] = true; // 방문으로 체크
                }
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
        System.out.printf("BFS(0): ");
        BFS b = new BFS(adjList);
        System.out.println();
    }
    public static void print_graph_Matrix(List<Edge>[] adjList, int N) {
        // 인접 행렬을 나타내는 2차원 배열 생성
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
