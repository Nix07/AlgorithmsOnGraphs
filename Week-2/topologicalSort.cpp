#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

std::stack<int> S;

void Explore(std::vector<int> adj[], int s, std::vector<bool> &visited)
{
  visited[s] = true;
  for(int i=0;i<adj[s].size();i++)
  {
    if(visited[adj[s][i]] == false)
      Explore(adj, adj[s][i], visited);
  }
  S.push(s);
}

int main()
{
  int i,n,m,a,b;
  scanf("%d %d",&n,&m);
  std::vector<int> adj[n+1];
  std::vector<bool> visited(n+1, false);
  for(i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
  }

  for(i=1;i<=n;i++)
  {
    if(visited[i] == false)
      Explore(adj, i, visited);
  }
  while(!S.empty())
  {
    printf("%d ",S.top());
    S.pop();
  }
  return 0;
}
