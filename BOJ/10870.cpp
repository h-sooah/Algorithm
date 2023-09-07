#include <iostream>

using namespace std;

int fibo(int num) {
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return fibo(num-1) + fibo(num-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;

    // 연산 및 출력
    cout << fibo(N);
        
    return 0;
}
