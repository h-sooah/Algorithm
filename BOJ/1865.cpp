#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;

struct info {
    int s, e, t;
};

bool bellmanFord(int n, vector<info> &roads) {
    // 모든 정점에 도달할 수 있는 가짜 정점(0)이 있다고 가정
    vector<int> dist(n+1, 0); // 가짜 정점 0에서 모든 정점으로의 거리가 0인 간선이 있다고 가정
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < roads.size(); j++) {
            
            int s = roads[j].s;
            int e = roads[j].e;
            int t = roads[j].t;
            
            // s -> e 간선 아직 없으면
            if (dist[s] == INF) {
                continue;
            }
            
            if (dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;
                
                // 음의 사이클
                if (i == n) {
                    return true;
                }
            }
            
        }
    }
    
    return false;
}

/**
 * [웜홀]
 *
 * 벨만-포드 문제
 *
 * 시간이 되돌아가서 출발 지점에 도착하는 경우 = 음의 사이클이 생긴 경우
 *
 * 특별히 시작점이 주어지지 않았으므로, 벨만-포드를 특정 정점에서 시작하는 경우만 돌릴 시 해당 정점에서 닿을 수 없는 음의 사이클의 존재를 판단할 수 없음
 * 그러나, 모든 정점에서 벨만-포드 연산을 하게 되면 O(n^2*E)의 시간 복잡도가 걸려서 효율적이지 않음
 * 
 * => ! 이럴 땐, 모든 정점에 도달할 수 있는 임의의 가짜 정점을 만들어서 시작점을 0으로 하는 한 번의 벨만-포드 연산으로 그래프 전체에 대한 음의 사이클 존재 여부 판단!
 * => 이때, 가짜 정점 0에서 모든 정점으로의 거리가 0인 간선이 있다고 가정하여 dist배열을 0으로 초기화
 *
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int TC, n, m, w, s, e, t;
    cin >> TC;
    
    while (TC--) {
        cin >> n >> m >> w;
        
        vector<info> roads;
        for (int i=0; i<m; i++) {
            cin >> s >> e >> t;
            roads.push_back({s, e, t}); // 도로는 무방향
            roads.push_back({e, s, t}); // 도로는 무방향
        }
        for (int i=0; i<w; i++) {
            cin >> s >> e >> t;
            roads.push_back({s, e, -t});
        }
        
        if (bellmanFord(n, roads))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}