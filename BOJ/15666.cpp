#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int SIZE = 8;

int N, M;
vector<int> result(SIZE, 0);
//vector<int> check(10000, 0);
set<int> s;

void backtracking(int cnt, int cur) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        int num = *iter;
        if (num >= cur) {
            result[cnt] = num;
            backtracking(cnt + 1, num);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N >> M;
    
    int tmp;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        s.insert(tmp);
    }
    
    backtracking(0, 1);

    return 0;
}