#include <iostream>

using namespace std;

int main() {

    int X, N, a, b;
    
    // 입력
    cin >> X >> N;
    
    // 연산 및 출력
    int sum = 0;
    while (N--) {
        cin >> a >> b;
        sum += (a * b);
    }
    
    if (sum == X)
        cout << "Yes";
    else
        cout << "No";
    
    return 0;
    
}