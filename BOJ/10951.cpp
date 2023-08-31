#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b;
    
    // 입력 및 출력
    while (!(cin >> a >> b).eof()) {
        cout << a + b << "\n";
    }
   
    
    return 0;
    
}