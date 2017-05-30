#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node // the object which is a tree and is aim to find the trace of BFS
{
	long long int id;
	struct node * parent;
}Node;

typedef struct state // the object which is put in queue
{
	long long int id;
	long long int step;
	Node * ptr_tree;
}State;

//ID_N <= 5; each element <= 63;

bool cmp(const vector < long long int > & v1, const vector < long long int > & v2){  //compare function for output sequence
	for(int i=0;i<v1.size();i++){
		if(v1[i] < v2[i]){
			return true;
		}
		if(v1[i] > v2[i]){
			return false;
		}
	}
	return false;
}
/*
void show(int ID_N, State & buff){//print the output
	Node * ptr = buff.ptr_tree;
	vector <long long int> mystep;
	while(ptr != NULL){
		mystep.push_back(ptr->id);
		ptr = ptr->parent;
	}
	for(int i=mystep.size() - 1;i>=0;i--){
		if(i == mystep.size() - 1) printf("%lld", mystep[i]);
		else printf("% lld", mystep[i]);
	}
	for(int i=mystep.size() - 1;i>=0;i--){
		if(i != mystep.size() - 1) printf(" ");
		printf("(");
		long long int buff = mystep[i];
		for(int j=0;j<ID_N;j++){
			if(j == 0) printf("%lld", buff % 64);
			else printf(",%lld", buff % 64);
			buff = (buff >> 6);
		}
		printf(")");
	}
	printf("\n");
}
*/
void show_id(int ID_N, long long int id){
	printf("(");
	for(int i=0;i<ID_N;i++){ //turn state to int form
		if(i == 0) printf("%lld", id % 64);
		else printf(",%lld", id % 64);
		id = (id >> 6);
	}
	printf(")");
	return;
}

void output(int ID_N, vector < State> & myans, long long int min_step){
	printf("minimum steps: %lld\n", min_step);
	printf("output: %lu\n", myans.size());

	vector < vector < long long int > > myvec(myans.size());
	for(int i=0;i<myans.size();i++){
		Node * ptr = myans[i].ptr_tree;
		myvec[i].assign(min_step + 1, 0);

		int idx = min_step;
		while(ptr != NULL){
			myvec[i][idx] = ptr->id;
			idx --;
			ptr = ptr->parent;
		}
	}

	sort(myvec.begin(), myvec.end(), cmp);

	for(int i=0;i<myvec.size();i++){
		for(int j=0;j<myvec[i].size();j++){
			show_id(ID_N, myvec[i][j]);
		}
		printf("\n");
	}

	return;
}

void key(int ID_N, int * cap, long long int state, vector < long long int > & can_go){
	int now[ID_N];
	for(int i=0;i<ID_N;i++){
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
	return;
}

void solver(int ID_N, int * cap, long long int init, long long int final){
	queue <State> myqueue; //define state queue
	vector <State> myans; //vector to store the answer

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

	//use unordered_map to check if the state has been visited
	unordered_map < long long int, long long int> been;
	been[init] = 0;

	//BFS
	while(!myqueue.empty()){
		State front_state = myqueue.front();
		myqueue.pop();

		if(min_step != -1 && front_state.step >= min_step) //if further steps are larger, break
			break;

		vector < long long int > can_go; //find which door can go
		key(ID_N, cap, front_state.id, can_go);

		for(int i=0;i<can_go.size();i++){
			if(been.find(can_go[i]) == been.end() || been[can_go[i]] >= front_state.step + 1){ //check visited and check if turning back
				been[can_go[i]] = front_state.step + 1;

				//new buffer to put in queue
				State buff;
				buff.id = can_go[i];
				buff.step = front_state.step + 1;

				//new Node to put in the tree
				Node * child = new Node;
				child->id = buff.id;
				child->parent = front_state.ptr_tree;

				buff.ptr_tree = child;

				if(buff.id == final){
					if(min_step == -1){
						min_step = buff.step;
					}
					//show(ID_N, buff);
					myans.push_back(buff);
				}
				myqueue.push(buff);
			}
		}
	}
	if(min_step == -1){
		printf("-1\n");
		return;
	}
	output(ID_N, myans, min_step);
}

int main(int argc, char const *argv[])
{
	int ID_N; //ID_N # of ID
	scanf("%d", &ID_N);

	int cap[ID_N]; //max value of each ID
	for(int i=0;i<ID_N;i++)
		scanf("%d", &cap[i]);

	long long int init = 0, final = 0;
	for(int i=0;i<ID_N;i++){  //turn initial and final state to long long int form
		long long int buff;
		scanf("%lld", &buff);
		init += (buff << (6 * i));
	}
	for(int i=0;i<ID_N;i++){  //turn initial and final state to long long int form
		long long int buff;
		scanf("%lld", &buff);
		final += (buff << (6 * i));
	}
	solver(ID_N, cap, init, final); //solve the problem
	return 0;
}
