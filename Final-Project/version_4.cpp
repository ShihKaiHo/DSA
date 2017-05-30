#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define MAX_INT (2147483647)

typedef struct node
{
	int idx;
	struct node * parent;
} Node;

typedef struct state
{
	int pos;
	int step;
	Node * tree_ptr;
}State;

void show(State & buff){
	Node * node_ptr = buff.tree_ptr;
	vector < int > record;
	while(node_ptr != NULL){
		record.push_back(node_ptr->idx);
		node_ptr = node_ptr->parent;
	}
	for(int i=record.size() - 1; i >= 0; i --){
		printf("%d ", record[i]);
	}
	printf("\n");
	return;
}

void solver(int N, int init, int final, vector < unordered_map <int, bool> > & has_path){
	queue <State> myqueue;
	bool can = false;
	int ans = MAX_INT;

	unordered_map <int, int> been;
	been[init] = 0;

	Node * root = new Node; // tree;
	root->idx = init;
	root->parent = NULL;

	State buff;
	buff.pos = init;
	buff.step = 0;
	buff.tree_ptr = root;

	myqueue.push(buff);

	int first = 1;

	if(init == final){
		ans = 0;
		can = true;
		printf("%d\n", init);
		return;
	}

	while(!myqueue.empty()){
		State frontstate = myqueue.front();
		myqueue.pop();

		if(!first && frontstate.step >= ans){
			break;
		}

		for(unordered_map<int, bool>::iterator it = has_path[frontstate.pos].begin(); it != has_path[frontstate.pos].end(); it ++){
			if(been.find(it->first) == been.end() || been[it->first] >= frontstate.step + 1){
				been[it->first] = frontstate.step + 1;
				State buff;
				buff.pos = it->first;
				buff.step = frontstate.step + 1;
			
				Node * child = new Node;
				child->idx = buff.pos;
				child->parent = frontstate.tree_ptr;

				buff.tree_ptr = child;

				if(buff.step <= N){
					myqueue.push(buff);
				}

				if(it->first == final){
					if(first){
						can = true;	
						first = 0;
						ans = buff.step;
					}
					show(buff); // when the state is created, the answer is printed;
				}
			}
		}
	}

	if(can) printf("min = %d\n----------\n", ans);
	else printf("-1\n----------\n");
	return;
}

int main(int argc, char const *argv[])
{
	int N, T; //total dot number; times of evolution;
	scanf("%d%d", &N, &T); // <- N, T;

	vector < unordered_map < int, bool >  >  has_path(N);

	for(int i=0;i<N;i++){
		int Num; // there are Num numbers in the following;
		scanf("%d", &Num); // <- Num;
		for(int j=0;j<Num;j++){
			int buff;
			scanf("%d", &buff); // <- the node which is pointed; 
			has_path[i][buff] = true;
		}
	}

	for(int times=0;times<T;times++){
		int operation, from, to, init, final;
		scanf("%d%d%d%d%d", &operation, &from, &to, &init, &final); // <- operation, from, to, query of init, query of final;

		if(operation == 0){
			if(has_path[from].find(to) != has_path[from].end()){
				has_path[from].erase(to);
			}
		}

		if(operation == 1){
			has_path[from][to] = true;
		}

		solver(N, init, final, has_path);
	}
	return 0;
}