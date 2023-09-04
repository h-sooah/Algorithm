#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int getNumber(int N) {
    int cnt = 0, i = 665;
    string s;
    while (cnt != N) {
        i++;
        s = to_string(i);
        if (s.find("666") != string::npos) {
            cnt++;
        }   
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    cout << getNumber(N);
    
    return 0;
}