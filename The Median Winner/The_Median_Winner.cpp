#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct comparator
{
    bool operator()(int i, int j)
    {
        return i > j;
    }
};

priority_queue<int,vector<int>, comparator> minHeap;
priority_queue<int> maxHeap;
bool median;

int get_median()
{
    if(median==1)
        return minHeap.top();
    else
        return maxHeap.top();
}

void adjust_heap()
{
    if(minHeap.size()-maxHeap.size()==2)
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    else if(maxHeap.size()-minHeap.size()==2)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    if(maxHeap.size()==minHeap.size() || maxHeap.size()>minHeap.size())
    {
        median=0;
    }
    else
        median=1;
    return;
}

int current_median()
{
    if(minHeap.size()==maxHeap.size())
        return (minHeap.top()+maxHeap.top())/2;
    else if(minHeap.size()>maxHeap.size())
        return minHeap.top();
    else
        return maxHeap.top();
}

int current_winner()
{
    if(median)
        return minHeap.top();
    else
        return maxHeap.top();
}

void kick_out_median()
{
    cout<<"Player ID:"<<current_winner()<<" is out!\n";
    if(median==1)
        minHeap.pop();
    else
        maxHeap.pop();
    adjust_heap();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio (false);

    int n;
    cin>>n;
    int operation;
    int temp;
    cin>>operation;
    cin>>temp;
    maxHeap.push(temp);
    median=0;

    for(int i=1;i<n-1;i++)
    {
        cin>>operation;
        switch(operation)
        {
            case 1:
                {
                    cin>>temp;
                    if(temp>get_median())
                        minHeap.push(temp);
                    else
                        maxHeap.push(temp);

                    adjust_heap();
                    break;
                }
            case 2:
                {
                    cout<<"Current median ID:"<<current_median()<<'\n';
                    break;
                }
            case 3:
                {
                    kick_out_median();
                    break;
                }
        }
    }
    cin>>operation;
    cout<<"The winner ID: "<<current_winner()<<"!!!\n";
 return 0;
}
