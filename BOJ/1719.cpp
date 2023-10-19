#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e5;

void floyWarshall(int n, vector<vector<int>> &path, vector<vector<int>> &board) {
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                
                // i -> k -> j
                int nt = path[i][k] + path[k][j];
                if (path[i][j] > nt) {
                    path[i][j] = nt;
                    board[i][j] = board[i][k];
                }
                
            }
        }
    }
    
}

/**
 * [택시]
 *
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 
 * ! 여기가 제일 주의해야 할 부분 !
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 14을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, a, b, t;
    cin >> n >> m;
    
    vector<vector<int>> path(n+1, vector<int>(n+1, INF));
    vector<vector<int>> board(n+1, vector<int>(n+1, 0));
    
    // 초기화
    for (int i=1; i<=n; i++) {
        path[i][i] = 0;
    }
    
    while (m--) {
        cin >> a >> b >> t;
        path[a][b] = t;
        path[b][a] = t;
        
        board[a][b] = b;
        board[b][a] = a;
    }
    
    floyWarshall(n, path, board);
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                cout << "-";
            else
                cout << board[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
