#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, a, b;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    string s = "*";
    for (int i=1; i<=N; i++) {
        cout << right << setw(N) << fixed << s << "\n";
        s += "*";
    }
    
    return 0;
    
}