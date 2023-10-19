#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e7;

void floydWarshall(int n, vector<vector<int>> &city) {
    // k: 거쳐가는 중간 노드
    for (int k=1; k<=n; k++) {
        // i: 출발 노드
        for (int i=1; i<=n; i++) {
            // j: 도착 노드
            for (int j=1; j<=n; j++) {
                
                // 거쳐가는 게 더 최소 비용이면 갱신
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
                
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, a, b, c;
    cin >> n >> m;
    
    vector<vector<int>> city(n+1, vector<int>(n+1, INF));
    
    // 시작 도시와 도착 도시가 같은 경우는 0
    for (int i=1; i<=n; i++) {
        city[i][i] = 0;
    }
    
    while (m--) {
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c); // 최소값 갱신
    }
    
    floydWarshall(n, city);
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            cout << (city[i][j] == INF ? 0 : city[i][j]) << ' ';
        cout << '\n';
    }
    
    return 0;
}
