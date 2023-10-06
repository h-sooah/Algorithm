#include <iostream>
#include <vector>

using namespace std;

int countCoins(int n, int k, vector<int> &coins) {
    
    int cnt = 0, idx = n - 1;
    
    while (k) {
        cnt += k / coins[idx];
        k = k % coins[idx];
        idx--;
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    for (int i=0; i<n; i++)
        cin >> coins[i];
    
    cout << countCoins(n, k, coins);
    
    return 0;
}