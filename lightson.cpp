#include <bits/stdc++.h>
using namespace std;

int n;
int out = 1;

bool visited[100][100];
bool illuminated[100][100];
vector<pair<int,int>> switches[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


bool connected(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cy < 0 || cx > n - 1 || cy > n - 1) {
			continue;
		}

		if (visited[cx][cy]) {
			return true;
		}
	}
	
	return false;

}

void floodfill(int x, int y) {
	if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || visited[x][y] || !illuminated[x][y]) {
		return;
	}

	if (!connected(x, y) && !(x == 0 && y == 0)) {
		return;
	}

	visited[x][y] = true;


	for (int i = 0; i < switches[x][y].size(); i++) {
		int currx = switches[x][y][i].first;
		int curry = switches[x][y][i].second;

		if (!illuminated[currx][curry]) {
			out++;
		}

		illuminated[currx][curry] = true;

		floodfill(currx, curry);
	}
	for (int i = 0; i < 4; i++) {
		floodfill(x + dx[i], y + dy[i]);
	}



}

int main() {

	int m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		switches[x - 1][y - 1].push_back({a - 1, b - 1});
	}

	illuminated[0][0] = true;

	floodfill(0, 0);

	cout << out << endl;
}
