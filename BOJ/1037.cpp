#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, input;
    vector<int> v;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        cin >> input;
        v.push_back(input);
    }
    
    // 연산 및 출력
    if (N == 1) {
        cout << v[0] * v[0] << "\n";
        return 0;
    }
    
    sort(v.begin(), v.end());
    
    cout << v[0] * v[v.size() - 1] << "\n";
    
    return 0;
}
