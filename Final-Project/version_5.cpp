#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct node
{
	long long int id;
	struct node * parent;
}Node;

typedef struct state
{
	long long int id;
	long long int step;
	Node * ptr_tree;
}State;

//ID_N <= 5; each element <= 63;

void show(int ID_N, State & buff){
	printf("%lld\n", buff.step);
	Node * ptr = buff.ptr_tree;
	vector <long long int> mystep;

	while(ptr != NULL){
		mystep.push_back(ptr->id);
		ptr = ptr->parent;
	}
/*
	for(int i=mystep.size() - 1;i>=0;i--){
		if(i == mystep.size() - 1) printf("%lld", mystep[i]);
		else printf("% lld", mystep[i]);
	}
*/
	for(int i=mystep.size() - 1;i>=0;i--){
		if(i != mystep.size() - 1) printf("  ");

		long long int buff = mystep[i];
		for(int j=0;j<ID_N;j++){
			if(j == 0) printf("%lld", buff % 64);
			else printf(",%lld", buff % 64);
			buff = (buff >> 6);
		}
	}

	printf("\n");
}

void key(int ID_N, int * cap, long long int state, vector < long long int > & can_go){
	int* now=new int[ID_N];
	for(int i=0;i<ID_N;i++){ //turn state to int form
		now[i] = state % 64;
		state = (state >> 6);
	}
	//filled in
	for(int i=0;i<ID_N;i++){
		if(now[i] != cap[i]){
			long long int buff = 0;
			for(int j=0;j<ID_N;j++){
				if(j == i){
					buff += (cap[j] << 6 * j);
				}else{
					buff += (now[j] << 6 * j);
				}
			}
			can_go.push_back(buff);
		}
	}

	//clear
	for(int i=0;i<ID_N;i++){
		if(now[i] != 0){
			long long int buff = 0;
			for(int j=0;j<ID_N;j++){
				if(j != i){
					buff += (now[j] << (6 * j));
				}
			}
			can_go.push_back(buff);
		}
	}

	//fill one to other
	for(int i=0;i<ID_N;i++){
		for(int j=0;j<ID_N;j++){
			if(i != j && now[i] != 0 && now[j] != cap[j]){
				long long int buff = 0;
				if(now[i] > cap[j] - now[j]){
					for(int k=0;k<ID_N;k++){
						if(k == i) buff += ((now[i] - cap[j] + now[j]) << (6 * k));
						else if(k == j) buff += ((cap[j]) << (6 * k));
						else buff += (now[k] << (6 * k));
					}
				}else{
					for(int k=0;k<ID_N;k++){
						if(k == i) buff += 0;
						else if(k == j) buff += ((now[j] + now[i]) << (6 * k));
						else buff += (now[k] << (6 * k));
					}
				}
				can_go.push_back(buff);
			}
		}
	}
	delete [] now;
	return;
}

void solver(int ID_N, int * cap, long long int init, long long int final){
	queue <State> myqueue;//define state queue

    //create root
	Node * root = new Node;
	root->id = init;
	root->parent = NULL;

	//initialize
	State buff;
	buff.id = init;
	buff.step = 0;
	buff.ptr_tree = root;

	myqueue.push(buff);

	long long int min_step = -1;

	//check the state has been visited
	unordered_map < long long int, long long int> been;
	been[init] = 0;

    //BFS
	while(!myqueue.empty()){
		State front_state = myqueue.front();
		myqueue.pop();

		if(min_step != -1 && front_state.step >= min_step) //if further steps are larger, break
			break;

		vector < long long int > can_go; //find state child
		key(ID_N, cap, front_state.id, can_go);

		for(int i=0;i<can_go.size();i++){
			if(been.find(can_go[i]) == been.end() || been[can_go[i]] >= front_state.step + 1){//check visited and check no turning back
				been[can_go[i]] = front_state.step + 1;

				//new buffer to put in queue
				State buff;
				buff.id = can_go[i];
				buff.step = front_state.step + 1;

				//new Node to put int tree
				Node * child = new Node;
				child->id = buff.id;
				child->parent = front_state.ptr_tree;

				buff.ptr_tree = child;

				if(buff.id == final){
					if(min_step == -1){
						min_step = buff.step;
					}
					show(ID_N, buff);
				}
				myqueue.push(buff);
			}
		}
	}
	if(min_step == -1){
		printf("-1\n");
	}
}

int main(int argc, char const *argv[])
{
	int ID_N, T;//ID_N # of code ,T # of query
	scanf("%d%d", &ID_N, &T);

	int* cap=new int[ID_N];//max value of each code
	for(int i=0;i<ID_N;i++)
		scanf("%d", &cap[i]);

	for(int t=0;t<T;t++){//turn initial and final state to long long int form
		long long int init = 0, final = 0;
		for(int i=0;i<ID_N;i++){
			long long int buff;
			scanf("%lld", &buff);
			init += (buff << (6 * i));
		}
		for(int i=0;i<ID_N;i++){
			long long int buff;
			scanf("%lld", &buff);
			final += (buff << (6 * i));
		}
		solver(ID_N, cap, init, final);//solve the problem
	}
	delete [] cap;
	return 0;
}
