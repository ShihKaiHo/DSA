#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <cstring>
using namespace std;

int current_time=0;
struct Node
{
    Node* children[2];
    int IP_due_time;
    int mask_keeping_time;
    Node():IP_due_time(0),mask_keeping_time(0),children{nullptr}
    {}
};

Node* get_new_node()
{
    Node* newnode=new Node;
    return newnode;
}

void insert_node(Node* root,bitset<32>&  IP,int& mask,int& last_time)
{
    Node* parent=root;
    for(int i=31;i>(31-mask);i--)
    {
        if(parent->children[IP[i]]==nullptr)
            parent->children[IP[i]]=get_new_node();
        parent=parent->children[IP[i]];
    }
    parent->mask_keeping_time=last_time;
    return;
}

void print_IP(bitset<32>& IP)
{
    bitset<32> temp;
    bitset<32> mask(255);
    printf("Your device has the ip address ");
    temp = (IP>>24);
    printf("%lu.",temp.to_ulong());
    temp = ( ( IP>>16 ) & mask );
    printf("%lu.",temp.to_ulong());
    temp = ( ( IP>>8 ) & mask );
    printf("%lu.",temp.to_ulong());
    temp = IP & mask;
    printf("%lu\n",temp.to_ulong());
}

void ask_for_IP(Node* root,bitset<32>&  IP)
{
    Node* parent=root;
    bool is_available=0;
    int keeping_time=0;

    for( int i=31; i >= 0 ; i--)
    {
        if( parent->mask_keeping_time > 0 )
        {
            is_available=true;
            if(keeping_time==0)
                keeping_time = parent->mask_keeping_time;
        }
        if(parent->children[IP[i]]==nullptr)
            parent->children[IP[i]]=get_new_node();
        parent=parent->children[IP[i]];
    }
    if( parent->mask_keeping_time > 0 )
    {
        is_available=true;
        if(keeping_time==0)
            keeping_time= parent->mask_keeping_time;
    }
    if(!is_available)
    {
        printf("Invalid\n");
        return;
    }
    else if(current_time <= parent->IP_due_time)
    {
        printf("HahahaXD You are too late\n");
        return;
    }
    else
    {
        parent->IP_due_time=current_time+keeping_time;
        print_IP(IP);
        return;
    }
    return;
}

int main()
{
    int n,mask,last_time;
    scanf("%d",&n);
    int operation;
    Node* root=get_new_node();

    bitset<32> IP(0);
    char* temp;
    char IP_string[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&operation);
        switch(operation)
        {
            case 1:
                {
                    scanf("%s",IP_string);
                    for(int j=3;j>=0;j--)
                    {
                        if(j==3)
                            temp = strtok (IP_string," ./");
                        else
                            temp = strtok (nullptr," ./");
                        IP |= bitset<32>(atoi(temp))<<(j*8);
                        //cout<<IP<<endl;
                    }
                    temp = strtok (nullptr," ./");
                    mask = atoi(temp);
                    scanf("%d",&last_time);
                    insert_node(root,IP,mask,last_time);
                    break;
                }
            case 2:
                {
                    scanf("%s",IP_string);
                    for(int j=3;j>=0;j--)
                    {
                        if(j==3)
                            temp = strtok (IP_string," ./");
                        else
                            temp = strtok (nullptr," ./");
                        IP |= bitset<32>(atoi(temp))<<(j*8);
                    }
                    ask_for_IP(root,IP);
                    break;
                }
        }
        IP.reset();
        current_time++;
    }
    return 0;
}
