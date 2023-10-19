#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tp;
typedef long long ll;

const int INF = 5e6;

vector<ll> bellmanFord(int n, int m, int start, vector<tp> &move) {
    
    vector<ll> dist(n+1, INF);
    dist[start] = 0;
    
    for (int i=1; i<=n; i++) {
        bool flag = true; // 갱신이 한 번도 안 되면 더 반복할 필요 X
        for (int j=0; j<m; j++) {
            
            int a = get<0>(move[j]);
            int b = get<1>(move[j]);
            int w = get<2>(move[j]);
            
            // 아직은 a->b 이동 불가능하므로 pass
            if (dist[a] == INF) {
                continue;
            }
            
            // a까지 온 가중치 + a->b로 가는 데 필요한 가중치
            ll next_weight = dist[a] + w;
            // 최솟값 갱신 가능하면
            if (next_weight < dist[b]) {
                dist[b] = next_weight;
                flag = false;
                // 음의 사이클이 될 경우
                if (i == n) {
                    return {-1};
                }
            }
            
        }
        if (flag)
            break;
        
    }
    
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, a, b, c;
    cin >> n >> m;
    
    vector<tp> move;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        move.push_back({a, b, c});
    }
    
    vector<ll> ans = bellmanFord(n, m, 1, move);
    
    // 음의 사이클인 경우
    if (ans[0] == -1) {
        cout << -1;
        return 0;
    }
    
    for (int i=2; i<=n; i++)
        cout << (ans[i] == INF ? -1 : ans[i]) << '\n';
    
    return 0;
}
