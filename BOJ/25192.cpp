#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    string str;
    set<string> s;
    int cnt = 0;
    while (N--) {
        cin >> str;
        
        if (str == "ENTER") {
            s.clear();
            continue;
        }
        
        if (s.find(str) == s.end()) {
            s.insert(str);
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
