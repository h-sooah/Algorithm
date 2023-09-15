#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e5;

vector<int> prime(MAX+1, 0);
vector<int> exponent(MAX+1, 0);

void isPrime() {
    for (int i=2; i*i<=MAX; i++) {
        if (prime[i] != 0)
            continue;
        for (int j=i*i; j<=MAX; j+=i) {
            if (prime[j] == 0)
                prime[j] = i;
        }
    }
}

void countExponent(int n, int cnt) {
    while (prime[n]) {
        exponent[prime[n]] += cnt;
        n /= prime[n];
    }
    exponent[n] += cnt;
}

bool isRational() {
    for (int i=2; i<=MAX; i++) {
        if (exponent[i] < 0)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 에라토스테네스
    isPrime();
    
    // 첫 번째 수 입력
    int num;
    char oper;
    cin >> num;
    
    // 곱하는 수가 0이면 더 계산할 필요 없음
    if (num == 0) {
        cout << "mint chocolate\n";
        return 0;
    }
    
    countExponent(abs(num), 1); // 첫 번째 수는 곱하기
    
    for (int i=1; i<N; i++) {
        cin >> oper >> num;
        
        if (num == 0) {
            cout << "mint chocolate\n";
            return 0;
        }
        
        if (oper == '*')
            countExponent(abs(num), 1);
        else
            countExponent(abs(num), -1);
    }
    
    if (isRational())
        cout << "toothpaste\n";
    else
        cout << "mint chocolate\n";
    
    return 0;
}