#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> a(num);
	vector<int> b(num);

	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> b[i];
	}

	int sum = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < num; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;
}