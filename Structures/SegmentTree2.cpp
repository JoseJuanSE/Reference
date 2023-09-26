struct SegmentTree {
    vector<int> tree;
    int n;
    SegmentTree(int n) {
        tree.assign(4*n, INT_MAX);
        this->n = n;
    }

    void build(vector<int> &a, int ini, int fin, int node) {
        if(ini == fin) {
            tree[node] = a[ini];
        } else {
            int mitad = (ini + fin) / 2;
            build(a, ini, mitad, node*2);
            build(a, mitad+1, fin, node*2+1);
            tree[node] = min(tree[node*2], tree[node*2+1]);
        }
    }

    void build(vector<int> &a) {
        build(a, 1, n, 1);
    }

    int query(int ini, int fin, int l, int r, int node) {
        if(ini == l and fin == r)return tree[node];
        if(l > r)return INT_MAX;
        int mitad = (ini + fin) / 2;
        return min(query(ini, mitad, l, min(r, mitad), node * 2), query(mitad+1, fin, max(mitad+1, l), r, node*2+1));
    }

    int query(int ini, int fin) {
        return query(1, n, ini, fin, 1);
    }
};
