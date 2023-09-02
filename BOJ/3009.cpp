#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x1, y1, x2, y2, x3, y3, x, y;
    
    // 입력
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    // 출력
    if (x1 == x2)
        x = x3;
    else if (x2 == x3)
        x = x1;
    else if (x3 == x1)
        x = x2;
        
        
    if (y1 == y2)
        y = y3;
    else if (y2 == y3)
        y = y1;
    else if (y3 == y1)
        y = y2;
        
    cout << x << " " << y;
    
    return 0;
}