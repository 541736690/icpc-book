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
    point val;
    node *l, *r;
    node(point _val = {0,inf}) {
        val = _val;
        l = r = nullptr;
    }
};

ll f(point val, ll x) {
    return val.X*x + val.Y;
}

void update(node *&root, int l, int r, point val) {
    if(val.Y==inf) return ;
    if(!root) {
        root = new node(val);
        return ;
    }
    int mid = (l+r)/2;
    int a = (f(val, l) < f(root->val, l));
    int b = (f(val, mid) < f(root->val, mid));
    int c = (f(val, r) < f(root->val, r));
    if(b) swap(root->val, val);
    if(l==r) return ;
    if(a != b) update(root->l, l, mid, val);
    else if(b != c) update(root->r, mid+1, r, val);
}

ll query(node *root, int l, int r, ll x) {
    if(!root) return inf;
    if(l==r) return f(root->val, x);
    int mid = (l+r)/2;
    if(x<=mid) return min(f(root->val, x), query(root->l,l,mid,x));
    return min(f(root->val, x), query(root->r,mid+1,r,x));
}
