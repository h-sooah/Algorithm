#include <iostream>
#include <queue>

using namespace std;

vector<int> findParent(int n, vector<vector<int>> &tree) {
    
    vector<int> parent_info(n+1, 0); // 부모 정보 저장할 벡터
    vector<bool> visited(n+1, false); // 방문 체크
    
    queue<int> que;
    
    que.push(1); // 1부터 시작
    visited[1] = true;
    
    while (!que.empty()) {
        int curr = que.front(); // 현재 노드
        que.pop();
        
        for (int i=0; i<tree[curr].size(); i++) {
            int next = tree[curr][i];
            if (visited[next])
                continue;
            
            visited[next] = true;
            parent_info[next] = curr; // 부모 노드 정보 저장
            que.push(next);
        }
    }
    
    return parent_info;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, a, b;
    cin >> n;
    
    vector<vector<int>> tree(n+1, vector<int>());
    for (int i=1; i<n; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    vector<int> result = findParent(n, tree);
    for (int i=2; i<=n; i++)
        cout << result[i] << '\n';

    return 0;
}