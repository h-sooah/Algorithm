#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int N;
	cin >> N;

	vector<int> v;
	int num;
	while (N--) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}