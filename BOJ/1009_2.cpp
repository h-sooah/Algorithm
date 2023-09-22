#include <iostream>

using namespace std;

int lastComNumber(int a, int b) {
    
    // a = 1이면 항상 1
    if (a == 1)
        return 1;
    
    // a가 10의 배수이면 항상 10
    if (a % 10 == 0)
        return 10;
        
    int tmp = 1;
    for (int i=1; i<=b; i++) {
        tmp *= a;
        tmp %= 10;
    }
    
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, a, b;
    // 입력
    cin >> T;
    
    while (T--) {
        cin >> a >> b;
        cout << lastComNumber(a, b) << "\n";
    }
    
    return 0;
}