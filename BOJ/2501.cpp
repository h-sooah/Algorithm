#include <iostream>

using namespace std;

int solution(int a, int b) {
    
    int flag = 0;
    
    for (int i=1; i<=a; i++) {
        if (a % i == 0)
            flag++;
            
        if (flag == b)
            return i;
    }
    
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b;
    
    // 입력
    cin >> a >> b;
    
    // 연산 및 출력
    cout << solution(a, b);
    
    return 0;
}