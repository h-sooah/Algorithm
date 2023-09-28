#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v(8, 0);

void backtracking(int cnt) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=1; i<=N; i++) {
        v[cnt] = i;
        backtracking(cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N >> M;
    
    backtracking(0);

    return 0;
}