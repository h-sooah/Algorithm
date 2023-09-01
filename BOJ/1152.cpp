#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    
    // 입력
    getline(cin, s);
    
    // 출력
    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ')
            cnt++;
    }
    
    if (s[s.size() - 1] != ' ')
        cnt++;
        
    if (s[0] == ' ')
        cnt--;
    
    cout << cnt << "\n";
    return 0;
    
}