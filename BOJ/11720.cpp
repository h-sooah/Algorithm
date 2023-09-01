#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    int N;
    
    // 입력
    cin >> N >> s;
    
    // 출력
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum += ( s[i] - '0' );
    }
    
    cout << sum << "\n";
    
    return 0;
    
}