#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

//typedef unordered_map<int,long long int> news_map;

int main()
{
    int n;
    long long int deducted_score;
    scanf("%d %lld",&n,&deducted_score);
    unordered_map<int,long long int> news_score;
    int operation;
    int temp_ID;
    long long int temp_score;
    int n_update;

    int max_ID=-1;
    long long int max_score=-1;

    for (int i=0; i<n; i++)
    {
        scanf("%d",&operation);
        switch(operation)
        {
            case 1:
                scanf("%d %lld",&temp_ID,&temp_score);
                temp_score+=deducted_score*(news_score.size()+1);
                news_score[temp_ID]=temp_score;
                if(temp_score>=max_score)
                {
                    max_score=temp_score;
                    max_ID=temp_ID;
                }
                break;
            case 2:
                scanf("%lld %d",&temp_score,&n_update);
                for(int i=0;i<n_update;i++)
                {
                    scanf("%d",&temp_ID);
                    news_score[temp_ID]+=temp_score;
                    if(news_score[temp_ID]>=max_score)
                    {
                        max_score=news_score[temp_ID];
                        max_ID=temp_ID;
                    }
                }
                break;
            case 3:
                temp_score=max_score-deducted_score*news_score.size();
                printf("id: %d, value: %lld\n",max_ID,temp_score);
                break;
        }
    }
    return 0;
}
