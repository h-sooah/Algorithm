#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 8;

int N, M;
vector<int> v(SIZE, 0);

void backtracking(int cnt, int cur) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=cur; i<=N; i++) {
        v[cnt] = i;
        backtracking(cnt + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N >> M;
    
    backtracking(0, 1);

    return 0;
}