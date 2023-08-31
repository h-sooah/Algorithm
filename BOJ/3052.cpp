#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    set<int> s;
    int num;
    
    // 입력 및 출력
    for (int i=0; i<10; i++) {
        cin >> num;
        num %= 42;
        s.insert(num);
    }
    
    cout << s.size();
    
    return 0;
    
}