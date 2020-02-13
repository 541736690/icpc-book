/**
 * Author:
 * Date:
 * License: 
 * Source: 
 * Description: 
 * Time:
 * Status:
 */
struct node {
    char key;
    ll prior;
    int sz, rev;
    node *l, *r;
    node(char _key = 0) {
        key = _key;
        prior = (rand()<<16) + rand();
        sz = 1;
        rev = 0;
    }
};
int sz(node *x) {
    return x ? x->sz : 0;
}
void pushdown(node *root) {
    if(root && root->rev) {
        swap(root->l, root->r);
        if(root->l) root->l->rev ^= 1;
        if(root->r) root->r->rev ^= 1;
        root->rev = 0;
    }
}
void update(node *root) {
    if(root) {
        pushdown(root->l); pushdown(root->r);
        root->sz = sz(root->l) + sz(root->r) + 1;
    }
}
void split(node *root, int pos, node *&l, node *&r) {
    pushdown(root);
    if(!root) l = r = nullptr;
    else if(sz(root->l)+1<=pos) l = root, split(root->r, pos-sz(root->l)-1, l->r, r);
    else r = root, split(root->l, pos, l, r->l);
    update(root);
}
void merge(node *&root, node *l, node *r) {
    pushdown(l); pushdown(r);
    if(!l || !r) root = l ? l : r;
    else if(l->prior > r->prior) root = l, merge(root->r, l->r, r);
    else root = r, merge(root->l, l, r->l);
    update(root);
}
int main() {
    node *root = nullptr;
    for(int i=1;i<=n;i++) merge(root, root, new node(s[i]));
    node *s1, *s2;
    split(root, k, s1, s2); // split root to s1 = [1..k] and s2 = [k+1..n]
    merge(root, s1, s2); // merge s1 and s2 to get new root
    // reverse [i, j]
    split(root, j, s2, s3);
    split(s2, i-1, s1, s2);
    s2->rev ^= 1; pushdown(s2);
    merge(root, s1, s2);
    merge(root, root, s3);
}