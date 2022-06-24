#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

typedef long long ll;

using namespace std;

//----------------------

typedef pair<int,int>ii;
typedef vector<ii>vii;
typedef vector<int>vi;
#define MAX 102	

int N, T;

int graph[MAX];
float x[MAX], y[MAX];


//----------------------


int main(){_

	float w, min, dist, dx, dy;
	int count, minPrim;

	cin >> T;
	while(T--){
		
		cin >> N;

		memset(graph, 0, sizeof(graph));
		
		for(int i = 0; i < N; ++i){
				cin >> x[i] >> y[i];
		}

		graph[0] = 1;
		count = 1;
		w = 0.0;

		while(count < N){
			min = -1.0;
		
		for(int i = 0; i < N; ++i){
				
				if(graph[i])
				
				for(int j = 0; j < N; ++j){
					
						if(!graph[j]){
							
							dx = x[i] - x[j];
							dy = y[i] - y[j];
							dist = sqrt(dx*dx + dy*dy);
						
							if(min == -1.0 or dist < min){
									min = dist;
									minPrim = j;
							}
						}

				}
			}

			graph[minPrim] = 1;
			w += min;
			count++;

		}

		printf("%.2f\n", w);
		
		if(T > 0) printf("\n");
				
	}



	return 0;

}

