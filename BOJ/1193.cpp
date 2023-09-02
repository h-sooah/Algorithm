#include <iostream>
#include <vector>

using namespace std;

void calResult(int N) {
    if (N == 1) {
        cout << "1/1";
        return;
    }
    
    int a, b;
    int num = 1, add = 2;
    while (true) {
        
        num += add;
        
        if (N <= num) {
            int diff = num - N;
            
            if (add % 2 == 0) {
                a = (add - diff);
                b = (1 + diff);
            }
            else {
                a = (1 + diff);
                b = (add - diff);
            }
            
            break;
        }
        
        add++;
    }
    
    cout << a << "/" << b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    calResult(N);
    
    return 0;
}