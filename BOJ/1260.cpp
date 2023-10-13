#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> adj_matrix;
vector<bool> visited_recur;
vector<int> order;

void dfs(int n, int m, int cur) {
    /*
    visited_recur[cur] = true;
    cout << cur << ' ';
    
    for (int i=1; i<=n; i++) {
        if (!adj_matrix[cur][i] || visited_recur[i])
            continue;
        
        visited_recur[i] = true;
        dfs(n, m, i);
    }
    */
    // 주석 처리한 것도 맞는 코드지만, 이건 반복문에 더 적합한 코드
    // 이 코드가 더 깔끔하고 맞는 코드 같음
    if (visited_recur[cur])
        return;
    
    visited_recur[cur] = true;
    order.push_back(cur);
    
    for (int i=1; i<=n; i++) {
        if (adj_matrix[cur][i])
            dfs(n, m, i);
    }
}

void bfs(int n, int m, int v) {
    
    vector<bool> visited(n+1, false);
    queue<int> que;
    
    que.push(v);
    visited[v] = true;
    
    while (!que.empty()) {
        int cur = que.front();
        cout << cur << ' ';
        que.pop();
        
        for (int i=1; i<=n; i++) {
            // 간선이 없거나 이미 방문한 정점이라면 pass
            if (!adj_matrix[cur][i] || visited[i])
                continue;
            que.push(i);
            visited[i] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, v, a, b;
    cin >> n >> m >> v;
    
    adj_matrix.assign(n+1, vector<bool>(n+1, false));
    visited_recur.assign(n+1, false);
    
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        adj_matrix[a][b] = true;
        adj_matrix[b][a] = true;
    }
    
    dfs(n, m, v);
    for (auto a : order)
        cout << a << ' ';
    
    cout << '\n';
    
    bfs(n, m, v);

    return 0;
}