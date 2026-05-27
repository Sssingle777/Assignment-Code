#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>
using namespace std;

const double N = 1e18;
vector<vector<double>> g(101, vector<double>(101, N));
int n, m;

struct node {
	int x, y;
	node(int a=0, int b=0):x(a),y(b){}
};
node s[101];
double dis(int a, int b) {
	double dx, dy, res;
	dx = s[a].x - s[b].x;
	dy = s[a].y - s[b].y;
	res = sqrt(dx * dx + dy * dy);
	return res;
}
vector<bool> sel(101, 0);
vector<double> dist(101,N);

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		s[i] = node(x, y);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		double w = dis(a, b);
		g[a][b] = w;
		g[b][a] = w;
	}
	double ans=0;
	dist[1] = 0;
	for(int cnt=0;cnt<n;cnt++)
	{
		int idx = -1;
		double tmp = N;
		for (int i = 1; i <= n; i++)
		{
			if (!sel[i] && dist[i]<tmp) {
				tmp = dist[i];
				idx = i;
			}
		}
		sel[idx] = 1;
		ans += tmp;
		for (int i = 1; i <= n; i++) {
			if (!sel[i]&&g[idx][i]<dist[i]) {
				dist[i] = g[idx][i];
			}
		}
	}
	cout <<fixed <<setprecision(2)<< ans;
	return 0;
}
/*
5
0 0
2 0
2 2
0 2
3 1
6
1 2
1 4
2 3
3 4
2 5
3 5

*/