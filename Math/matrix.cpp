vii mat_mult(vii &a,vii &b){
    assert(a[0].size() == b.size());
    vii ans (a.size(),vi(b[0].size(),0));
    for(ll i=0;i<a.size();i++)
        for(ll j=0;j<b[0].size();j++)
            for(ll k=0;k<a[0].size();k++)
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
    return ans;
}