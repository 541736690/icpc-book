/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 
 */
struct state {
    int len, link;
    int next[B];
};

struct SAM {
    state st[MAXLEN * 2];
    int sz, last;
    int cnt[MAXLEN * 2];
    int anc[LOGN][MAXLEN * 2];

    void sam_init() { /// start-hash
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    } /// end-hash

    int sam_extend(int c, int nlast, int val) { /// start-hash
        last = nlast;
        int cur = sz++;
        cnt[cur] = val;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        while(p != -1 && st[p].next[c] == -1) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if(p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                while(p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
        return last;
    } /// end-hash
} sam;

int n, m;
vector<int> tid[N];

struct Trie { 
    int nxt[MAXLEN][B];
    int sz;
    int id[MAXLEN];

    void init() { /// start-hash
        sz = 1;
        memset(nxt, -1, sizeof(nxt));
    } /// end-hash

    void add(string s, int idx) { /// start-hash
        int cur = 0;
        for(char c : s) {
            int &nx = nxt[cur][c - 'a'];
            if(nx == -1) nx = sz++;
            cur = nx;
            tid[idx].push_back(cur);
        }
    } /// end-hash

    void build_sam() { /// start-hash
        sam.sam_init();
        queue<int> que;
        id[0] = 0;
        que.push(0);
        while(!que.empty()) {
            int v = que.front(); que.pop();
            for(int i = 0; i < B; i++) {
                if(nxt[v][i] != -1) {
                    id[nxt[v][i]] = sam.sam_extend(i, id[v], 1);
                    que.push(nxt[v][i]);
                }
            }
        }
        sam.build();
    } /// end-hash

} trie;
