#include <iostream>
#include <deque>

using namespace std;

deque<int> dodo;
deque<int> su;
deque<int> ground_dodo;
deque<int> ground_su;


// 그라운드의 상단 카드 합이 5
bool isSum5() {
    // 두 그라운드 중 하나라도 비어있으면 false
    if (ground_dodo.empty() || ground_su.empty())
        return false;
        
    int sum = ground_dodo.back() + ground_su.back();
    return sum == 5;
}

// 그라운드 상위 카드 중 하나가 5
bool isCard5() {
    // 그라운드가 비어있지 않고, 상단의 카드가 5이면
    if (!ground_dodo.empty() && ground_dodo.back() == 5)
        return true;
        
    // 그라운드가 비어있지 않고, 상단의 카드가 5이면
    if (!ground_su.empty() && ground_su.back() == 5)
        return true;
        
    return false;
}

bool play(int isDodo) {
    
    if (isDodo == 1) {
        // 도도 카드 내려놓기
        ground_dodo.push_back(dodo.back());
        dodo.pop_back();
    } else {
        // 수연 카드 내려놓기
        ground_su.push_back(su.back());
        su.pop_back();
    }
    // 덱 비었는지 check
    if (dodo.empty()) {
        cout << "su\n";
        return true;
    }
    if (su.empty()) {
        cout << "do\n";
        return true;
    }
    
    // 종 치는 조건 확인
    if (isSum5()) {
        // 수연이가 카드 회수
        // 도도 그라운드 먼저 회수
        while (!ground_dodo.empty()) {
            su.push_front(ground_dodo.front());
            ground_dodo.pop_front();
        }
        // 수연이 그라운드 회수
        while (!ground_su.empty()) {
            su.push_front(ground_su.front());
            ground_su.pop_front();
        }
    }
    
    if (isCard5()) {
        // 도도가 카드 회수
        // 수연이 그라운드 먼저 회수
        while (!ground_su.empty()) {
            dodo.push_front(ground_su.front());
            ground_su.pop_front();
        }
        // 도도 그라운드 회수
        while (!ground_dodo.empty()) {
            dodo.push_front(ground_dodo.front());
            ground_dodo.pop_front();
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int N, M;
    cin >> N >> M;
    
    int a, b;
    while (N--) {
        cin >> a >> b;
        dodo.push_back(a);
        su.push_back(b);
    }
    
    int isDodo = 1; // 1 == 도도 차례, -1 == 수연이 차례
    bool isEnd = false;
    while (M--) {
        isEnd = play(isDodo);
        
        if (isEnd)
            return 0;

        isDodo = -isDodo;
    }
    
    if (dodo.size() == su.size()) {
        cout << "dosu\n";
        return 0;
    }
    
    if (dodo.size() > su.size())
        cout << "do\n";
    else
        cout << "su\n";
    
    return 0;
}