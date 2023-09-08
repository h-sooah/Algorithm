#include <iostream>
#include <cmath>
#include <stack>

#define MAX 9

using namespace std;

int N, M;
int arr[MAX] = { 0 };
bool visited[MAX] = { false };

void backtracking(int cnt) {
    
    if (cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            backtracking(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> N >> M;
    
    // 연산 및 출력
    backtracking(0);
    
    return 0;
}
