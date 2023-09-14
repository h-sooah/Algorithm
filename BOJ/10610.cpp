#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    string s;
    cin >> s;
    
    sort(s.begin(), s.end(), greater<>());
    
    // 제일 끝에 있는 숫자가 0인지 확인
    if (s[s.size() - 1] != '0') {
        cout << -1 << '\n';
        return 0;
    }
        
    int sum = 0;
    for (int i=0; i<s.size()-1; i++)
        sum += s[i] - '0';
    
    if (sum % 3 == 0)
        cout << s << '\n';
    else
        cout << -1 << '\n';
    
    return 0;
}
