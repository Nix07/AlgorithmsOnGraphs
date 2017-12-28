#include <cstdio>
#include <vector>

using namespace std;

int check = 0;

void DFS(std::vector<int> adj[], int s, std::vector<bool> &visited, std::vector<int> &processing)
{
  visited[s] = true;
  processing[s] = true;
  // for(int i=1;i<processing.size();i++)
  //   printf("%d ",processing[i]);
  // printf("\n");
  for(int i=0;i<adj[s].size();i++)
  {
    if(processing[adj[s][i]] == true)
    {
      // printf("Backedge - %d %d\n",s, adj[s][i]);
      check = 1;
    }
    if(visited[adj[s][i]] == false)
    {
      DFS(adj, adj[s][i], visited, processing);
    }
  }
  processing[s] = false;
}

int main()
{
  int n,m,a,b;
  scanf("%d %d",&n,&m);
  std::vector<int> adj[n+1];
  std::vector<bool> visited(n+1, false);
  std::vector<int> processing(n+1, 0);
  for(int i=1;i<=m;i++)
  {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    // adj[b].push_back(a);
  }

  for(int i=1;i<=n;i++)
  {
    if(visited[i] == false)
      DFS(adj, i, visited, processing);
  }
  printf("%d\n",check);
  return 0;
}
