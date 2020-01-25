/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: 0-indexed BIT
 */
int n;
int bit[N];

void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}
