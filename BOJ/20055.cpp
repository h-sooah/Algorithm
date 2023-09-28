#include <iostream>
#include <deque>

using namespace std;

int findProgressLevel(deque<int> &belt, int K, int N) {
    
    deque<bool> robot(N, false);
    int cnt = 0;
    int level = 0;
    
    while (cnt < K) {
        level++;
        
        // 로봇 & 벨트 한 칸씩 회전
        robot.pop_back();
        robot.push_front(false);
        belt.push_front(belt.back());
        belt.pop_back();

        
        // 내리는 위치에 있으면 내려주기
        robot[N-1] = false;
        
        // 로봇 이동
        for (int i = N-2; i >= 0; i--) {
            
            if (robot[i] == false)
                continue;
            
            if (robot[i+1] == true || belt[i+1] == 0)
                continue;
            
            robot[i+1] = true;
            robot[i] = false;
            belt[i+1]--;
            
            if (belt[i+1] == 0)
                cnt++;
        }
        
        
        // 로봇 올려주기
        if (belt[0] != 0) {
            robot[0] = true;
            belt[0]--;
            
            if (belt[0] == 0)
                cnt++;
        }
        
    }
    
    return level;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, K;
    cin >> N >> K;
    
    int input;
    deque<int> belt;
    for (int i=0; i<2*N; i++) {
        cin >> input;
        belt.push_back(input);   
    }
    
    cout << findProgressLevel(belt, K, N);

    return 0;
}