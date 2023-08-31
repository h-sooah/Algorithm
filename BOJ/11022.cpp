#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, a, b;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    for (int i=1; i<=N; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": "  << a << " + " << b << " = " << a + b << "\n";
    }
    
    return 0;
    
}