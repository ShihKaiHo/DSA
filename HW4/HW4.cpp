#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

//typedef unordered_map<int,long long int> news_map;
void insert_heap( vector<int>& news_heap,int& ID,long long int& score,unordered_map<int,long long int>& news_score,unordered_map<int,int>& news_pos)
{
    news_heap.push_back(ID);
    news_score[ID]=score;
    news_pos[ID]=news_heap.size()-1;
    while( news_pos[ID]!=1 )
    {
        int parent_ID=news_heap[news_pos[ID]/2];
        if(news_score[parent_ID]>score)
            break;
        news_heap[news_pos[ID]]=parent_ID;
        news_heap[news_pos[ID]/2]=ID;
        news_pos[parent_ID]=news_pos[ID];
        news_pos[ID] /=2;
    }
    return;

}

void update_score( vector<int>& news_heap,int& ID,long long int& score,unordered_map<int,long long int>& news_score,unordered_map<int,int>& news_pos)
{
    news_score[ID]=news_score[ID]+score;
    while( news_pos[ID]!=1 )
    {
        int parent_ID=news_heap[news_pos[ID]/2];
        if(news_score[parent_ID]>news_score[ID])
            return;
        news_heap[news_pos[ID]]=parent_ID;
        news_heap[news_pos[ID]/2]=ID;
        news_pos[parent_ID]=news_pos[ID];
        news_pos[ID] /=2;
    }
    return;
}
int main()
{
    int n;
    long long int deducted_score;
    if(scanf("%d %lld",&n,&deducted_score)){}
    unordered_map<int,long long int> news_score;
    unordered_map<int,int> news_pos;
    vector<int> news_heap;
    news_heap.reserve(1000000);
    news_heap.push_back(-1);
    int operation;
    int temp_ID;
    long long int temp_score;
    int n_update;

    for (int i=0; i<n; i++)
    {
        if(scanf("%d",&operation)){}
        switch(operation)
        {
            case 1:
                //printf("case 1\n");
                if(scanf("%d %lld",&temp_ID,&temp_score)){}
                temp_score+=deducted_score*news_heap.size();
                insert_heap(news_heap,temp_ID,temp_score,news_score,news_pos);
//                for(auto it=news_heap.begin()+1;it!=news_heap.end();it++)
//                {
//                    cout<<*it<<' '<<news_score[*it]<<endl;
//                }
//                cout<<endl;
                break;
            case 2:
                if(scanf("%lld %d",&temp_score,&n_update)){}
                for(int i=0;i<n_update;i++)
                {
                    if(scanf("%d",&temp_ID)){}
                    update_score(news_heap,temp_ID,temp_score,news_score,news_pos);
                }
//                for(auto it=news_heap.begin()+1;it!=news_heap.end();it++)
//                {
//                    cout<<*it<<' '<<news_score[*it]<<endl;
//                }
//                cout<<endl;
                break;
            case 3:
//                printf("case 3\n");
                temp_ID=news_heap[1];
                temp_score=news_score[temp_ID]-(news_heap.size()-1)*deducted_score;
                printf("id: %d, value: %lld\n",temp_ID,temp_score);
                break;
        }
    }
    return 0;
}
