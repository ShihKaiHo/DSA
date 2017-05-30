#include "game.h"
#include <unordered_map>
int trans(int p,int q,int s)
{
    return ((s<<6)+(p<<3)+q);
}
unordered_map<int,double> hash_table;
double D(int , int , double );
// My strategy to play the dice sum game
// Returns 0 for ten's position, 1 for one's position
int myStrategy(int gameState[4][2], int diceValue){
	static int initialized;		// Static variable, default to zero
	// Add your declaration of DP structure here
	if (!initialized){
		initialized=1;
		// Populate your structure here
		D(4,4,0);
	}
	int tenAvailCount=0;	// No. of available ten's position
	for (int j=0; j<4; j++)
		if (gameState[j][0]<=0) {tenAvailCount=4-j; break;}
	int oneAvailCount=0;	// No. of available one's position
	for (int j=0; j<4; j++)
		if (gameState[j][1]<=0) {oneAvailCount=4-j; break;}
	if ((tenAvailCount!=0)&&(oneAvailCount==0)) return(0);  //only ten left
	if ((tenAvailCount==0)&&(oneAvailCount!=0)) return(1);  //only one left
//	My strategy
	int strategy=3;
	int nextPos, total;
	switch(strategy){
		case 1:
			nextPos=rand()%2;
			break;
		case 2:
			nextPos=0;
			total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
			if (total+diceValue*10>SCOREMAX)
				nextPos=1;
			break;
		case 3:
			// Add your own strategy (which uses the DP structure) here
			total=(gameState[0][0]+gameState[1][0]+gameState[2][0]+gameState[3][0])*10
					+(gameState[0][1]+gameState[1][1]+gameState[2][1]+gameState[3][1]);
			if(hash_table[trans(tenAvailCount-1,oneAvailCount,total+diceValue*10)]>hash_table[trans(tenAvailCount,oneAvailCount-1,total+diceValue)])
                nextPos=0;
            else
                nextPos=1;
			break;
		default:
			printf("Error!\n");
	}
	return(nextPos);
}

double D(int p, int q, double s)
{
    int temp=trans(p,q,s);
    if(s>150)
    {
        if(hash_table.find(temp)==hash_table.end())
            hash_table[temp]=0.0;
        return 0;
    }
    else if(p==0 && q==0)
    {
        if(hash_table.find(temp)==hash_table.end())
            hash_table[temp]=s;
        return s;
    }
    else if(p==0)
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=D(p,q-1,s+i)/6.0;}
        }
        return hash_table[temp];
    }
    else if(q==0)
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=D(p-1,q,s+i*10)/6.0;}
        }
        return hash_table[temp];
    }
    else
    {
        if(hash_table.find(temp)==hash_table.end())
        {
            hash_table[temp]=0;
            for(int i=1;i<=6;i++){hash_table[temp]+=MAX(D(p-1,q,s+i*10),D(p,q-1,s+i))/6.0;}
        }
        return hash_table[temp];
    }
}
