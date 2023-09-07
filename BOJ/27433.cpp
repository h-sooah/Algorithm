#include <iostream>

using namespace std;

long long fact(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;

    // 연산 및 출력
    cout << fact(N);
        
    return 0;
}
