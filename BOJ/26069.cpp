#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N;
    cin >> N;
    
    // 연산 및 출력
    string A, B;
    bool flag = false, A_status, B_status, A_dance, B_dance;
    map<string, bool> m;

    while (N--) {
        cin >> A >> B;
        
        // 초기화
        A_status = false;
        B_status = false;
        A_dance = false;
        B_dance = false;
        
        if (A == "ChongChong") {
            m.insert({A, true});
            flag = true;
        }
        if (B == "ChongChong") {
            m.insert({B, true});
            flag = true;
        }
            
        // 총총이 나오기 전
        if (!flag) {
            m.insert({A, false});
            m.insert({B, false});
        }
        // 총총이 나온 후
        else {
            if (m.find(A) != m.end()) {
                A_dance = m[A];
                A_status = true;
            }
            if (m.find(B) != m.end()) {
                B_dance = m[B];
                B_status = true;
            }
                
            // 춤 전파하기
            if (A_dance)
                B_dance = true;
            if (B_dance)
                A_dance = true;
            
            if (A_status) {
                m[A] = A_dance;
            } else {
                m.insert({A, A_dance});
            }
            
            if (B_status) {
                m[B] = B_dance;
            } else {
                m.insert({B, B_dance});
            }
            
        }
    }
    
    int cnt = 0;
    for (auto it=m.begin(); it!=m.end(); it++) {
        if (it -> second == 1)
            cnt++;
    }
    
    cout << cnt;
    
    return 0;
}
