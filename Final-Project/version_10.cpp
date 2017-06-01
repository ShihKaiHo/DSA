#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>

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

bool str_cmp(const string & s1, const string & s2){
	return (s1 < s2);
}

void output(int ID_N, vector < State> & myans, long long int min_step){
	printf("minimum steps: %lld\n", min_step);
	printf("output: %lu\n", myans.size());

	vector <string> mystr;
	for(int i=0;i<myans.size();i++){
		Node * ptr = myans[i].ptr_tree;
		vector <long long int> buff_vec(min_step + 1);
		long long int idx = min_step;
		string buff_str = "";
		while(ptr != NULL){
			buff_vec[idx] = ptr->id;
			idx --;
			ptr = ptr->parent;
		}
		for(int j=0;j<buff_vec.size();j++){
			long long int buff = buff_vec[j];
			buff_str += "(";
			for(int k=0;k<ID_N;k++){
				if(k == 0) buff_str += to_string(buff % 64);
				else buff_str += "," + to_string(buff % 64);
				buff = (buff >> 6);
			}
			buff_str += ")";
		}
		mystr.push_back(buff_str);
	}

	sort(mystr.begin(), mystr.end(), str_cmp);

	for(int i=0;i<mystr.size();i++){
		printf("%s\n", mystr[i].c_str());
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

int GCD(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	return ((a >= b) ? GCD(b, a % b) : GCD(a, b % a));
}

bool check(int ID_N, int * cap, int * init_state, int * final_state){
	int mygcd = cap[0];
	for(int i=0;i<ID_N;i++){
		if(final_state[i] > cap[i])
			return false;
		mygcd = GCD(mygcd, cap[i]);
		mygcd = GCD(mygcd, init_state[i]);
	}
	for(int i=0;i<ID_N;i++){
		if(final_state[i] % mygcd != 0)
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int ID_N; //ID_N # of ID
	scanf("%d", &ID_N);

	int cap[ID_N]; //max value of each ID
	int init_state[ID_N], final_state[ID_N];
	for(int i=0;i<ID_N;i++)
		scanf("%d", &cap[i]);

	long long int init = 0, final = 0;
	for(int i=0;i<ID_N;i++){  //turn initial and final state to long long int form
		long long int buff;
		scanf("%lld", &buff);
		init += (buff << (6 * i));
		init_state[i] = buff;
	}
	for(int i=0;i<ID_N;i++){  //turn initial and final state to long long int form
		long long int buff;
		scanf("%lld", &buff);
		final += (buff << (6 * i));
		final_state[i] = buff;
	}
	if(!check(ID_N, cap, init_state, final_state)) printf("-1\n");
	else solver(ID_N, cap, init, final); //solve the problem
	return 0;
}
