#include <iostream>
#include <stack>

using namespace std;

int alpha[26] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int N;
	cin >> N;
	string postfix;
	cin >> postfix;

	for (int i = 0; i < N; i++)
		cin >> alpha[i];

	// 후위표기식 계산
	stack<double> s;
	for (int i = 0; i < postfix.size(); i++) {

		// 연산자일 때
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double n1, n2;
			n1 = s.top();
			s.pop();
			n2 = s.top();
			s.pop();

			double result;
			switch (postfix[i]) {
			case '+':
				result = n2 + n1;
				break;
			case '-':
				result = n2 - n1;
				break;
			case '*':
				result = n2 * n1;
				break;
			case '/':
				result = n2 / n1;
				break;
			}
			s.push(result);
		}

		// 피연산자일 때
		else {
			s.push(alpha[postfix[i] - 'A']);
		}

	}

	double ans = s.top();
	cout.precision(2);
	cout << fixed;
	cout << ans << "\n";
}