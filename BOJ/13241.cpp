#include <iostream>

using namespace std;

// 최대 공약수 구하기: 유클리드 호제법
long long divide(long long A, long long B) {
    if (A % B == 0)
        return B;
    else
        return divide(B, A % B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    long long A, B;
    cin >> A >> B;
    
    // 연산 및 출력
    long long common;
    if (A > B)
        common = divide(A, B);
    else
        common = divide(B, A);
    
    cout << A * B / common;
    
    return 0;
}

