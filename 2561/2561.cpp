#include <cstdio>
#include <cmath>
#include <cstdlib>
int N, arr[1005], ans[3][2];
bool flag = false;
void change(int left, int right) {
	int temp[1005];
	for (int i = left; i <= right; i++) {
		temp[i] = arr[right + left - i];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
}
void findcut(int* cut, int& cnt) {
	bool ascending = true;
	for (int i = 1; i <= N; i++) {
		if (ascending) {
			if (arr[i] != arr[i - 1] + 1) {
				if (cnt != 0 && cut[cnt - 1] < i - 1) cut[cnt++] = i - 1;
				if(cnt == 0 || cut[cnt - 1] < i) cut[cnt++] = i;
				if (i != N) cut[cnt++] = i + 1;
				if (i != N && arr[i] == arr[i + 1] + 1) {
					ascending = false;
				}
				else if (i != N && arr[i] == arr[i + 1] - 1) {
					ascending = true;
				}
			}
		}
		else {
			if (arr[i] != arr[i - 1] - 1) {
				if (cnt != 0 && cut[cnt - 1] < i - 1) cut[cnt++] = i - 1;
				if (cnt == 0 || cut[cnt - 1] < i) cut[cnt++] = i;
				if (i != N) cut[cnt++] = i + 1;
				if (i != N && arr[i] == arr[i + 1] + 1) {
					ascending = false;
				}
				else if (i != N && arr[i] == arr[i + 1] - 1) {
					ascending = true;
				}
			}
		}
	}
	cut[cnt++] = N + 1;
	int n = cnt;
}
void dfs(int depth) {
	int cnt = 0, cut[1005];
	findcut(cut, cnt);
	if (flag) return;
	if (depth == 3) {
		for (int i = 1; i <= N; i++) {
			if (arr[i] != i) return;
		}
		for (int i = 0; i < 3; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
		flag = true;
		return;
	}
	ans[depth][0] = 1; ans[depth][1] = 1;
	dfs(depth + 1);
	if (flag) return;
	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (abs(arr[cut[i] - 1] - arr[(cut[j] - 1)]) != 1 && abs(arr[cut[j]] - arr[cut[i]]) != 1) continue;
			change(cut[i], cut[j] - 1);
			ans[depth][0] = cut[i]; ans[depth][1] = cut[j] - 1;
			dfs(depth + 1);
			change(cut[i], cut[j] - 1);
			if (flag) return;
		}
	}
}
void makeArr() {
	int l, r;
	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 0; i < 3; i++) {
		l = rand() % N;
		r = rand() % (N - l);
		change(1 + l, 1 + l + r);
	}
}
bool checkans() {
	for (int i = 0; i < 3; i++) {
		change(ans[i][0], ans[i][1]);
	}
	for (int i = 1; i <= N; i++)
		if (arr[i] != i) return false;
	return true;
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	arr[N + 1] = N + 1;
	dfs(0);
	/*int a = 0;
	while (true) {
		++a;
		if (a == 1844) {
			a = a;
		}
		makeArr();
		arr[N + 1] = N + 1;
		flag = false;
		dfs(0);
		if (checkans()) {
			printf("true\n");
		}
		else {
			printf("false\n");
			return 0;
		}
	}*/
}