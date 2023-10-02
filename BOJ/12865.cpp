#include <iostream>
#include <vector>

using namespace std;

struct stuff {
    int w, v;
};

int maxValue(int n, int k, vector<stuff> &arr) {
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
    for (int i=1; i<=n; i++) {
        
        // 어차피 최대 배낭 무게가 물품 무게보다 작아서 물건을 넣지 x
        // -> 그 전의 값 그대로 사용
        for (int j=0; j<arr[i].w; j++) {
            dp[i][j] = dp[i-1][j];
        }
        // 물품 넣는 경우엔, 배낭에 넣은 경우와 안 넣은 경우 중 최댓값 선택
        for (int j=arr[i].w; j<=k; j++) {
            dp[i][j] = max(dp[i - 1][j - arr[i].w] + arr[i].v, dp[i-1][j]);
        }
        
    }
    
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, k;
    cin >> n >> k;
    
    vector<stuff> arr(n + 1, {0, 0});
    for (int i=1; i<=n; i++)
        cin >> arr[i].w >> arr[i].v;
        
    cout << maxValue(n, k, arr);
    
    return 0;
}