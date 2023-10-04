#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int n, a, tmp;
    cin >> n;
    
    priority_queue<int> pq;
    
    while (n--) {
        cin >> a;
        
        // 아이들을 만날 때
        if (a == 0) {
            if (pq.empty())
                cout << -1 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // 거점지에서
        else {
            while (a--) {
                cin >> tmp;
                pq.push(tmp);
            }
        }
    }
    
    return 0;
}