#include <cstdio>
#include <vector>

using namespace std;

void Explore(std::vector<int> adj[], int s, std::vector<bool> &visited)
{
  visited[s] = true;
  for(int i=0;i<adj[s].size();i++)
  {
    if(visited[adj[s][i]] == false)
      Explore(adj, adj[s][i], visited);
  }
}

int main()
{
  int n,m,a,b,cc=0;
  vector<int> adj[10000];
  vector<bool> visited(10000, false);
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=1;i<=n;i++)
  {
    if(visited[i] == false)
    {
      cc++;
      Explore(adj, i, visited);
    }
  }
  printf("%d\n",cc);
  return 0;
}
