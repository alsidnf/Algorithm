#include <iostream>
#define INF 1e9
using namespace std;
int TC, N, k, m;
int dp[1501][1501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> k >> m;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dp[i][j] = INF;
		for (int i = 1; i <= N; i++) dp[i][i] = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			for (int j = 1; j <= N; j++) {
				int a = dp[j][x], b = dp[j][y];
				dp[j][x] = min(b, a + 1);
				dp[j][y] = min(a, b + 1);
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (dp[a][b] == INF) --ans;
			else ans += dp[a][b];
		}
		cout << "Case #" << tc << "\n" << ans << "\n";
	}
}