#include <iostream>
#define MAX 9

using namespace std;

int N, M, flag = 0;
int arr[MAX] = { 0 };
bool visited[MAX] = { false };

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
        return;
    } 

    for (int i=num; i<=N; i++) {
        visited[i] = true;
        arr[cnt] = i;
        dfs(i, cnt+1);
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> N >> M;

    // 출력
    dfs(1, 0);
    
    return 0;
}