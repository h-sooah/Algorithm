#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    int cmd;
    priority_queue<int> max_heap;
    while (N--) {
        cin >> cmd;
        
        if (cmd == 0) {
            
            if (max_heap.empty())
                cout << 0 << '\n';
            else {
                cout << max_heap.top() << '\n';
                max_heap.pop(); 
            }
            
        } else {
            max_heap.push(cmd);
        }
        
    }
    
    return 0;
}