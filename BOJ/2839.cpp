#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinBag(int N) {
    
    int fives = N / 5, num, cnt;
    
    while (fives >= 0) {
        
        num = N;
        cnt = 0;
        num -= 5 * fives;
        cnt += fives;
        
        while (num > 0) {
            num -= 3;
            cnt++;
        }
        
        if (num == 0)
            return cnt;
        else
            fives--;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    cout << getMinBag(N);
    
    return 0;
}