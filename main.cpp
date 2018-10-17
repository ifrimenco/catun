#include <bits/stdc++.h>
#define inf INT_MAX
#define nmax 36002
using namespace std;
vector <pair <int, int> > v[nmax];
vector <int> cost (nmax, inf);
int parinti[nmax];
int fortarete[nmax];
 int n, m, k;
 int x, gr, vf, vft;

void dijkstra ()
{

    vector <int> vtemp (nmax, inf);
    set <pair <int, int> > q;
    for (x=1; x<=k; ++x)
    {vtemp[fortarete[x]]=0;
    q.insert(make_pair(0,fortarete[x]));}
    while (!q.empty())
    {
        vf=(*q.begin()).second;
        q.erase(q.begin());
        vector <pair <int, int> > :: iterator it;
        for (it=v[vf].begin();it!=v[vf].end();++it)
        {
            vft=(*it).first;
            gr=(*it).second;
           if (vtemp[vft] > vtemp[vf] + gr )
           {
                 if (vtemp[vft] !=inf )
                q.erase(q.find(make_pair(vtemp[vft],vft)));
                vtemp[vft]=vtemp[vf]+gr;
                q.insert(make_pair(vtemp[vft],vft));
               if (parinti[vf]==-1) parinti[vft]=vf;
                else parinti[vft]=parinti[vf];
           }
           else if  (vtemp[vft]==vtemp[vf] + gr)
           {
                if (parinti[vf]==-1) parinti[vft]=min(parinti[vft],vf);
                else parinti[vft]=min(parinti[vft],parinti[vf]);

           }

        }
    }

    }


int main()
{
    ifstream f("catun.in");
    ofstream g("catun.out");
    int  i, j;
    f >> n >> m >> k;
    int x, y, z;
    for (i=1; i<=k; ++i)
       {f >> fortarete[i]; parinti[fortarete[i]] =-1; }

         for (i=1; i<=m; ++i)
         {
             f >> x >> y >> z;
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
         }
         vector <pair<int, int> > :: iterator it;
    dijkstra();
  for (i=1; i<=n; ++i)
    if (parinti[i]!=-1) g << parinti[i] << " ";
  else g << 0 << " ";
  g << "\n";
    return 0;

}
