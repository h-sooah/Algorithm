#include <iostream>
#include <vector>

using namespace std;

void solution(int N) {
    if (N == 1)
        return;
        
    int i = 2;
    while (N != 1) {
        if (N % i == 0) {
            N /= i;
            cout << i << "\n";
        }
        else {
            i++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    solution(N);
    
    return 0;
}