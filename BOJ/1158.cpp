#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, k;
	cin >> n >> k;

	//N명 앉히기
	vector<int> people(n+1, 0);
	for (int i = 1; i <= n; i++)
		people[i] = i;

	//한 명씩 빼기
	cout << "<";
	int out = k, flag = k, cnt = 0;
	while (cnt != n) {

		while (people[out] == 0 || flag != k) {
			out++;
			if (out == n + 1)
				out = 1;
			if (people[out] != 0)
				flag++;
		}

		cout << people[out];
		if (cnt != n - 1)
			cout << ", ";

		people[out] = 0;
		flag = 0;
		cnt++;
	}
	cout << ">\n";

	return 0;
}