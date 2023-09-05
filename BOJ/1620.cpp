#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

bool isNumber(string s) {
    bool result = true;
    
    for (int i=0; i<s.size(); i++) {
        if (!isdigit(s[i])) {
            result = false;
            break;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M;
    cin >> N >> M;
    
    map<string, int> map_name;
    map<int, string> map_number;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        map_name.insert({s, i});
        map_number.insert({i, s});
    }
    
    // 연산 및 출력
    while (M--) {
        cin >> s;
        if (isNumber(s))
            cout << map_number[stoi(s)] << "\n";
        else
            cout << map_name[s] << "\n";
    }
    
    return 0;
}


