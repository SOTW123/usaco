#include <bits/stdc++.h>
using namespace std;

ifstream fin("crosswords.in");
ofstream fout("crosswords.out");

int main() {
	int n, m;
	fin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) fin >> v[i][j];

	set<pair<int,int>> s;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i < n-2) {
				if(i > 0) {
					if(v[i-1][j]!='.' &&  v[i][j]=='.' && v[i+1][j]=='.' && v[i+2][j]=='.') {
						s.insert(make_pair(i,j));
					}
				} else {
					if(v[i][j]=='.' && v[i+1][j]=='.' && v[i+2][j]=='.') {
						s.insert(make_pair(i,j));
					}
				}
			}
			if(j < m-2) {
				if(j > 0) {
					if(v[i][j-1]!='.' &&  v[i][j]=='.' && v[i][j+1]=='.' && v[i][j+2]=='.') {
						s.insert(make_pair(i,j));
					}
				} else {
					if(v[i][j]=='.' && v[i][j+1]=='.' && v[i][j+2]=='.') {
						s.insert(make_pair(i,j));
					}
				}
			}
		}
	}
	fout << s.size() << endl;
	for(auto e : s) {
		fout << e.first+1 << " " << e.second+1 << endl;
	}
    return 0;
}
