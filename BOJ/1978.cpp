#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkNum(int num) {
    bool result = true;
    
    if (num == 1) {
        result = false;
        return result;
    }
    
    for (int i=2; i<num; i++) {
        // 소수가 아니면
        if (num % i == 0) {
            result = false;
            break;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, num;
    
    // 입력
    cin >> T;
    
    // 연산 및 출력
    int cnt = 0;
    while (T--) {
        cin >> num;
        
        if (checkNum(num))
            cnt++;
    }
    
    cout << cnt;
    
    return 0;
}