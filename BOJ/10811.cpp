#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> v, tmp;
    int N, M, a, b;
    
    // 입력 및 출력
    cin >> N >> M;
    for (int i=0; i<=N; i++) {
        v.push_back(i);
    }

    while (M--) {
        cin >> a >> b;
        
        if (a == b)
            continue;
        
        reverse(v.begin()+a, v.begin()+b+1);
    }
    
    for (int i=1; i<=N; i++)
        cout << v[i] << " ";
    
    return 0;
    
}