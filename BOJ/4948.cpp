#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력 및 연산 및 출력
    int num, cnt, root;
    while (true) {
        cin >> num;
        
        if (num == 0)
            break;
        
        cnt = 0;
        
        for (int i=num+1; i<=2*num; i++) {
            root = sqrt(i);
            // num = 2, 3
            if (root == 1) {
                cnt++;
                continue;
            }
            
            // num = 홀수
            if (i % 2 != 0) {
                for (int j=2; j<=root; j++) {
                    if (i % j == 0)
                        break;
                    if (j == root)
                        cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}

