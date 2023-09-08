#include <iostream>
#include <cmath>

using namespace std;

void cantor(int N) {
    if (N == 0) {
        cout << "-";
        return;
    }
    
    int num = pow(3, N);
    cantor(N-1);
    for (int j=0; j<num/3; j++)
        cout << " ";
    cantor(N-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    // 입력
    int N;
    
    // 연산 및 출력
    while (cin >> N) {
        cantor(N);
        cout << "\n";
    }
        
    return 0;
}
