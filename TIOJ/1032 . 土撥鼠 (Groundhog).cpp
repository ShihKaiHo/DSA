#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

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
                auto got=tunnel[a].find(b);
                if(got==tunnel[a].end())
                {
                    tunnel[a][b]=1;
                    tunnel[b][a]=1;
                }
                else
                {
                    got->second++;
                    tunnel[b][a]++;
                }
                break;
            }
            case 1:
            {
                scanf("%d %d",&a,&b);
                tunnel[a][b]--;
                tunnel[b][a]--;
                break;
            }
            case 2:
            {
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    scanf("%d",&k);
                    seeing_hole.push_back(k);
                }
                int stop=1;
                for(auto it=seeing_hole.begin();it!=seeing_hole.end();it++)
                {
                    if(stop==0)
                        break;
                    for(auto it2=tunnel[*it].begin();it2!=tunnel[*it].end();it2++)
                    {
                        if(stop==0)
                            break;

                        for(auto it3=seeing_hole.begin();it3!=seeing_hole.end();it3++)
                        {
                            if(it2->first=*it3 && it2->second<=0)
                            {
                                stop=0;
                                printf("0\n");
                                break;
                            }
                        }
                    }
                }
                printf("1\n");
                seeing_hole.clear();
                break;
            }
        }
    }

    //printf("%d %d",num_of_hole,num_of_query);
    return 0;
}
