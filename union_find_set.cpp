#include<vector>
using namespace std;

vector<int> par, Rank;
void init(int n){
    Rank.resize(n+1,0);
    par.resize(n+1);
    for(int i=0;i<par.size();i++){
        par[i] = i;
    }
}
int find(int x){
    if(par[x]==x) return x;
    else return par[x] = find(par[x]);
}
bool unity(int x, int y){
    x = find(x);
    y = find(y);
    if(Rank[x]>Rank[y]) par[y] = x;
    else if(Rank[x]<Rank[y]) par[x] = y;
    else {
        par[x] = y;
        Rank[y]++;
    }
}
bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    return 0;
}