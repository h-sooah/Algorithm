#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a1, a0, c, n0;
    
    // 입력
    cin >> a1 >> a0 >> c >> n0;
    
    // 출력
    int fn = a1 * n0 + a0;
	int gn = c * n0;
	(fn <= gn) && (a1 <= c) ? cout << 1 : cout << 0;
    
    return 0;
}