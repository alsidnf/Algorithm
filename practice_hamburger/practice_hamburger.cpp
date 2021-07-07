#include <iostream>
#include <algorithm>
using namespace std;
int TC, b, m, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> b >> m >> c;
		int ans = min({b / 2, m, c / 3});
		cout << "Case #" << tc << "\n" << ans << "\n";
	}
}