#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vector;
    int N, num, v;
    
    // 입력 및 출력
    cin >> N;
    
    while (N--) {
        cin >> num;
        vector.push_back(num);
    }
    
    cin >> v;
    
    int sum = 0;
    for (int i : vector) {
        if (v == i)
            sum++;
    }
    
    cout << sum << "\n";
    
    return 0;
    
}