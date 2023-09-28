#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 8;

int N, M;
vector<int> result(SIZE, 0);
vector<bool> check(SIZE, false);
vector<int> v;

void backtracking(int cnt, int cur) {
    if (cnt == M) {
        for (int i=0; i<cnt; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=cur; i<N; i++) {
        int num = v[i];
        if (check[num] == false) {
            check[num] = true;
            result[cnt] = num;
            backtracking(cnt + 1, i + 1);
            check[num] = false;
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
    
    backtracking(0, 0);

    return 0;
}