#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long n;
    
    // 입력
    cin >> n;
    
    // 출력
    long long sum = 0;
    for (long long i=1; i<n-1; i++) {
        sum += ((i+1) * i / 2);
    }
    cout << sum << "\n" << 3;
    
    return 0;
}