#include <iostream>
#include <cmath>

using namespace std;

void star(int i, int j, int n) {
	if (i / n % 3 == 1 && j / n % 3 == 1) {
		cout << " ";
	}
	else if (n / 3 == 0) {
		cout << "*";
	}
	else {
		star(i, j, n / 3);
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    
    // 입력
    int n;
    cin >> n;
    
    // 연산 및 출력
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		cout << '\n';
	}
        
    return 0;
}
