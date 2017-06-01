#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define MAX_INT (2147483647)

typedef struct state
{
	int pos;
	int step;
}State;

void solver(int N, int init, int final, vector < unordered_map <int, bool> > & has_path, int & ans, bool & can){
	queue <State> myqueue;
	State buff;
	buff.pos = init;
	buff.step = 0;
	myqueue.push(buff);

	int first = 1;

	if(init == final){
		ans = 0;
		can = true;
		return;
	}

	while(!myqueue.empty()){
		State frontstate = myqueue.front();
		myqueue.pop();

		if(!first && frontstate.step > ans){
			return;
		}

		for(unordered_map<int, bool>::iterator it = has_path[frontstate.pos].begin(); it != has_path[frontstate.pos].end(); it ++){
			State buff;
			buff.pos = it->first;
			buff.step = frontstate.step + 1;
			if(buff.step <= N) myqueue.push(buff);

			if(first && it->first == final){
				ans = buff.step;
				first = 0;
				can = true;
			}
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int N; //total dot number;
	scanf("%d", &N);

	vector < unordered_map < int, bool >  >  has_path(N);

	for(int i=0;i<N;i++){
		int Num; // there are Num numbers in the following;
		scanf("%d", &Num);
		for(int j=0;j<Num;j++){
			int buff;
			scanf("%d", &buff);
			has_path[i][buff] = true;
		}
	}

	int init, final, ans = MAX_INT;
	bool can = false;
	scanf("%d%d", &init, &final);

	solver(N, init, final, has_path, ans, can);
	if(can) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}