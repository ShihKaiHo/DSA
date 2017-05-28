#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

int check_is_good(int visit,vector<unordered_map<int,int>>& tunnel,unordered_map<int,bool>& check,unordered_map<int,bool>& is_visit)
{
    if (is_visit.find(visit)!=is_visit.end())
    {
        return 1;
    }
    if(check.find(visit)==check.end())
    {
        return 0;
    }
    is_visit[visit]=true;
    for(auto it= tunnel[visit].begin();it!=tunnel[visit].end();it++)
    {
        if(is_visit.find(it->first)==is_visit.end())
        {
            if( !check_is_good(it->first,tunnel,check,is_visit))
                return 0;
        }
    }
    return 1;
}

int main()
{
    int num_of_hole;
    int num_of_query;
    int action;

    vector<int> seeing_hole;
    int a, b;
    int n;
    int k;
    scanf("%d %d",&num_of_hole,&num_of_query);
    vector<unordered_map<int,int>> tunnel(num_of_hole);
    for(int i=0;i<num_of_query;i++)
    {
        scanf("%d",&action);
        switch(action)
        {
            case 0:
            {
                scanf("%d %d",&a,&b);
                if(a>num_of_hole||b>num_of_hole||a==b)
                    break;
                auto got=tunnel[a].find(b);
                if(got==tunnel[a].end())
                {
                    tunnel[a][b]=1;
                    tunnel[b][a]=1;
                }
                else
                {
                    tunnel[a][b]++;
                    tunnel[b][a]++;
                }
                break;
            }
            case 1:
            {
                scanf("%d %d",&a,&b);
                if(a>num_of_hole||b>num_of_hole||a==b)
                    break;
                if(tunnel[a].find(b) != tunnel[a].end())
                {
                    tunnel[a][b] --;
                    tunnel[b][a] --;

                    if(tunnel[a][b] == 0)
                    {
                        tunnel[a].erase(b);
                        tunnel[b].erase(a);
                    }
                }
                break;
            }
            case 2:
            {
                scanf("%d",&n);
                unordered_map<int,bool> check;
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&k);
                    check[k]=true;
                }
                unordered_map<int,bool> is_visit;
                int answer=1;
                for(auto it=check.begin();it!=check.end();it++)
                {
                    answer*=check_is_good(it->first,tunnel,check,is_visit);
                    if(answer==0)
                        break;
                }
                printf("%d\n",answer);
                break;
            }
        }
    }

    //printf("%d %d",num_of_hole,num_of_query);
    return 0;
}
