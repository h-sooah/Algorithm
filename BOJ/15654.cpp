#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int N, M;
vector<int> result(SIZE, 0);
vector<bool> check(10000, false);
vector<int> v;

void backtracking(int cnt) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i : v) {
        if (check[i] == false) {
            check[i] = true;
            result[cnt] = i;
            backtracking(cnt + 1);
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
    
    v.assign(N, 0);
    for (int i=0; i<N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    backtracking(0);

    return 0;
}