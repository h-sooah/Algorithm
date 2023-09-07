#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, N, K;
    cin >> T;
    
    // 연산 및 출력
    while (T--) {
        cin >> N >> K;
        
        long long result = 1;
        long long tmp = 1;
        
        for (int i=K; i>K-N; i--) {
            result *= i;
            result /= tmp;
            tmp++;
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
