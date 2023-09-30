#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumCase(int num) {
    
    if (num == 1)
        return 1;
    else if (num == 2)
        return 2;
    else if (num == 3)
        return 4;
    
    vector<int> dp(num+1, 0);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int i=4; i<=num; i++) {
        /*
        * dp[i] 구하는 법
        * = dp[i-1] + 1인 방법의 수 (= dp[i-1])
        * + dp[i-2] + 2인 방법의 수 (= dp[i-2])
        * + dp[i-3] + 3인 방법의 수 (= dp[i-3])
        */
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        //cout << "dp[" << i << "]: " << dp[i] << '\n';
    }
    
    return dp[num];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T;
    cin >> T;
    
    int num;
    while (T--) {
        cin >> num;
        
        cout << sumCase(num) << '\n';
    }
    
    return 0;
}