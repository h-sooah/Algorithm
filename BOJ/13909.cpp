#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    long long N;
    cin >> N;
    
    // 연산 및 출력
    long long i = 2;
    while (true) {
        
        if (i * i > N) {
            i--;
            break;
        }
        else if (i * i == N)
            break;
        
        i++;
    }
    
    cout << i << "\n";
    
    return 0;
}