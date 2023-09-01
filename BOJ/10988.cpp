#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s1, s2;
    
    // 입력
    cin >> s1;
    
    // 출력
    s2 = s1;
    reverse(s2.begin(), s2.end());
    
    if (s1 == s2)
        cout << 1 << "\n";
    else 
        cout << 0 << "\n";
        
    return 0;
}