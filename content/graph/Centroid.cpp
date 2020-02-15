/**
 * Author: 
 * Description:
 */
set<int> G[N];
int depth[N], par[N], sub[N];
 
int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}
 
int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}
 
void decompose(int v, int p){
    dfs1(v, -1);
    int centroid = dfs2(v, -1, sub[v]);
    par[centroid] = p;
    for(int nxt : G[centroid]){
        G[nxt].erase(centroid);
        decompose(nxt, centroid);
    }
    G[centroid].clear();
}