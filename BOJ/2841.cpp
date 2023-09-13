#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<stack<int>> st(7, stack<int>());

int numOfMove(int line, int fret) {
    int move = 0;

    if (st[line].empty()) {
        st[line].push(fret);
        return 1;
    }
    
    int top = st[line].top();
    while (top > fret) {
        st[line].pop();
        move++;
        if (!st[line].empty()) {
            top = st[line].top();
        }
        else
            break;
    }
            
    if (st[line].empty()) {
        st[line].push(fret);
        move++;
        return move;
    }
    top = st[line].top();
    if (top < fret) {
        st[line].push(fret);
        move++;
    }
    
    return move;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, P;
    cin >> N >> P;
    
    // 연산 & 출력
    int line, fret;
    int ans = 0;
    while (N--) {
        cin >> line >> fret;
        //cout << numOfMove(line, fret) << " ";
        ans += numOfMove(line, fret);
    }
    
    cout << ans << '\n';
    
    return 0;
}