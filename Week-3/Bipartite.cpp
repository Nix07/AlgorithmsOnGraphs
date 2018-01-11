#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int n,m,a,b,i,s,ans=1,node=0,size=1;
  scanf("%d %d",&n,&m);
  std::vector<int> adj[n+1];
  std::vector<int> dist(n+1, -1);
  std::vector<int> dummy;
  std::vector<bool> proc(n+1, false);
  std::queue<int> Q;
  for(i=0;i<m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dist[1] = 0;
  Q.push(1);
  while(!Q.empty())
  {
    s = Q.front();
    Q.pop();
    proc[s] = true;
    node++;

    for(i=0;i<adj[s].size();i++)
    {
      if(proc[adj[s][i]] == true)
      {
        ans = 0;
        break;
      }
      if(dist[adj[s][i]] == -1)
      {
        Q.push(adj[s][i]);
        dummy.push_back(adj[s][i]);
        dist[adj[s][i]] = dist[s] + 1;
      }
    }

    if(node == size)
    {
      while(!dummy.empty())
      {
        int t = dummy.back();
        proc[t] = true;
        dummy.pop_back();
      }
      size = adj[s].size();
      node = 0;
    }
    proc[s] = false;
  }
  printf("%d\n",ans);
  return 0;
}
