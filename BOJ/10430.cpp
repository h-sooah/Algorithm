#include <iostream>

using namespace std;

int main() {
    
    int A, B, C;
    
    // 입력
    cin >> A >> B >> C;
    
    // 출력
    cout << (A + B) % C << "\n";
    cout << ((A % C) + (B % C)) % C << "\n";
    cout << (A * B) % C << "\n";
    cout << ((A % C) * (B % C)) % C << "\n";
    
    return 0;
    
}