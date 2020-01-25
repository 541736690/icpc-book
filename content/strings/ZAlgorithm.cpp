/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: str = "aabaacd", z = (x, 1, 0, 2, 1, 0, 0)
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e6 + 500;

string s;
int z[MAXN],cnt[MAXN];

void getZarr(string str) /// start-hash
{
    memset(z, 0, sizeof(z));
    int n = str.length();
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
} /// end-hash
