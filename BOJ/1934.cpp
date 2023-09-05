#include <iostream>

using namespace std;

int getMinMulti(int A, int B) {
    
    // 일단 둘 중 하나 1일 때
    if (A == 1 || B == 1)
        return A * B;
    
    // 작은 수 정하기: A
    if (B > A) {
        int tmp = A;
        A = B;
        B = tmp;
    }
    
    // 최대 공약수 찾기: O(N)
    int common = 1;
    for (int i=2; i<=A; i++) {
        if (A % i == 0 && B % i == 0)
            common = i;
    }
    
    A /= common;
    B /= common;
    
    return common * A * B;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, A, B;
    cin >> T;
    
    // 연산 및 출력
    while (T--) {
        cin >> A >> B;
        cout << getMinMulti(A, B) << "\n";
    }
    
    return 0;
}

