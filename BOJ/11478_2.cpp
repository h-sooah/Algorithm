#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    string str;
    cin >> str;
    
    // 연산 & 출력
    unordered_set<string> s;
    
    for (int i=0; i<str.size(); i++) {
        string substr = "";
        for (int j=i; j<str.size(); j++) {
            substr += str[j];
            s.insert(substr);
        }
    }
    
    cout << s.size() << '\n';
    
    
    return 0;
}
