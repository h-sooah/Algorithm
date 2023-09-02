#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    
    // 입력
    cin >> n;
    
    // 출력
    long long sum = 0;
    sum += (2 * n); // 가로 길이
    sum += (2 * n); // 세로 길이
    
    cout << sum;
    
    return 0;
}