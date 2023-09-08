#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T;
    cin >> T;

    // 연산 및 출력
    string s, rs;
    int cnt;
    while (T--) {
        cin >> s;

        rs = s;
        cnt = 1;
        reverse(rs.begin(), rs.end());
        
        for (int i=0; i<s.size()/2; i++) {

            if (i == (s.size()-i-1)) {
                cnt++;
                break;
            }
            
            if (s[i] == s[s.size() - i - 1])
                cnt++;
            else
                break;
        }
        
        if (rs == s)
            cout << 1 << " " << cnt << "\n";
        else
            cout << 0 << " " << cnt << "\n";
    }
        
    return 0;
}
