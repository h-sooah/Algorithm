#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    if (N == 0 || N == 1) {
        cout << 1 << "\n";
        return 0;
    }
    
    int sum = 1;
    for (int i=2; i<=N; i++)
        sum *= i;
        
    cout << sum << "\n";
    
    return 0;
}
