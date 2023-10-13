#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1e5;

int bfs(int n, int k) {
    
    vector<int> visited(MAX + 1, 0);
    queue<int> que;
    
    que.push(n); // n에서 시작
    int t = 0;
    visited[n] = t;
    
    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        
        t = visited[curr];
        
        if (curr == k)
            break;
        
        // 수빈이가 갈 수 있는 윛이 총 3가지
        if (curr - 1 >= 0 && !visited[curr - 1]) {
            visited[curr - 1] = t + 1;
            que.push(curr - 1);
        }
        
        if (curr + 1 <= MAX + 1 && !visited[curr + 1]) {
            visited[curr + 1] = t + 1;
            que.push(curr + 1);
        }
        
        if (2 * curr <= MAX + 1 && !visited[2 * curr]) {
            visited[2 * curr] = t + 1;
            que.push(2 * curr);
        }
    }
    
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, k;
    cin >> n >> k;
    
    cout << bfs(n, k);

    return 0;
}