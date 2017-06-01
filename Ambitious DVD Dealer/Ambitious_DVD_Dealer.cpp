#include <cstdio>
#include <iostream>
#define MAX(x,y)	((x)>(y)?(x):(y))
#define MIN(x,y)	((x)<(y)?(x):(y))
#define MAX_INT 2147483647
#include <vector>
#include <unordered_map>
#define PRINT(x)	{cout << #x << "=" << x << " (line=" << __LINE__ << ", file=" << __FILE__ << ")" << endl;}
using namespace std;

int trans(int i, int j)
{
    return (i<<10)+j;
}
struct Time
{
    int disk;
    int minute;
};

Time my_min(const Time left,const Time right)
{
    if(left.disk<right.disk)
        return left;
    else if(right.disk<left.disk)
        return right;
    else if(left.minute<=right.minute)
        return left;
    else
        return right;
}

int min_disk(Time a)
{
    if(a.minute>0)
        return a.disk+1;
    else
        return a.disk;
}
int x;
int num_of_song, num_of_disk, disk_capacity;
vector<int> length_of_song;
unordered_map<int,Time> hash_table;

Time g(int ,int );
int main()
{
    int temp,temp2;
    scanf("%d",&x);
    for(int j=0;j<x;j++)
    {
        scanf("%d %d %d",&num_of_song,&num_of_disk,&disk_capacity);
        //num_of_song=4; num_of_disk=2; disk_capacity=5;
        length_of_song.push_back(0);
        temp2=num_of_song;
        for(int i=0;i<temp2;i++)
        {
            scanf("%d",&temp);
            if(temp>disk_capacity)
            {
                num_of_song--;
                continue;
            }
            length_of_song.push_back(temp);
        }
        for(int i=num_of_song;i>=0;i--)
        {
            if(min_disk(g(num_of_song,i))<=num_of_disk)
            {
                printf("%d\n",i);
                break;
            }
            if(i==0)
                printf("0\n");
        }

        hash_table.clear();
        length_of_song.clear();
    }
    return 0;
}
Time g(int pre_song,int choose_song)
{
    int trans_ID=trans(pre_song,choose_song);
    if(hash_table.find(trans_ID)!=hash_table.end())
    {
        return hash_table[trans_ID];
    }
    else if(choose_song==0)
    {
        Time temp;
        temp.disk=0;
        temp.minute=0;
        hash_table[trans_ID]=temp;
        return temp;
    }
    else if(pre_song==choose_song)
    {
        if(length_of_song[pre_song]<=disk_capacity-g(pre_song-1,choose_song-1).minute)
        {
            Time temp;
            temp.disk=g(pre_song-1,choose_song-1).disk;
            temp.minute=g(pre_song-1,choose_song-1).minute+length_of_song[pre_song];
            hash_table[trans_ID]=temp;
            return temp;
        }
        else
        {
            Time temp;
            temp.disk=g(pre_song-1,choose_song-1).disk+1;
            temp.minute=length_of_song[pre_song];
            hash_table[trans_ID]=temp;
            return temp;
        }
    }
    else if(length_of_song[pre_song]>disk_capacity)
    {
        Time temp=g(pre_song-1,choose_song);
        hash_table[trans_ID]=temp;
        return temp;
    }
    if(length_of_song[pre_song]<=disk_capacity-g(pre_song-1,choose_song-1).minute)
    {
        Time temp;
        temp.disk=g(pre_song-1,choose_song-1).disk;
        temp.minute=g(pre_song-1,choose_song-1).minute+length_of_song[pre_song];
        temp=my_min(g(pre_song-1,choose_song),temp);
        hash_table[trans_ID]=temp;
        return temp;
    }
    else
    {
        Time temp;
        temp.disk=g(pre_song-1,choose_song-1).disk+1;
        temp.minute=length_of_song[pre_song];
        temp=my_min(g(pre_song-1,choose_song),temp);
        hash_table[trans_ID]=temp;
        return temp;
    }
}
