#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

std::stack<int> S;

void Explore(std::vector<int> adj[], int s, std::vector<bool> &visited, int chioce)
{
  visited[s] = true;
  for(int i=0;i<adj[s].size();i++)
  {
    if(visited[adj[s][i]] == false)
      Explore(adj, adj[s][i], visited, chioce);
  }
  if(chioce)
    S.push(s);
}

int main()
{
  int n,m,a,b,i,scc=0;
  scanf("%d %d",&n,&m);
  std::vector<int> adj1[n+1];
  std::vector<int> adj2[n+1];
  std::vector<bool> visited1(n+1, false);
  std::vector<bool> visited2(n+1, false);
  for(i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    adj1[a].push_back(b);
    adj2[b].push_back(a);
  }

  for(i=1;i<=n;i++)
  {
    if(visited2[i] == false)
      Explore(adj2, i, visited2, 1);
  }

  while(!S.empty())
  {
    int s = S.top();
    S.pop();
    if(visited1[s] == false)
    {
      scc++;
      Explore(adj1, s, visited1, 0);
    }
  }
  printf("%d\n",scc);
  return 0;
}
