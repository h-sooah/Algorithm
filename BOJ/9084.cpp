#include <iostream>
#include <vector>

using namespace std;

int numOfCases(int n, vector<int> &coins, int sum) {
    
    vector<int> dp(sum + 1, 0);
    
    dp[0] = 1;
    for (int i=0; i<n; i++) {
        
        for (int j=coins[i]; j<=sum; j++) {
            
            dp[j] += dp[j - coins[i]];
        }
    
    }
    
    
    return dp[sum];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, N, sum;
    cin >> T;
    
    while (T--) {
        cin >> N;
        vector<int> coins(N);
        for (int i=0; i<N; i++) 
            cin >> coins[i];
        cin >> sum;
        
        cout << numOfCases(N, coins, sum) << '\n';
    }
    
    return 0;
}