#include <iostream>
#include <vector>

using namespace std;

int fillRectangle(int n) {
    
    if (n == 1)
        return 1;
    else if (n == 2)
        return 3;
    else if (n == 3)
        return 5;
    
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    
    for (int i=4; i<=n; i++) {
        /*
        * dp[i] 구하는 법
        * = dp[i-2] 에 1x2 2개 붙이는 방법
        * + dp[i-2] 에 2x2 1개 붙이는 방법
        * + dp[i-1] 에 2x1 1개 붙이는 방법
        */
        dp[i] = (dp[i-2] * 2 + dp[i-1]) % 10007;
    }
    
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n;
    cin >> n;
    
    cout << fillRectangle(n);
    
    return 0;
}