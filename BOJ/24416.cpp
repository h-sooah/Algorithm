#include <iostream>

using namespace std;

int cnt = 0;

int fib(int n) {
    if (n ==1 || n == 2) {
        cnt++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 연산 및 출력
    int dp = n - 2;
    
    fib(n);
    
    cout << cnt << " " << dp;
    return 0;
}