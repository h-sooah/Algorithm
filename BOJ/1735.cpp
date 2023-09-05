#include <iostream>

using namespace std;

// 최대 공약수 구하기: 유클리드 호제법
int divide(int A, int B) {
    if (A % B == 0)
        return B;
    else
        return divide(B, A % B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    
    // 연산 및 출력
    // 1. 일단 더하기: 분모 일단 곱해
    int B = b1 * b2;
    int A = a1 * b2 + a2 * b1;
    
    // 2. 기약분수 만들기
    int common;
    if (A > B)
        common = divide(A, B);
    else
        common = divide(B, A);
    
    cout << A / common << " " << B / common;
    
    return 0;
}

