#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int A, B, input;
    unordered_set<int> s;
    cin >> A >> B; 
    
    for (int i=0; i<A; i++) {
        cin >> input;
        s.insert(input);
    }
    
    // 연산 및 출력
    int common = 0;
    for (int i=0; i<B; i++) {
        cin >> input;
        // 중복
        if (s.find(input) != s.end())
            common++;
    }
    
    cout << A + B - common * 2;
    
    return 0;
}

