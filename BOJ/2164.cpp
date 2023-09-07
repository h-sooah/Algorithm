#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    deque<int> deque;
    int N, num;
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        deque.push_back(i);
    }
    
    // 연산 및 출력
    while (deque.size() != 1) {
        deque.pop_front();
        num = deque.front();
        deque.pop_front();
        deque.push_back(num);
    }
    
    cout << deque.front();
    
    return 0;
}