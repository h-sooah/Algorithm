#include <iostream>
#include <vector>

using namespace std;

void calMoney(int money) {
    int quarter = 0, dime = 0, nickel = 0, penny = 0;
    while (money > 0) {
        
        while (true) {
            if (money - 25 < 0)
                break;
            money -= 25;
            quarter++;
        }
        
        while (true) {
            if (money - 10 < 0)
                break;
            money -= 10;
            dime++;
        }
        
        while (true) {
            if (money - 5 < 0)
                break;
            money -= 5;
            nickel++;
        }
        
        while (true) {
            if (money - 1 < 0)
                break;
            money -= 1;
            penny++;
        }
    }
    
    cout << quarter << " " << dime << " " << nickel << " " << penny << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T, money;
    
    // 입력
    cin >> T;
    
    // 연산 및 출력
    while (T--) {
        cin >> money;
        calMoney(money);
    }
    
    return 0;
}