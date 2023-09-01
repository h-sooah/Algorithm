#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    
    // 입력 및 출력
    while (true) {
        getline(cin, s);
        if (s == "")
            break;
            
        cout << s << "\n";
    }
    
    return 0;
    
}