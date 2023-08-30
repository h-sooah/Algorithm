#include <iostream>

using namespace std;

int main() {
    
    int num1, num2;
    
    // 입력
    cin >> num1 >> num2;
    
    int hun = num2 / 100;
    int ten = (num2 % 100) / 10;
    int one = (num2 % 100) % 10;
    
    // 출력
    cout << num1 * one << "\n";
    cout << num1 * ten << "\n";
    cout << num1 * hun << "\n";
    cout << num1 * num2 << "\n";
    
    return 0;
    
}