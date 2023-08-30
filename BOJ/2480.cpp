#include <iostream>
#include <algorithm>

using namespace std;

int calPrize(int a, int b, int c) {
    
    int result;
    
    // 같은 눈 3개
    if (a == b && b == c) {
        result = 10000 + a * 1000;
        return result;
    }
    
    // 같은 눈 2개
    if (a == b || b == c || c == a) {
        int num;
        if (a == b)
            num = a;
        else if (b == c)
            num = b;
        else if (c == a)
            num = c;
        
        result = 1000 + num * 100;
        return result;
    }
    
    // 모두 다른 눈
    int num = max({a, b, c});
    result = num * 100;
    return result;
    
}

int main() {

    int a, b, c;
    
    // 입력
    cin >> a >> b >> c;
    
    // 연산 및 출력
    cout << calPrize(a, b, c);
    
}