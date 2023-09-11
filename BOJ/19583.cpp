#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    string S, E, Q, time, nickname;
    cin >> S >> E >> Q;
    
    // 연산 & 출력
    map<string, bool> attend;
    while (cin >> time >> nickname) {
        
        // 개총 시작 전
        if (time <= S)
            attend[nickname] = false;
            
        // 개총 끝난 후
        else if (time >= E && time <= Q) {
            if (attend.find(nickname) != attend.end())
                attend[nickname] = true;
        } 
    }
    
    int sum = 0;
    for (auto it=attend.begin(); it!=attend.end(); it++) {
        if (it->second == true)
            sum++;
    }
    
    cout << sum << '\n';
    
    return 0;
}
