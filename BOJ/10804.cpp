#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int a , b;
    vector<int> cards(21);
    for (int i=0; i<=20; i++)
        cards[i] = i;
        
    // 연산 및 출력
    for (int i=0; i<10; i++) {
        cin >> a >> b;
        reverse(cards.begin()+a, cards.begin()+b+1);
    }
    
    for (int i=1; i<=20; i++)
        cout << cards[i] << " ";
    
    return 0;
}