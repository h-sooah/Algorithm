#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num;
    
    // 입력
    cin >> num;
    
    // 출력
    for (int i=1; i<=num; i++) {
        for (int j=0; j<num-i; j++)
            cout << " ";
        for (int j=0; j<2*i-1; j++)
            cout << "*";
        cout << "\n";
    }
    
    for (int i=1; i<=num; i++) {
        for (int j=0; j<i; j++)
            cout << " ";
        for (int j=0; j<2*(num-i)-1; j++)
            cout << "*";
        cout << "\n";
    }
}