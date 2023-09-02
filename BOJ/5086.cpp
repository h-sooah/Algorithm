#include <iostream>

using namespace std;

string getClimbingDay(int a, int b) {
    
    if (a == 0 || b == 0)
        return "neither";
        
    if (a > b) {
        if (a % b == 0)
            return "multiple";
        else
            return "neither";
    }
    else {
        if (b % a == 0)
            return "factor";
        else
            return "neither";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b;
    
    // 입력 및 연산 및 출력
    while (true) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        cout << getClimbingDay(a, b) << "\n";
    }
    
    return 0;
}