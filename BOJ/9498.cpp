#include <iostream>

using namespace std;

int main() {
    
    int grade;
    
    // 입력
    cin >> grade;
    
    if (grade >= 90) {
        cout << "A";
        return 0;
    }
    
    if (grade >= 80) {
        cout << "B";
        return 0;
    }
    
    if (grade >= 70) {
        cout << "C";
        return 0;
    }
    
    if (grade >= 60) {
        cout << "D";
        return 0;
    }
    
    cout << "F";
    return 0;
    
}