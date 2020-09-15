bool con(int mid){

}
int bs(int ini,int fin){
    if(fin==ini)
        return ini;
    int mid = (ini+fin)/2+1;
    if(con(mid)>x)return bs(ini,mid-1);
    return bs(mid,fin);
}