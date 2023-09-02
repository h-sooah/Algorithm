#include <iostream>
#include <vector>

using namespace std;

bool checkNum(int num) {
    bool result = true;
    
    if (num == 1) {
        result = false;
        return result;
    }
    
    for (int i=2; i<num; i++) {
        // 소수가 아니면
        if (num % i == 0) {
            result = false;
            break;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int min, max;
    vector<int> v;
    
    // 입력
    cin >> min >> max;
    
    // 연산 및 출력
    for (int i=min; i<=max; i++) {
        if (checkNum(i))
            v.push_back(i);
    }
    
    if (v.empty())
        cout << -1;
    else {
        int sum = 0;
        for (int i : v)
            sum += i;
        
        cout << sum << "\n";
        cout << v[0] << "\n";
    }
    
    return 0;
}