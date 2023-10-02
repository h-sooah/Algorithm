#include <iostream>
#include <vector>

using namespace std;

int increaseNumber(int n) {
    
    vector<vector<int>> dp(n+1, vector<int>(10, 1));
    int ans = 0;
        
    for (int i=2; i<=n; i++) {
        for (int j=1; j<10; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= 10007;
            
        }
        
    }
    
    /*
    for (int i=1; i<=n; i++) {
        cout << "[" << i << "] ";
        
        for (int j=0; j<10; j++)
            cout << dp[i][j] << ' ';
        
        cout << '\n';
    }
    */
    
    for (int i=0; i<10; i++) {
        ans += dp[n][i];
        ans %= 10007;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    cout << increaseNumber(N);
    
    return 0;
}