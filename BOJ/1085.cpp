#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x, y, w, h;
    
    // 입력
    cin >> x >> y >> w >> h;
    
    // 출력
    int x_diff = w - x;
    int y_diff = h - y;
    
    cout << min({x, y, x_diff, y_diff});
    
    return 0;
}