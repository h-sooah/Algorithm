#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

const int INF = 1e7;

ci dijkstra(int n, int start, vector<vector<ci>> &computer) {
    
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    
    priority_queue<ci, vector<ci>, greater<>> pq;
    pq.push({0, start});
    
    int cnt = 0, t = 0;
    while (!pq.empty()) {
        int cur_time = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        
        if (cur_time > dist[cur_node]) {
            continue;
        }
        
        cnt++;
        t = cur_time;
        
        for (int i=0; i<computer[cur_node].size(); i++) {
            int next_node = computer[cur_node][i].first;
            int next_time = computer[cur_node][i].second + cur_time;
            if (next_time < dist[next_node]) {
                dist[next_node] = next_time;
                pq.push({next_time, next_node});
            }
        }
    }
    
    
    return {cnt, t};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, n, d, c, a, b, s;
    cin >> T;
    
    while (T--) {
        cin >> n >> d >> c; // c번 컴퓨터에서 시작
        
        vector<vector<ci>> computer(n+1, vector<ci>());
        while (d--) {
            cin >> a >> b >> s;
            computer[b].push_back({a, s}); // s초 후 a도 감염
        }
        
        ci ans = dijkstra(n, c, computer);
        cout << ans.first << ' ' << ans.second << '\n';
    }
    
    
    return 0;
}
