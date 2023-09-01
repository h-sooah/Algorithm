#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s1, s2;
    int a, b;
    
    // 입력
    cin >> s1 >> s2;
    
    // 출력
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    
    a = stoi(s1);
    b = stoi(s2);
    
    if (a >= b)
        cout << a << "\n";
    else
        cout << b << "\n";
    
    return 0;
    
}