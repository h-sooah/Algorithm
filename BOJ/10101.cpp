#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    
    // 입력
    cin >> a >> b >> c;
    
    // 출력
    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral";
        return 0;
    }
    
    if (a + b + c != 180) {
        cout << "Error";
        return 0;
    }
    
    if (a == b || b == c || c == a) {
        cout << "Isosceles";
        return 0;
    }
    
    cout << "Scalene";
    
    return 0;
}