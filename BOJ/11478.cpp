#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    unordered_set<string> s;
    string str, tmp;
    cin >> str;
    
    // 연산 및 출력
    for (int i=0; i<str.size(); i++) {
        tmp = "";
        for (int j=i; j<str.size(); j++) {
            tmp += str[j];
            s.insert(tmp);
        }
    }
    
    cout << s.size();
    
    return 0;
}