#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getAlarmTime(int H, int M) {
    
    pair<int, int> result;
    
    // M >= 45 인 경우 -> 시간 계산 필요 X
    if (M >= 45) {
        M -= 45;
        result.first = H;
        result.second = M;
    }
    // M < 45 인 경우 -> 시간 계산 필요 O
    else {
        // 계산하기 쉽게 0 -> 24로 변경
        if (H == 0)
            H = 24;
            
        H -= 1;
        M += 15; // +60분, -45분
        
        result.first = H;
        result.second = M;
    }
    return result;
}

int main() {
    
    int H, M;
    
    // 입력
    cin >> H >> M;
    
    pair<int, int> p = getAlarmTime(H, M);
    
    // 연산 및 출력
    cout << p.first << " " << p.second << "\n";
    
}