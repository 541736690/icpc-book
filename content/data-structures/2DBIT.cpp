/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
vector<int> vals[N], f[N];

void addupd(int x, int y) {
    for (int i = x; i < N; i |= i + 1) vals[i].push_back(y);
}

void addget(int x, int y) {
    if (x < 0 || y < 0) return;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) vals[i].push_back(y);
}

void upd(int x, int y, int v) {
    for (int i = x; i < N; i |= i + 1) {
        for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin();
             j < (int) f[i].size(); j |= j + 1) {
            f[i][j] += v;
        }
    }
}

int get(int x, int y) {
    if (x < 0 || y < 0) return 0;
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0;
             j = (j & (j + 1)) - 1)
            res += f[i][j];
    return res;
}