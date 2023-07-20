#include <iostream>
#include <set>

using namespace std;

struct compare {
	bool operator() (const string& a, const string& b) const {
		if (a.length() != b.length())
			return a.length() < b.length();
		return a < b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int N;
	cin >> N;

	set<string, compare> s;
	string word;
	while (N--) {
		cin >> word;
		s.insert(word);
	}

	for (auto iter : s)
		cout << iter << "\n";

	return 0;
}
