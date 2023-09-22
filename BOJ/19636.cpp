#include <iostream>
#include <cmath>

using namespace std;

// 기초 대사량 변화 고려하지 않았을 때의 다이어트 결과
void dashDiet1(int W0, int I0, int D, int I, int A) {
    
    while (D--) {
        W0 += (I - (I0 + A));
    }
    
    if (W0 <= 0) {
        cout << "Danger Diet\n";
        return;
    }
    
    cout << W0 << ' ' << I0 << "\n";
    
}

void dashDiet2(int W0, int I0, int T, int D, int I, int A) {
    
    int weight = W0; // 변화 체중
    int basic = I0; // 변화 기초 대사량
    int change = I - (basic + A); // 일일 에너지 섭취량 - 일일 에너지 소비량
    
    while (D--) {
        change = I - (basic + A);
        
        // 체중 변화
        weight += change;
        
        // 기초 대사량 변화
        if (abs(change) > T) {
            basic += floor((double) (change) / 2); 
            //c++에서 음수를 나누면 소수점은 그냥 버려지므로 내림함수 적용
            // basic = (int) floor(change/2); : 이렇게 작성하면 틀림
        }
        
        if (weight <= 0 || basic <= 0) {
            cout << "Danger Diet";
            return;
        }
        
        //cout << "weight: " << weight << "\n";
    }
    
    string status;
    if (I0 - basic > 0)
        status = "YOYO";
    else
        status = "NO";
    
    cout << weight << ' ' << basic << ' ' << status << '\n';
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;
    
    dashDiet1(W0, I0, D, I, A);
    
    dashDiet2(W0, I0, T, D, I, A);
    
    return 0;
}