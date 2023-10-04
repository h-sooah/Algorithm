#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int &a, const int &b) {
        if (abs(a) != abs(b))
            return abs(b) < abs(a);
        
        return b < a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    //입력
    int N, x;
    cin >> N;
    
    priority_queue<int, vector<int>, cmp> pq;
    while (N--) {
        cin >> x;
        
        if (x == 0) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    
    return 0;
}