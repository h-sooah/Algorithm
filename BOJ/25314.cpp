#include <iostream>

using namespace std;

int main() {

    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    int num = (N / 4);

    while (num) {
        cout << "long ";
        num--;
    }
    
    cout << "int\n";
    
    return 0;
    
}