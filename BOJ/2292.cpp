#include <iostream>
#include <vector>

using namespace std;

int getMinRoom(int N) {
    if (N == 1)
        return 1;
    
    int num = 1, add = 6, cnt = 1;
    while (true) {
        num += add;
        cnt++;
        
        if (N <= num) {
            return cnt;
        }
        
        add += 6;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    cout << getMinRoom(N);
    
    return 0;
}