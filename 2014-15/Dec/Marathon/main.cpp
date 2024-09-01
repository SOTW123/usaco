#include <bits/stdc++.h>

using namespace std;

ifstream fin("marathon.in");
ofstream fout("marathon.out");

int dist(pair<int,int> f, pair<int,int> s) {
    return abs(s.first-f.first) + abs(s.second-f.second);
}

int main() {
    int N;
    fin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        fin >> v[i].first >> v[i].second;
    }
    
    int total = 0;
    for(int i = 0; i < N-1; i++) {
        total += dist(v[i+1], v[i]);
    }
    
    int ans = total;
    for(int i = 1; i < N-1; i++) {
        int new_dist = total - dist(v[i], v[i-1]) - dist(v[i+1], v[i]) + dist(v[i+1], v[i-1]);
        ans = min(ans, new_dist);
    }
    
    fout << ans << endl;
    return 0;
}
   
