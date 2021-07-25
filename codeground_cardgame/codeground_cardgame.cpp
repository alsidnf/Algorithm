#include <iostream>
#include <cstring>
using namespace std;
int TC, N, K, X[3001], Y[3001];
bool ans[3001][3001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> X[i];
		for (int i = 1; i <= N; i++) cin >> Y[i];
		memset(ans, true, sizeof(ans));
		ans[0][0] = false;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (ans[i][j]) {
					int sum = 0;
					for (int k = i + 1; k <= N; k++) {
						sum += X[k];
						if (sum > K) {
							break;
						}
						ans[k][j] = 0;
					}
					sum = 0;
					for (int k = j + 1; k <= N; k++) {
						sum += Y[k];
						if (sum > K) {
							break;
						}
						ans[i][k] = 0;
					}
				}
			}
		}
		int a = 0;
		for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) if (ans[i][j]) ++a;
		cout << "Case #" << tc << "\n" << (N + 1) * (N + 1) - a << " " << a << "\n";
	}
}