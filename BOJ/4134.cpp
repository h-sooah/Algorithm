#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrimeNum(long long n) {
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
    int T;
    cin >> T;
    
    // 연산 및 출력
    long long n;
    for (int i = 0; i < T; i++) {
        cin >> n;

        if (n >= 0 && n <= 2)
            cout << 2 << "\n";
        else if (n == 3)
            cout << 3 << "\n";
        else {
            while (!isPrimeNum(n))
                n++;
            cout << n << "\n";
        }
    }
    
    return 0;
}

