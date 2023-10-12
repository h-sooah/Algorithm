#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<vector<bool>> &adj_matrix) {
    int cnt = 0;
    
    vector<int> visited(n+1, false);
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next=1; next<=n; next++) {
            if (!adj_matrix[cur][next] || visited[next])
                continue;
            
            visited[next] = true;
            q.push(next);
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, a, b;
    cin >> n >> m;
    
    vector<vector<bool>> adj_matrix(n+1, vector<bool>(n+1, false));
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj_matrix[a][b] = true;
        adj_matrix[b][a] = true;
    }
    
    cout << bfs(n, adj_matrix);
    
    return 0;
}