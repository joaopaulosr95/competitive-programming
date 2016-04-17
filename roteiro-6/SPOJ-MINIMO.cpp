#include <iostream>
#include <algorithm>

using namespace std;

#define LIM 110
#define LIM1 1000000000

int main() {
	int n, m, g[LIM][LIM][LIM], num = 0;

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j][0] = LIM1;
			}
		}

		for (int i = 0; i < n; i++) 
			g[i][i][0] = 0;

		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			g[u-1][v-1][0] = min(g[u-1][v-1][0], c);
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					g[i][j][k+1] = min(g[i][k][k] + g[k][j][k], g[i][j][k]);
				}
			}
		}

		int c;
		cin >> c;

		cout << "Instancia " << ++num << "\n";
		for (int i = 0; i < c; i++) {
			int o, d, t;
			cin >> o >> d >> t;
			if (g[o-1][d-1][t] == LIM1)
				cout << "-1\n";
			else
				cout << g[o-1][d-1][t] << "\n";
		}
		cout << "\n";
	}

	return 0;
}
