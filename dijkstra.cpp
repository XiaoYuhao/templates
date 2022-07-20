#include<vector>
#include<queue>
using namespace std;

struct Edge{
    int to, cost;
};
struct Node{
    int pos, cost;
};
vector<vector<Edge>> E; 
vector<int> dis;
vector<int> used;
int n;
void dijkstra(int src){
    dis.resize(n, 0x3f3f3f3f);
    used.resize(n, 0);
    dis[src] = 0;
    //used[src] = 1;
    auto cmp = [](const Node &a, const Node &b){
        return a.cost > b.cost;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);
    Node node;
    node.pos = src;
    node.cost = 0;
    q.push(node);
    while(!q.empty()){
        Node t = q.top();
        q.pop();
        if(used[t.pos]) continue;
        used[t.pos] = 1;
        for(int i=0;i<E[t.pos].size();i++){
            int to = E[t.pos][i].to;
            int cost = dis[t.pos] + E[t.pos][i].cost;
            if(dis[to]>cost){
                dis[to] = cost;
                node.pos = to;
                node.cost = dis[to];
                q.push(node);
            }
        }
    }
}

int main(){
    return 0;
}