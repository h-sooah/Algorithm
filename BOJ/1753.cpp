#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

const int INF = 2e5;

vector<int> dijkstra(int v, int start, vector<vector<ci>> &graph) {
    
    vector<int> dist(v+1, INF);
    
    priority_queue<ci, vector<ci>, greater<>> pq; // 가중치, 정점 -> 가중치 순으로 정렬
    // 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int w = pq.top().first; // 탐색하지 않은 정점 중 시작점에서 가장 가까운 정점의 가중치
        int v = pq.top().second; // 탐색하지 않은 정점 중 시작점에서 가장 가까운 정점
        pq.pop();
        
        // 값이 더 커 어차피 갱신할 수 없다면
        if (w > dist[v]) {
            continue;
        }
        
        for (int i=0; i<graph[v].size(); i++) {
            int next_node = graph[v][i].first;
            int next_weight = graph[v][i].second;
            
            // 가중치를 갱신할 수 있으면
            if (w + next_weight < dist[next_node]) {
                dist[next_node] = w + next_weight;
                pq.push({dist[next_node], next_node});
            }
        }
        
    }
    
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int v, e, k, a, b, w;
    cin >> v >> e >> k;
    
    vector<vector<ci>> graph(v+1, vector<ci>(0));
    while (e--) {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    
    vector<int> answer = dijkstra(v, k, graph);
    
    for (int i=1; i<=v; i++) {
        if (answer[i] == INF)
            cout << "INF" << '\n';
        else
            cout << answer[i] << '\n';
    }
    
    return 0;
}
