#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vector;
    int N, X, num;
    
    // 입력 및 출력
    cin >> N >> X;
    while (N--) {
        cin >> num;
        if (num < X)
            vector.push_back(num);
    }
    
    for (int i: vector) {
        cout << i << " ";
    }
    
    return 0;
    
}