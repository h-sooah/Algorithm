#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int stealMoney(int n, int m, int k, vector<int> &house) {
    
    // 초기화
    int sum = 0, ans = 0, idx = 0;
    for (int i=0; i<m; i++) {
        sum += house[idx++];
    }
    
    if (sum < k)
        ans++;
        
    // 전체 집의 개수와 훔칠 집의 개수가 같으면 -> 무조건 훔칠 수 있는 건 아님
    if (n == m)
        return ans;
    
    for (int i=0; i<n-1; i++) {
        sum -= house[idx - m];
        sum += house[idx % n];
        idx++;
        
        if (sum < k)
            ans++;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, n, m, k;
    cin >> T;
    
    while (T--) {
        cin >> n >> m >> k;
        
        vector<int> house(n, 0);
        for (int i=0; i<n; i++)
            cin >> house[i];
            
        cout << stealMoney(n, m, k, house) << '\n';
    }

    return 0;
}
