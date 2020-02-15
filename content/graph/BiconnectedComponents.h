/**
 * Author: Simon Lindholm
 * Date: 2017-04-17
 * License: CC0
 * Source: folklore
 * Description:
 * Time: O(E + V)
 * Status: 
 * Usage:
 */
#pragma once

int cur, num[maxn], low[maxn];
int sz;
vector<int> com[maxn];
void tarjan(int u, int last) {
    num[u] = low[u] = ++cur;
    st.push(u); // vertex
    for(auto tmp : way[u]) {
        int v = tmp.first, id = tmp.second;
        if(v == last) continue; // if(id == last)
        if(!num[v]) {
            // st.push(id);
            tarjan(v, u); // tarjan(v, id)
            low[u] = min(low[u], low[v]);
            /* if(low[v] >= num[u]) {
                sz++;
                while(1) {
                    int x = st.top(); st.pop();
                    com[sz].push_back(x);
                    if(x == id) break;
                }
            } */
        }
        else low[u] = min(low[u], num[v]);
        /* else if(num[v] < num[u]) {
            st.push(id);
            low[u] = min(low[u], num[v]);
        } */
    }
    if(num[u] == low[u]) { // vertex
        sz++;  
        while(1) {
            int x = st.top(); st.pop();
            com[sz].push_back(x);
            if(x == u) break;
        }
    }
}