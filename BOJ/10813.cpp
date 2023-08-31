#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> balls;
    int N, M, a, b;
    
    // 입력 및 출력
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        balls.push_back(i);
    
    int tmp;
    while (M--) {
        cin >> a >> b;
        
        if (a == b)
            continue;
            
        a--;
        b--;
        
        swap(balls[a], balls[b]);
    }
    
    for (int b : balls)
        cout << b << " ";
        
    return 0;
    
}