#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    deque<int> dq;
    int N, option, input;
    cin >> N;
        
    // 연산 및 출력
    while (N--) {
        cin >> option;
        
        switch (option) {
            case 1:
                cin >> input;
                dq.push_front(input);
                continue;
            case 2:
                cin >> input;
                dq.push_back(input);
                continue;
            case 3:
                if (!dq.empty()) {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
                else 
                    cout << -1 << "\n";
                continue;
            case 4:
                if (!dq.empty()) {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
                else 
                    cout << -1 << "\n";
                continue;
            case 5:
                cout << dq.size() << "\n";
                continue;
            case 6:
                cout << dq.empty() << "\n";
                continue;
            case 7:
                if (!dq.empty()) 
                    cout << dq.front() << "\n";
                else 
                    cout << -1 << "\n";
                continue;
            case 8:
                if (!dq.empty()) 
                    cout << dq.back() << "\n";
                else 
                    cout << -1 << "\n";
                continue;
        }
    }
    
    return 0;
}