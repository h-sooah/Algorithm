#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, input;
    cin >> N;
    
    deque<int> dq;
    for (int i=1; i<=N; i++)
        dq.push_back(i);
    
    vector<int> in_ballon(N+1, 0);
    for (int i=1; i<=N; i++) {
        cin >> in_ballon[i];
    }
    
    // 연산 및 출력
    int move = 1;
    while (!dq.empty()) {
        
        // 양수 방향으로 움직일 때
        if (move > 0) {
            for (int i=1; i<move; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            move = in_ballon[dq.front()];
            cout << dq.front() << " ";
            dq.pop_front();
        }
        // 음수 방향으로 움직일 때
        else {
            move = -move;
            for (int i=1; i<move; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            move = in_ballon[dq.back()];
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    
    return 0;
}