#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned int A, B;
	cin >> A >> B;
	int cnt = 1;
	while (A < B) {
		++cnt;
		if (B % 2 == 0) B /= 2;
		else if (B % 10 == 1) B /= 10;
		else break;
	}
	printf("%d", A == B ? cnt : -1);
}