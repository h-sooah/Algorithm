#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    
    // 입력
    cin >> N >> M;
    
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<vector<int>> B(N, vector<int>(M, 0));
    
    // 연산 및 출력
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> B[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}