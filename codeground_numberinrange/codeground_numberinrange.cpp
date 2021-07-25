#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int p[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };

int TC, N, K, M;
char str[50001];

struct Arr {
	int val;	//값
	int type;	//몇번째 i를 바꾼건지 N이면 안바꾼것
	int ep;		//숫자의 기준
	bool operator<(const Arr& O) { return val < O.val; }
}arr[500000];
int cnt;

const int start = 65536;
int tree[131072];
int lazy[131072];

void lazy_update(int node) {
	tree[node] += lazy[node];
	if (node < start) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

int STMAX(int L, int R, int NL, int NR, int node) {
	lazy_update(node);
	if (NR < L || R < NL) return 0;
	if (L <= NL && NR <= R) return tree[node];
	int NM = (NL + NR) / 2;
	return max(STMAX(L, R, NL, NM, node * 2), STMAX(L, R, NM + 1, NR, node * 2 + 1));
}

void STADD(int L, int R, int diff, int NL, int NR, int node) {
	lazy_update(node);
	if (NR < L || R < NL) return;
	if (L <= NL && NR <= R) {
		lazy[node] += diff;
		lazy_update(node);
		return;
	};
	int NM = (NL + NR) / 2;
	STADD(L, R, diff, NL, NM, node * 2);
	STADD(L, R, diff, NM + 1, NR, node * 2 + 1);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> K >> M;
		cin >> str;
		int val = 0;
		cnt = 0;
		for (int i = 0; i < K - 1; i++) {
			val *= 10;
			val += (str[i] - '0');
		}
		for (int i = K - 1; i < N; i++) {
			val = (val % p[K - 1]) * 10 + (str[i] - '0');
			arr[cnt++] = { val, N, i };
			for (int j = 0; j < K; j++) {
				int temp = val - val % p[j + 1] + val % p[j] + p[j];
				arr[cnt++] = { temp, i - j, i };
			}
		}
		sort(arr, arr + cnt);
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		int ans = 0;
		for (int i = 0, j = 0; i < cnt; i++) {
			while (arr[i].val - arr[j].val > M) {
				if (arr[j].type == N) {
					STADD(0, arr[j].ep - K, -1, 0, start - 1, 1);
					STADD(arr[j].ep + 1, N - 1, -1, 0, start - 1, 1);
				}
				else {
					STADD(arr[j].type, arr[j].type, -1, 0, start - 1, 1);
				}
				++j;
			}
			if (arr[i].type == N) {
				STADD(0, arr[i].ep - K, 1, 0, start - 1, 1);
				STADD(arr[i].ep + 1, N - 1, 1, 0, start - 1, 1);
			}
			else {
				STADD(arr[i].type, arr[i].type, 1, 0, start - 1, 1);
			}
			if (i < cnt - 1 && arr[i].val == arr[i + 1].val) continue;
			ans = max(ans, STMAX(0, start - 1, 0, start - 1, 1));
		}
		cout << "Case #" << tc << "\n" << ans << "\n";
	}
}