#include <iostream>

using namespace std;

bool dfs(int n) {
	if (n == 0) return true;
	if (n < 0) return false;
	if (dfs(n - 11)) return true;
	if (dfs(n - 9)) return true;
	if (dfs(n - 7)) return true;
	return false;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int N;
		cin >> N;
		cout << "Case #" << test_case << "\n";
		cout << (dfs(N)?"YES":"NO") << "\n";
	}

	return 0;
}