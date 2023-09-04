#include <iostream>
#include <vector>

using namespace std;

int getMaxSum(vector<int> &cards, int M) {
    int result = 0, tmp = 0;
    
    for (int i=0; i<cards.size()-2; i++) {
        for (int j=i+1; j<cards.size()-1; j++) {
            for (int k=j+1; k<cards.size(); k++) {
                tmp = cards[i] + cards[j] + cards[k];
                
                if (tmp <= M && tmp > result)
                    result = tmp;
            }
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, tmp;
    vector<int> cards;
    
    // 입력
    cin >> N >> M;
    while (N--) {
        cin >> tmp;
        cards.push_back(tmp);
    }
    
    // 출력
    cout << getMaxSum(cards, M);
    
    return 0;
}