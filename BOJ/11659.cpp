#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int n, m, num;
    cin >> n >> m;
    
    vector<int> arr(n + 1, 0); // arr[i]: i까지의 누적 합
    for (int i=1; i<=n; i++) {
        cin >> num;
        arr[i] = arr[i-1] + num;
    }
    
    int start, end;
    while (m--) {
        cin >> start >> end;
        
        cout << arr[end] - arr[start - 1] << '\n';
    }
    
    return 0;
}