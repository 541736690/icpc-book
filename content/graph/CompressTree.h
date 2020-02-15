/**
 * Author: Simon Lindholm
 * Date: 2016-01-14
 * License: CC0
 * Status: Tested at CodeForces
 * Description:
 * Time: $O(|S| \log |S|)$
 */
#pragma once

void build(vector<int> vec) {
    for(auto u : vir) // reset edge
    sort(vec.begin(),vec.end(),[](int u,int v) {return st[u]<st[v];});
    int sz = 0; vector<int> stk(n+1);
    stk[++sz] = 1;
    for(auto u : vec) {
        int x = lca(u, stk[sz]);
        vir.push_back(u); vir.push_back(x);
        if(u == stk[sz]) continue;
        if(x != stk[sz]) {
            while(sz >= 2 && h[stk[sz-1]] >= h[x]) {
                add_edge(stk[sz-1], stk[sz]);
                sz--;
            }
            if(x != stk[sz]) {
                add_edge(x, stk[sz]);
                stk[sz] = x;
            }
        }
        stk[++sz] = u;
    }
    for(int i=1;i<=sz-1;i++) add_edge(stk[i], stk[i+1]);
}
