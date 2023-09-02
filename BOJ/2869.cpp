#include <iostream>
#include <vector>

using namespace std;

int getClimbingDay(int A, int B, int V) {
    
    int result = 0;
    
    // 일단 V-A <- 정상에서 올라간 후 미끄러지지 않는 조건 때문
    V -= A;
    result++;
    
    // 하루에 오를 수 있는 거리 = A - B -> 며칠 오를 수 있는지 계산
    int diff = A - B;
    // 나머지가 있으면 한 번 더 올라야 함
    if (V % diff != 0)
        result++;
        
    result += (V / diff);
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int A, B, V;
    
    // 입력
    cin >> A >> B >> V;
    
    // 연산 및 출력
    cout << getClimbingDay(A, B, V);
    
    return 0;
}