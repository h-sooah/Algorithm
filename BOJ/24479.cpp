#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;
int cnt = 1;

void dfs(int R) {
    
    // 아직 방문 안 했으면
    if (visited[R] == 0) {
        visited[R] = cnt;
        cnt++;
    }
    
    
    for (int x : edges[R]) {
        if (visited[x] == 0)
            dfs(x);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N, M, R, u, v;
    cin >> N >> M >> R;
    
    edges.resize(N+1);
    visited.resize(N+1);
    
    while (M--) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    // 연산 및 출력
    for (int i=1; i<=N; i++)
        sort(edges[i].begin(), edges[i].end());
    
    dfs(R);
    
    for (int i=1; i<=N; i++) {
        cout << visited[i] << "\n";
    }
    return 0;
}