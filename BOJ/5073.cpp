#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b, c;
    
    // 입력 및 출력
    while (true) {
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0)
            break;
            
        // 삼각형 조건 만족 못 하는 경우
        int max_num = max({a, b, c});
        int sum = 0;
        if (max_num == a) sum += (b + c);
        else if (max_num == b) sum += (a + c);
        else if (max_num == c) sum += (a + b);
        
        if (max_num >= sum) {
            cout << "Invalid\n";
            continue;
        }
        
        // 세 변의 길이가 모두 같은 경우
        if (a == b && b == c && c == a) {
            cout << "Equilateral\n";
            continue;
        }
        
        // 두 변의 길이만 같은 경우
        if (a == b || b == c || c == a) {
            cout << "Isosceles\n";
            continue;
        }
        
        // 세 변의 길이가 모두 다른 경우
        cout << "Scalene\n";
    }
    
    return 0;
}