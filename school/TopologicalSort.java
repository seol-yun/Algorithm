import java.util.*;

public class Main {
    public static void main(String[] args) {
        int N = 9;

        // 인접리스트 생성
        List<Integer>[] adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }

        // 인접한 노드 추가
        adjList[2].add(0); adjList[2].add(1);
        adjList[0].add(1); adjList[1].add(3);
        adjList[1].add(4); adjList[4].add(5);
        adjList[5].add(3); adjList[5].add(7);
        adjList[3].add(6); adjList[6].add(7);
        adjList[7].add(8);

        // 순방향 위상 정렬 수행
        TopologicalSort t = new TopologicalSort(adjList);
        List<Integer> sortedSeq = t.tsort();
        System.out.printf("순방향 위상 정렬: ");
        System.out.println(sortedSeq);

        // 역방향 위상 정렬 수행
        RTopologicalSort rt = new RTopologicalSort(adjList);
        List<Integer> reverseSortedSeq = rt.tsort();
        System.out.printf("역방향 위상 정렬: ");
        System.out.println(reverseSortedSeq);
    }
}
class TopologicalSort {
    int N;                        // 정점의 갯수
    boolean[] visited;             // 방문한 정점을 저장할 배열
    List<Integer>[] adjList;       // 인접리스트
    List<Integer> sequence;        // 위상 순서를 저장할 리스트

    // 생성자
    public TopologicalSort(List<Integer>[] graph) {
        N = graph.length;            // 정점의 갯수 초기화
        visited = new boolean[N];    // 방문 배열 생성
        adjList = graph;             // 그래프를 인접리스트에 할당
        sequence = new ArrayList<>(); // 결과를 저장할 sequence 초기화
    }

    // 위상 정렬 수행 메소드
    public List<Integer> tsort() {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i); // 방문하지 않은 정점에 대해 dfs 호출
            }
        }
        Collections.reverse(sequence); // 순서를 반대로 설정
        return sequence;
    }

    // DFS 메소드
    public void dfs(int i) {
        visited[i] = true; // 현재 정점을 방문한 것으로 표시
        for (int w : adjList[i]) { // 인접한 정점들을 방문
            if (!visited[w]) {
                dfs(w); // 방문하지 않은 정점에 대해 재귀적으로 dfs 호출
            }
        }
        sequence.add(i); //더이상 없으면 추가
    }
}

// 역방향 위상 정렬
class RTopologicalSort {
    int N;                        // 정점의 갯수
    boolean[] visited;             // 방문한 정점을 저장할 배열
    List<Integer>[] adjList;       // 인접리스트
    List<Integer> sequence;        // 위상 순서를 저장할 리스트

    // 생성자
    public RTopologicalSort(List<Integer>[] graph) {
        N = graph.length;            // 정점의 갯수 초기화
        visited = new boolean[N];    // 방문 배열 생성
        adjList = reverseGraph(graph); // 그래프를 역방향 그래프로 변환
        sequence = new ArrayList<>(); // 결과를 저장할 sequence 초기화
    }

    // 역방향 그래프 생성 메소드
    private List<Integer>[] reverseGraph(List<Integer>[] graph) {
        List<Integer>[] reverseGraph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            reverseGraph[i] = new ArrayList<>();
        }
        for (int i = 0; i < N; i++) {
            for (int w : graph[i]) {
                reverseGraph[w].add(i); // 간선의 방향을 반대로
            }
        }
        return reverseGraph;
    }

    // 역방향 위상 정렬 수행 메소드
    public List<Integer> tsort() {
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                dfs(i); // 방문하지 않은 정점에 대해 dfs 호출
            }
        }
        Collections.reverse(sequence); // 결과를 반대로 하여 반환
        return sequence;
    }

    // DFS 메소드
    public void dfs(int i) {
        visited[i] = true; // 현재 정점을 방문한 것으로 표시
        for (int w : adjList[i]) { // 인접한 정점들을 방문
            if (!visited[w]) {
                dfs(w); // 방문하지 않은 정점에 대해 재귀적으로 dfs 호출
            }
        }
        sequence.add(i); // 정점을 방문한 순서에 바로 앞쪽에 추가
    }
}
