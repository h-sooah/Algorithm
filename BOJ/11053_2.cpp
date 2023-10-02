#include <iostream>
#include <vector>

using namespace std;

int LIS(int n, vector<int> &arr) {
    
    vector<int> dp(n, 1);
    int ans = 1;
    
    for (int i=0; i<n; i++) {
        
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]); // 중간에 최댓값이 나올 수 있으므로 ans 갱신 필요
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
    
    vector<int> arr(N);
    for (int i=0; i<N; i++)
        cin >> arr[i];
    
    cout << LIS(N, arr);
    
    return 0;
}