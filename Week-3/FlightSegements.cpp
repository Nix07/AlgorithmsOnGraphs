#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int n,m,a,b,i,u,v,s;
  scanf("%d %d",&n,&m);
  std::vector<int> adj[n+1];
  std::vector<int> dist(n+1, -1);
  std::queue<int> Q;
  for(i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  scanf("%d %d",&u,&v);
  dist[u] = 0;
  Q.push(u);
  while(!Q.empty())
  {
    s = Q.front();
    Q.pop();
    for(i=0;i<adj[s].size();i++)
    {
      if(dist[adj[s][i]] == -1)
      {
        Q.push(adj[s][i]);
        dist[adj[s][i]] = dist[s] + 1;
      }
    }
  }
  printf("%d ",dist[v]);
  return 0;
}
