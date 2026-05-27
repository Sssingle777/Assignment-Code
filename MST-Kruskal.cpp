#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

const double N = 1e18;
vector<vector<double>> g(101, vector<double>(101, N));
int n, m;

struct node {
	int x, y;
};
node s[101];

struct edge {
	int a, b;
	double w;
};
vector<edge> e(101);
vector<int> fa(101);
struct cmp {
	bool operator()(const edge& x, const edge& y) const {
		return x.w > y.w;
	}
};
int find(int x) {
	if (fa[x] != x) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
priority_queue<edge, vector<edge>, cmp> pq;
double Kruskal() {
	double ans=0;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		pq.push(e[i]);
	}
	int cnt = 0;
	while(!pq.empty()&&cnt<n-1){
		edge tmp = pq.top();
		pq.pop();
		int a = tmp.a, b = tmp.b;
		int pa = find(a), pb = find(b);
		if (pa!=pb) {
			ans += tmp.w;
			cnt++;
			fa[pb] = pa;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].x >> s[i].y;
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		e[i].a = a;
		e[i].b = b;
		double dx, dy, res;
		dx = s[a].x - s[b].x;
		dy = s[a].y - s[b].y;
		e[i].w = sqrt(dx * dx + dy * dy);
	}
	double ans = Kruskal();
	cout << fixed << setprecision(2) << ans;
}
