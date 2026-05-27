#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int s, f, n, m;
struct vex {
	int x, y;
	vex(int a, int b) :x(a), y(b){}
};
long double dist[101], g[101][101];
bool v[101];
vector<vex> pos;
void dijkstra() {
		for (int i = 1; i <= n; i++) {
			dist[i] = 1e18;
			v[i] = 0;
		}
		dist[s] = 0;
		for (int k = 1; k <= n; k++) {
			int t = -1;
			for (int i = 1; i <= n; i++) {
				if (v[i] == 0 && (t == -1 || dist[i] < dist[t])) t = i;
			}
			v[t] = 1;
			for (int i = 1; i <= n; i++) {
				if (g[t][i] != 0 && v[i] == 0) {
					dist[i] = min(dist[i], dist[t] + g[t][i]);
				}

			}
		}
}
long double cmp(int a, int b) {
	long double dis = 0;
	dis = sqrt((pos[a].x - pos[b].x) * (pos[a].x - pos[b].x)+(pos[a].y - pos[b].y)*(pos[a].y - pos[b].y));
	return dis;
}

int main() {
	cin >> n;
	pos.push_back(vex(0, 0));
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pos.push_back(vex(x,y));
	}
	cin >> m;
	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		g[i][j] = cmp(i,j);
		g[j][i] = cmp(i, j);
	}
	cin >> s >> f;
	dijkstra();
	cout <<fixed<<setprecision(2)<< dist[f];
}
/*
5
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
*/

