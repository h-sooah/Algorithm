#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    int i;
    
    // 입력
    cin >> s >> i;
    
    // 연산 및 출력
    cout << s[i-1] << "\n";
    
    return 0;
    
}