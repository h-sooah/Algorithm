#include <iostream>
#include <cmath>

using namespace std;

int solution(int N, int K) {
    if (N == K || K == 0)
        return 1;
    else
        return solution(N-1, K-1) + solution(N-1, K);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, K;
    cin >> N >> K;
    
    // 연산 및 출력
    cout << solution(N, K);
    
    return 0;
}
