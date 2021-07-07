#include <iostream>
using namespace std;
const int coin[4] = { 10,50,100,500 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int ans[4] = { 0 };
		int a;
		cin >> a;
		for (int i = 3; i >= 0; --i) {
			if (a / coin[i]) {
				ans[i] = a / coin[i];
				a %= coin[i];
			}
		}
		cout << "Case #" << tc << "\n";
		for (int i = 0; i < 4; i++) cout << ans[i] << " ";
		cout << "\n";
	}
}