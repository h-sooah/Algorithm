#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M, input;
    deque<int> dq;
    
    cin >> N;
    
    vector<int> v(N, 1);
    for (int i=0; i<N; i++) {
        cin >> input;
        if (input == 0)
            v[i] = 0;
    }
    
    for (int i=0; i<N; i++) {
        cin >> input;
        if (v[i] == 0)
            dq.push_back(input);
    }
    
    cin >> M;
    
    // 연산 및 출력
    for (int i=0; i<M; i++) {
        cin >> input;
        
        dq.push_front(input);
        cout << dq.back() << " ";
        dq.pop_back();
    }
    
    return 0;
}