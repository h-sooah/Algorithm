#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int arr[6] = {1, 1, 2, 2, 2, 8};
    
    // 입력
    int input;
    for (int i=0; i<6; i++) {
        cin >> input;
        
        cout << arr[i] - input << " ";
    }
}