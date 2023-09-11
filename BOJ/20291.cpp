#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N;
    cin >> N;
    map<string, int> m;
    
    // 연산 & 출력
    string input;
    while (N--) {
        cin >> input;
        
        input = input.substr(input.find(".")+1);
        
        if (m.find(input) != m.end())
            m[input]++;
        else
            m[input] = 1;
    }
    
    for (auto it=m.begin(); it!=m.end(); it++)
        cout << it->first << " " << it->second << '\n';
    
    return 0;
}
