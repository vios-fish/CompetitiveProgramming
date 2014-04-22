#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1<<30;

struct Area{
    int begin;
    int end;
    int cost;
};

typedef pair<int, int> P;
struct edge{ int to, cost; };
vector<edge> g[30000];

void dijkstra(int s, vector<int> &d, int V){
    priority_queue<P, vector<P>,greater<P> > pqn;
    d.resize(V,INF);

    pqn.push(P(0,s));
    d[s] = 0;
    while(!pqn.empty()){
        P p = pqn.top();
        int v = p.second;
        pqn.pop();

        if( d[v] < p.first ) continue;
        for(int i=0; i<g[v].size(); ++i){
            edge e = g[v][i];
            if( d[e.to] > d[v]+e.cost){
                d[e.to] = d[v] + e.cost;
                pqn.push(P(d[e.to], e.to));
            }
        }
    }
}

int to_cost(int &minpath, vector<Area> &area){
    if(minpath == INF){
        return INF;
    }
    for(int j=0; j<area.size(); ++j){
        if( area[j].begin <= minpath && minpath < area[j].end){
            return area[j].cost;
        }
    }
}

int main(){
    int N,M,K,S,G;

    cin >> N >> M >> K >> S >> G;
    
    vector<Area> area(K);
    
    for(int i=0; i<M; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back(edge{b,c});
        g[b].push_back(edge{a,c});
    }

    for(int i=0; i<K; ++i){
        cin >> area[i].begin >> area[i].cost;
    }
    for(int i=0; i<K-1; ++i){
        area[i].end = area[i+1].begin;
    }
    area[K-1].end = INF;


    vector<int> minpathS, minpathG;
    dijkstra(S, minpathS, N);
    dijkstra(G, minpathG, N);

    int ans = to_cost(minpathS[G], area);

    for(int j=0; j<N; ++j){
        if(j == S || j == G) continue;

        if(minpathS[j] == INF || minpathG[j] == INF) continue;

        int tmp = to_cost(minpathS[j], area) + to_cost(minpathG[j], area);
        ans = min(ans, tmp);
    }

    cout << ans << endl;           
}
