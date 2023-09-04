#include <iostream>
#include <vector>

using namespace std;

void solution(int a, int b, int c, int d, int e, int f) {
    
    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++) {
            
            if (a * i + b * j == c && d * i + e * j == f) {
                cout << i << " " << j << "\n";
                break;
            }
            
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c, d, e, f;
    
    // 입력
    cin >> a >> b >> c >> d >> e >> f;
    
    // 출력
    solution(a, b, c, d, e, f);
    
    return 0;
}