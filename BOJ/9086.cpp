#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    string s;
    
    // 입력 및 출력
    cin >> T;
    
    while (T--) {
        cin >> s;
        int size = s.size() - 1;
        
        cout << s[0] << s[size] << "\n";
    }
    
    return 0;
    
}