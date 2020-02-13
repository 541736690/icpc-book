/**
 * Author:
 * Date:
 * License: 
 * Source: 
 * Description: 
 * Time:
 * Status:
 */
class DSU {
public:
    int n,com;
    int head[maxn], sz[maxn];
    stack<pii> stk;
 
    void init(int _n) {
        n = com = _n;
        for(int i=0;i<n;i++) {
            head[i] = i;
            sz[i] = 1;
        }
    }
 
    int findhead(int x) {
        if(x==head[x]) return x;
        return findhead(head[x]);
    }
 
    void add_edge(int u, int v) {
        int x = findhead(u), y = findhead(v);
        if(sz[x] > sz[y]) swap(x,y);
        stk.push({x,y});
        if(x!=y) {
            head[x] = y;
            sz[y] += sz[x];
            com--;
        }
    }
 
    void pop_edge() {
        int x = stk.top().X, y = stk.top().Y; stk.pop();
        if(x!=y) {
            head[x] = x;
            sz[y] -= sz[x];
            com++;
        }
    }
 
    int size() {
        return com;
    }
} dsu;

int main() {
    dsu.init(n);
    dsu.add_edge(u, v);
    dsu.pop_edge();
    ans = dsu.size();
}
