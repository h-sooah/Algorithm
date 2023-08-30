#include <iostream>

using namespace std;

int main() {

    int n;
    
    // 입력
    cin >> n;
    
    // 연산 및 출력
    int sum = 0;
    while (n) {
        sum += n;
        n--;
    }
    
    cout << sum << "\n";
    
}