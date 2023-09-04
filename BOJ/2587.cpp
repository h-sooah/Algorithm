#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    vector<int> v(5, 0);
    int sum = 0;
    for (int i=0; i<5; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    sort(v.begin(), v.end());
    
    // 연산 및 출력
    cout << sum / 5 << "\n" << v[2];
    
    return 0;
}