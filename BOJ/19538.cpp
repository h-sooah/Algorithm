#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &rumor, vector<int> &init, int N, int M) {
    vector<int> rest(N+1, 0); // 각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(N+1, -1); // 루머를 믿는 시각 정보
    queue<int> que;
    
    // 시작 정점 초기화
    for (int i=0; i<M; i++) {
        ans[init[i]] = 0;
        que.push(init[i]);
    }
    
    // 루머 믿어야 하는 주변인 수 초기화
    for (int i=1; i<=N; i++) {
        rest[i] = (rumor[i].size() + 1) / 2;
    }
    
    while (!que.empty()) {
        int curr = que.front();
        int t = ans[curr];
        que.pop();
        
        for (int i=0; i<rumor[curr].size(); i++) {
            int next = rumor[curr][i];
            // 이미 루머 믿으면
            if (ans[next] > -1)
                continue;
            
            rest[next]--;
            if (!rest[next]) {
                ans[next] = t + 1;
                que.push(next);
            }
        }
        
    }
    
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    cin >> N;
    
    vector<vector<int>> rumor(N+1, vector<int>());
    
    int num;
    for (int i=1; i<=N; i++) {
        while (true) {
            cin >> num;
            
            if (num == 0)
                break;
            
            rumor[i].push_back(num);
        }
    }
    
    // 최초 유포자 입력
    cin >> M;
    vector<int> init(M, 0);
    for (int i=0; i<M; i++) {
        cin >> init[i];
    }
    
    vector<int> ans = bfs(rumor, init, N, M);
    
    for (int i=1; i<=N; i++)
        cout << ans[i] << ' ';

    return 0;
}
