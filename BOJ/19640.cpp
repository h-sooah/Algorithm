#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct info {
    int d, h, line, seq; // 근무 일수, 급한 정도, 줄 번호, 도착한 순서
};

struct cmp {
    bool operator() (const info &a, const info &b) {
        // 1. 근무 일수 높은 사람 먼저
        if (a.d != b.d)
            return a.d < b.d;
        // 2. 화장실 급한 사람 먼저
        if (a.h != b.h)
            return a.h < b.h;
        // 3. 줄 번호 가장 낮은 사람 먼저
        return a.line > b.line;
    }
};

int useToilet(vector<queue<info>> &v, int m, int k) {
    priority_queue<info, vector<info>, cmp> pq;
    
    int ans = 0;
    
    for (int i=1; i<=m; i++) {
        if (v[i].empty()) // 해당 줄에 사람이 없을 수도 있음
            continue;
        pq.push(v[i].front());
        v[i].pop();
    }
    
    // 데카의 차례가 될 때까지 반복
    while (pq.top().seq != k + 1) {
        ans++;
        info i = pq.top();
        
        int line = i.line;
        pq.pop();
        
        if (!v[line].empty()) { // 해당 줄에 사람이 있으면 -> pop 할 땐 empty 체크 필수
            pq.push(v[line].front());
            v[line].pop();
        }
    }
    
    return ans;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, m, k;
    cin >> n >> m >> k;
    
    int d, h;
    vector<queue<info>> v(m+1, queue<info>());
    for (int i=1; i<=n; i++) {
        cin >> d >> h;
        
        int line = i % m;
        if (line == 0)
            line = m;
        
        v[line].push({d, h, line, i});
    }
    
    // !주의! 앞에 사람이 없다고 해서 데카가 바로 들어가는 거 X
    // if (k == 0) {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    
    
    cout << useToilet(v, m, k) << '\n';
    
    return 0;
}