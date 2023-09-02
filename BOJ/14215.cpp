#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v(3, 0);
    
    // 입력
    for (int i=0; i<3; i++)
        cin >> v[i];
    
    // 출력
    sort(v.begin(), v.end());
    
    if (v[2] < v[1] + v[0]) {
        cout << v[0] + v[1] + v[2];
        return 0;
    }
    
    v[2] = v[1] + v[0] - 1;
    
    cout << v[0] + v[1] + v[2];
    
    return 0;
}