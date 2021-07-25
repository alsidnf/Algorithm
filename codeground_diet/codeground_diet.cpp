#include <iostream>
#include <algorithm>
using namespace std;
int T, N, K;
int A[200000], B[200000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < N; i++) cin >> B[i];
		sort(A, A + N);
		sort(B, B + N);
		int ans = 0;
		for (int i = 0; i < K; i++) {
			ans = max(ans, (A[i] + B[K - 1 - i]));
		}
		cout << "Case #" << tc << "\n" << ans << "\n";
	}
}