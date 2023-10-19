#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

const int INF = 8e5 * 3; // 중복 순회 가능하므로 3배 해줘야 함

vector<int> dijkstra(int n, int start, vector<vector<int>> &graph) {
    
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    
    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (weight > dist[node]) {
            continue;
        }
        
        for (int i=1; i<=n; i++) {
            // 경로 없으면 패스
            if (!graph[node][i]) {
                continue;
            }
            int next_node = i;
            int next_weight = graph[node][i] + weight;
            
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
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
    int n, e, a, b, c, u, v;
    cin >> n >> e;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    while (e--) {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    
    cin >> u >> v;
    
    /*
    int ans1 = 0, ans2 = 0;
    // 1. 1 -> u -> v -> N 
    vector<int> v1 = dijkstra(n, 1, graph);
    ans1 += v1[u]; // 1 -> u
    v1 = dijkstra(n, u, graph);
    ans1 += v1[v]; // u -> v
    v1 = dijkstra(n, v, graph); 
    ans1 += v1[n]; // v -> N
    
    // 2. 1 -> v -> u -> N
    vector<int> v2 = dijkstra(n, 1, graph);
    ans2 += v2[v]; // 1 -> v
    v2 = dijkstra(n, v, graph);
    ans2 += v2[u]; // v -> u
    v2 = dijkstra(n, u, graph); 
    ans2 += v2[n]; // u -> N 
    
    int ans = min(ans1, ans2);
    */
    
    // 이 코드가 더 깔끔
    vector<int> start_nodes = {1, u, v};
    vector<vector<int>> dist(3, vector<int>(n+1, 0));
    for (int i=0; i<3; i++) {
        dist[i] = dijkstra(n, start_nodes[i], graph);
    }
    
    int ans = min(dist[0][u] + dist[1][v] + dist[2][n],
                dist[0][v] + dist[2][u] + dist[1][n]);
    
    cout << (ans >= INF ? -1 : ans) << '\n';
    
    return 0;
}
