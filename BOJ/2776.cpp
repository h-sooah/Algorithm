#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int T, N, M, input;
    cin >> T;
    
    // 연산 & 출력
    while (T--) {
        cin >> N;
        
        unordered_set<int> s;
        
        for (int i=0; i<N; i++) {
            cin >> input;
            s.insert(input);
        }
        cin >> M;
        while (M--) {
            cin >> input;
            if (s.find(input) != s.end())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
            
        
    }
    
    
    return 0;
}
