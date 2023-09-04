#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    int num;
    vector<int> v;
    while (N--) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    // 연산 및 출력
    for (int i : v) {
        cout << i << "\n";
    }
    
    return 0;
}