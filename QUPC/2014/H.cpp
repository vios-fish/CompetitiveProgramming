#include<iostream>
#include <vector>

using namespace std;

struct edge{ int to, cap, rev; };

const int INF = 1 << 30;
vector<edge> G[100];
bool used[100];

void add_edge(int from, int to, int cap){
    G[from].push_back(edge{to, cap, (int)G[to].size() } );
    G[to].push_back(edge{from,0,(int)G[from].size()-1});
}

int dfs(int v, int t, int f){
    if(v==t) return f;
    used[v] = true;
    for( int i=0; i<G[v].size(); ++i){
        edge &e = G[v][i];
        if( !used[e.to] && e.cap >0){
            int d = dfs(e.to, t, min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_frow(int s, int t){
    int flow = 0;
    for(;;){
        memset(used, 0, sizeof(used));
        int f = dfs(s,t,INF);
        if( f == 0) return flow;
        flow += f;
    }
}

int main(){
    int N,M,P,G;

    cin >> N >> M >> P >> G;

    vector<int> s(G);
    for(int i=0; i<G; ++i){
        cin >> s[i];
    }

    for(int i=0; i<N; ++i){
        
    }
    
    
    
}
