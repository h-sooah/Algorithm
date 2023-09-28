#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> oper(4, 0); // 0: +, 1: -, 2: x, 3: /
vector<int> v;
int N;

int ans_max = -10e8;
int ans_min = 10e8;

void operation(int n, int cnt) {

    if (cnt == N-1) {
        if (n > ans_max)
            ans_max = n;
        if (n < ans_min)
            ans_min = n;
            
        return;
    }
    
    int next = v[cnt + 1];
    for (int i=0; i<4; i++) {
        if (oper[i] == 0)
            continue;
        
        oper[i]--;
        
        if (i == 0)
            operation(n + next, cnt + 1);
        else if (i == 1)
            operation(n - next, cnt + 1);
        else if (i == 2)
            operation(n * next, cnt + 1);
        else
            operation(n / next, cnt + 1);
        
        oper[i]++;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N;
    
    v.assign(N, 0);
    for (int i=0; i<N; i++)
        cin >> v[i];
        
    for (int i=0; i<4; i++)
        cin >> oper[i];
    
    operation(v[0], 0);
    
    cout << ans_max << '\n' << ans_min << '\n';
    
    return 0;
}