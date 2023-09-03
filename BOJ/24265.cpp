#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n;
    
    // 입력
    cin >> n;
    
    // 출력
    long long cnt = 0;
    for (int i=1; i<n; i++) {
        cnt += i;
    }
    
    cout << cnt << "\n" << 2;
    
    return 0;
}