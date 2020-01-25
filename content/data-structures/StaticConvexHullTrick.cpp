/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: Maintaining upper convex hull, querying the maximum. Need to put in lines in strictly increasing order of slope.
 */
#include <bits/stdc++.h>
using namespace std;

struct Line {
    ll k, m;
    Line(ll _k, ll _m) {
        k = _k, m = _m;
    }
    Pll inter(Line o) {
        return {m - o.m, o.k - k};
    }
};


struct Hull {
    deque<Line> que;

    bool leq(Pll a, Pll b) {
        return a.first * b.second <= a.second * b.first;
    }
    // k needs to be strictly increasing!
    void add(ll k, ll m) {
        while(que.size() > 1) {
            int ls = que.size() - 1;
            if(leq(que[ls].inter(Line(k, m)), que[ls-1].inter(que[ls]))) que.pop_back();
            else break;
        }
        que.push_back({k, m});
    }
    // Arbitrary x.
    ll query_bin(ll x) {
    	if(que.empty()) return -INF;
        int l = 0, r = que.size() - 1;
        while(l < r) {
            int mi = (l + r) / 2;
            if(que[mi].k * x + que[mi].m < que[mi+1].k * x + que[mi+1].m) l = mi + 1;
            else r = mi;
        }
        return que[l].k * x + que[l].m;
    }
    // If querying increasing x.
    ll query(ll x) {
    	if(que.empty()) return -INF;
        while(que.size() > 1) {
            if(que[0].k * x + que[0].m < que[1].k * x + que[1].m) que.pop_front();
            else break;
        }
        return que[0].k * x + que[0].m;
    }

} hull;
