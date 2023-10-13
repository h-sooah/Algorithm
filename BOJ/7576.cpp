#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int bfs(int n, int m, int cnt, vector<vector<int>> &tomato, queue<ci> &que) {
    
    // 방향 벡터: 상 하 좌 우
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    int t = 0; // 토마토가 익는 시간
    
    while (!que.empty()) {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        t = tomato[r][c]; // 현재 토마토가 익는 데 걸린 시간
        
        // 상하좌우 이동
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // 이동한 좌표가 유효한 좌표이고, 해당 좌표의 토마토가 아직 안 익은 토마토이면
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && tomato[nr][nc] == 0) {
                tomato[nr][nc] = t + 1; // 다음날 토마토가 익음
                cnt--; // 안 익은 토마토 개수 감소
                que.push({nr, nc});
            }
        }
    }
    return (cnt == 0 ? t-1 : -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m;
    cin >> m >> n;
    
    vector<vector<int>> tomato(n, vector<int>(m, 0));
    queue<ci> que;
    int cnt = 0; // 안 익은 토마토의 총 개수
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                que.push({i, j});
            } else if (tomato[i][j] == 0) {
                cnt++; // 안 익은 토마토의 개수 증가
            }
        }
    }

    cout << bfs(n, m, cnt, tomato, que);

    return 0;
}