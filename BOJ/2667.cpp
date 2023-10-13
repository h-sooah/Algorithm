#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

vector<vector<bool>> visited;

int cntHouse(int row, int col, int n, vector<vector<int>> &house) {
    
    // 집 없거나 이미 방문했으면 패스
    if (!house[row][col] || visited[row][col])
        return 0;
    
    // 방향 벡터
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    stack<ci> stk;

    stk.push({row, col});
    visited[row][col] = true;
    int cnt = 1;
    
    while (!stk.empty()) {
        int r = stk.top().first;
        int c = stk.top().second;
        stk.pop();
        
        // 상하좌우
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && house[nr][nc]) {
                visited[nr][nc] = true;
                stk.push({nr, nc});
                cnt++;
            }
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    vector<vector<int>> house(n, vector<int>(n, 0));
    visited.assign(n, vector<bool>(n, false));
    
    string s;
    for (int i=0; i<n; i++) {
        cin >> s;
        
        for (int j=0; j<n; j++) {
            house[i][j] = s[j] - '0';
        }
    }
    
    
    vector<int> ans;
    int count;
    // 한 칸씩 단지 형성 가능한지 검사
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            count = cntHouse(i, j, n, house);
            if (count != 0)
                ans.push_back(count);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int a : ans)
        cout << a << '\n';
    
    return 0;
}