#include <cstdio>
#include <vector>

using namespace std;

int chioce = 0;

int Explore(std::vector<int> adj[], int source, std::vector<bool> &visited, int v) {
  visited[source] = true;
  for(int i=0;i<adj[source].size();i++)
  {
    if(adj[source][i] == v)
    {
      chioce = 1;
    }
    if(visited[adj[source][i]] == false)
      Explore(adj, adj[source][i], visited, v);
  }
  return chioce;
}

int main(){
  int i,n,m,u,v,a,b;
  std::vector<int> adj[10000];
  std::vector<bool> visited(10000, false);
  scanf("%d %d",&n,&m);
  for(i=1;i<=m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  scanf("%d %d",&u,&v);
  printf("%d\n",Explore(adj, u, visited, v));
  return 0;
}
