#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

ci findRoomSize(int r, int b) {
    
    int sum = r + b;
    
    for (int k=sum-1; k>=1; k--) {
        
        if (sum % k != 0)
            continue;
            
        int n = k;
        int m = sum / k;
        
        //cout << "n: " << n << ", m: " << m << '\n';
        int cnt_r = 0, cnt_b = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1)
                    cnt_r++;
                else
                    cnt_b++;
            }
        }
        
        if (cnt_r == r && cnt_b == b)
            return {n, m};
    }
    
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int R, B;
    cin >> R >> B;
    
    ci result = findRoomSize(R, B);
    cout << result.first << ' ' << result.second << '\n';
    
    return 0;
}
