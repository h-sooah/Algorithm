#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v(8, 0);
vector<bool> check(8, false);

void backtracking(int cnt, int cur) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=cur; i<=N; i++) {
        if (check[i] == false) {
            check[i] = true;
            v[cnt] = i;
            backtracking(cnt + 1, i + 1);
            check[i] = false;
        }
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