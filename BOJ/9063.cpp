#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, x, y;
    vector<int> xs;
    vector<int> ys;
    
    // 입력
    cin >> N;
    
    // 출력
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
    }
    
    if (N == 1) {
        cout << 0;
        return 0;
    }
    
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    
    int x_min = xs[0];
    int x_max = xs[xs.size() -1];
    int y_min = ys[0];
    int y_max = ys[ys.size() -1];
    
    cout << (x_max - x_min) * (y_max - y_min);
    
    return 0;
}