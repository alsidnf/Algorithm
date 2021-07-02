#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, test_case;
	cin >> T;
	string str;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> str;
		cout << "Case #" << test_case + 1 << endl;
		int a = 0, b = 0, ans = 0;
		for (char ch : str) {
			if (ch == 'A') {
				if (++a == 21) {
					ans = 1;
					cout << "Alice\n";
					break;
				}
			}
			else {
				if (++b == 21) {
					ans = 2;
					cout << "Bob\n";
					break;
				}
			}
		}
		if (ans == 0) cout << "Playing\n";
	}
	return 0;
}