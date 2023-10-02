#include <iostream>
#include <vector>

using namespace std;

int LCS (string s1, string s2) {
    
    int size1 = s1.size();
    int size2 = s2.size();
    
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    
    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }
    
    /*
    for (int i=0; i<size1; i++) {
        for (int j=0; j<size2; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    */
    
    return dp[size1][size2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s1, s2;
    cin >> s1 >> s2;
    
    cout << LCS(s1, s2);
    
    return 0;
}