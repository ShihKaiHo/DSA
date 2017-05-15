#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d%d", &N, &M);

	vector < unordered_map <int, int> > path_data(N); //<index, number>

	for(int times=0;times<M;times++){
		int operation;
		scanf("%d", &operation);
		//printf("operation = %d\n", operation);
		if(operation == 0){
			int a, b;
			scanf("%d%d", &a, &b);

			if(a != b){
				if(path_data[a].find(b) != path_data[a].end() && path_data[b].find(a) != path_data[b].end()){
					path_data[a][b] ++;
					path_data[b][a] ++;
				}else{ // no appearance before
					path_data[a][b] = 1;
					path_data[b][a] = 1;
				}
			}
		}

		if(operation == 1){
			int c, d;
			scanf("%d%d", &c, &d);
			if(path_data[c].find(d) != path_data[c].end() && path_data[d].find(c) != path_data[d].end()){ // the path really exists
				path_data[c][d] --;
				path_data[d][c] --;

				if(path_data[c][d] == 0){
					path_data[c].erase(d);
					path_data[d].erase(c);
				}
			}
		}

		if(operation == 2){
			int good = 1;

			int K;
			scanf("%d", &K);

			if(K > 0){
				int *k_list = new int [K];
				int buff;
				unordered_map <int, bool> check;

				for(int i=0;i<K;i++){
					scanf("%d", &buff);
					if(check.find(buff) == check.end()) check[buff] = true;
					k_list[i] = buff;
				}

				for(int i=0;i<K;i++){
					if(0 <= k_list[i] && k_list[i] < N){
						for(unordered_map<int, int>::iterator it = path_data[k_list[i]].begin(); it != path_data[k_list[i]].end(); it++){
							if(check.find(it->first) == check.end()){
								good = 0;
								break;
							}
						}
					}else{
						good = 0;
					}

					if(good == 0)
						break;
				}
				delete [] k_list;
			}
			printf("%d\n", good);

		}
	}
	return 0;
}
