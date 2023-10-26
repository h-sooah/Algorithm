#include <string>
#include <vector>

using namespace std;

const int INF = 1e7 * 2;

vector<vector<int>> fillGraph(int n, vector<vector<int>> &fares) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    // 자기 자신 초기화
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    
    // 비용 채우기
    for (int i = 0; i < fares.size(); i++) {
        int a = fares[i][0];
        int b = fares[i][1];
        int cost = fares[i][2];
        
        graph[a][b] = cost;
        graph[b][a] = cost;
    }
    
    return graph;
}

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
                
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    vector<vector<int>> graph = fillGraph(n, fares);
    floydWarshall(n, graph);
    
    // i번째 지점까지 합승한다고 가정
    // s -> i (합승구간) 비용 + i -> a (a 혼자 비용) + i -> b (b 혼자 비용) --> 최소 비용 갱신
    for (int i = 1; i <= n; i++) {
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    
    return answer;
}