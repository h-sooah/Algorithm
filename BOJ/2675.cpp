#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string S;
    int R, T;
    
    // 입력
    cin >> T;
    
    // 출력
    while (T--) {
        cin >> R >> S;
        
        for (int i=0; i<S.size(); i++) {
            for (int j=0; j<R; j++)
                cout << S[i];
        } 
        
        cout << "\n";
    }
    
    return 0;
    
}