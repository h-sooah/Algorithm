#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> balls;
    int N, M, a, b, c;
    
    // 입력 및 출력
    cin >> N >> M;
    balls.assign(N, 0);
    
    while (M--) {
        cin >> a >> b >> c;
        
        for (int i=a-1; i<b; i++) {
            balls[i] = c;
        }
    }
    
    for (int b : balls)
        cout << b << " ";
        
    return 0;
    
}