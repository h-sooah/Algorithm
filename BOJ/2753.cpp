#include <iostream>

using namespace std;

int getYearType(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 1;
    return 0;
}

int main() {
    
    int year;
    
    // 입력
    cin >> year;
    
    // 연산 및 출력
    cout << getYearType(year) << "\n";
    
}