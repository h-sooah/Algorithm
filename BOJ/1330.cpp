#include <iostream>

using namespace std;

int main() {
    
    int a, b;
    
    // 입력
    cin >> a >> b;
    
    // 출력
    if (a > b)
        cout << ">" << "\n";
    else if (a < b)
        cout << "<" << "\n";
    else
        cout << "==";
    
}