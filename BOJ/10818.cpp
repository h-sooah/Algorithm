#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vector;
    int N, num;
    
    // 입력 및 출력
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> num;
        vector.push_back(num);
    }
    
    sort(vector.begin(), vector.end());
    
    cout << vector[0] << " " << vector[N-1] << "\n";
    
    return 0;
    
}