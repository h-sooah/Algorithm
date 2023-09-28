#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cost;
vector<bool> visited;
int N, cur_cost;
int ans = 10e8;

void backtracking(int start, int cur, int cnt) {
    
    // 이 조건이 있어야 시간이 확 줄어듦
    if (cur_cost >= ans)
        return;
    
    if (start == cur && cnt == N) {
        ans = min(cur_cost, ans);
        return;
    }
    
    for (int i=0; i<N; i++) {
        if (cost[cur][i] != 0 && visited[i] == false) {
            visited[i] = true;
            cur_cost += cost[cur][i];
            backtracking(start, i, cnt + 1);
            cur_cost -= cost[cur][i];
            visited[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N;
    
    cost.assign(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++)
            cin >> cost[i][j];
    }
    
    visited.assign(N, false);
    cur_cost = 0;
    backtracking(0, 0, 0);
    
    cout << ans << '\n';
    
    return 0;
}