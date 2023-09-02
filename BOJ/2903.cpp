#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    // 입력
    cin >> N;
    
    // 연산 및 출력
    int num = 2, add = 1;
    for (int i=0; i<N; i++) {
        num += add;
        add *= 2;
    }
    
    cout << num * num;
    
    return 0;
}