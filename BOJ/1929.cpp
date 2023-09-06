#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int M, N;
    cin >> M >> N;
    
    // 연산 및 출력
    for (int i=M; i<=N; i++) {
        if (i == 1)
            continue;
        else {
            if (isPrime(i))
                cout << i << "\n";
        }
    }
    
    return 0;
}

