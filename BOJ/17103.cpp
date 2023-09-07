#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_NUM = 1000001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int T, input, cnt;
    cin >> T;
    
    // 먼저 채워놓기
    vector<bool> primes(MAX_NUM, false);
    for (int i=2; i<=sqrt(MAX_NUM); i++) {
        // 이미 true -> pass
        if (primes[i])
            continue;
        // 배수 체크해주기
        for (int j=2*i; j<=MAX_NUM; j+=i)
            primes[j] = true;
    }
    
    // 연산 및 출력
    while (T--) {
        cin >> input;
        
        // 개수 초기화
        cnt = 0; 
        
        // 대칭 -> 반만 검사
        for (int i=2; i<=input/2; i++) {
            // 소수 아님 -> pass
            if (primes[i]) 
                continue;
            
            // 나머지도 소수
            if (!primes[input-i])
                cnt++;
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}