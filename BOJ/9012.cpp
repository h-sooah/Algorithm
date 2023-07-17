#include <iostream>
#include <stack>

using namespace std;

bool isVPS (string str) {
	int len = str.length();

	stack<char> s;
	char bracket;
	for (int i = 0; i < len; i++) {
		bracket = str[i];
		if (bracket == '(')
			s.push('(');
		else {
			if (s.empty())
				return false;
			else
				s.pop();
		}
	}

	if (s.empty())
		return true;
	else
		return false;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int T;
	cin >> T;

	string str;
	while (T--) {
		cin >> str;
		if (isVPS(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
profile
shasha