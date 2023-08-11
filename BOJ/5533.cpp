#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));
	vector<int> result(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[j][i];
		}
	}

	int num;
	bool flag;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			flag = false;
			num = v[i][j];

			for (int k = 0; k < n; k++) {
				if (k == j)
					continue;

				if (num == v[i][k]) {
					flag = true;
					break;
				}		
			}

			if (flag == false) {
				result[j] += num;
			}

		}
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << "\n";

	return 0;

}