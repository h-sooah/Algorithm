#include <iostream>
#include <string>

using namespace std;

bool isGroup(string s) {
    bool result = true;
    
    bool alpha[26] = { false };
    
    for (int i=0; i<s.size(); i++) {
        if (i != 0 && s[i] == s[i-1])
            continue;
        
        if (alpha[s[i] - 'a'] == false)
            alpha[s[i] - 'a'] = true;
        else {
            result = false;
            break;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    int cnt = 0;
    while (N--) {
        cin >> s;
        
        if (isGroup(s))
            cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
}