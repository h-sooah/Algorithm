#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int T, n;
    cin >> T;
    
    // 연산 & 출력
    string name, type;
    while (T--) {
        map<string, int> m;
        cin >> n;
        while (n--) {
            cin >> name >> type;
            m[type]++;
        }
        
        int result = 1;
        for (auto it=m.begin(); it!=m.end(); it++)
            result *= (it->second + 1);
        
        cout << result - 1 << '\n';
    }
    
    return 0;
}
