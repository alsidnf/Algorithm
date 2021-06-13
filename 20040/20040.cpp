#include <iostream>
using namespace std;
int N, M;
int P[500000];
int find(int n) {
	if (P[n] < 0) return n;
	return P[n] = find(P[n]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (P[a] < P[b]) {
		P[a] += P[b];
		P[b] = a;
	}
	else {
		P[b] += P[a];
		P[a] = b;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) P[i] = -1;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		if (ans) continue;
		if (!merge(a, b)) {
			ans = i;
		}
	}
	cout << ans;
}