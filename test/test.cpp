#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, arr[8], ans[8];
void dfs(int st, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = st; i < N; i++) {
		ans[cnt] = arr[i];
		dfs(i, cnt + 1);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	dfs(0, 0);
}