#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;


int isPrime(int k){
	
	for(int i = 2; i <= sqrt(k); i++){
			if(k % i == 0)
				return 0;
	}

	return 1;
}


int main(){_

	int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
	int n;

	while(cin >> n && n){
		
		int factor[25] = {0};
		int val = 0;
		int lim = 25;

		for(int i = n ; i >= 2; i--){
				int index = i;
				for(int j = 0; j < lim; j++){
						while(index % primes[j] == 0){
									factor[j]++;
									index /= primes[j];
						}

						if(isPrime(index) == 1) break;
							
				}

				for(int j = 0; j < lim; j++){
						if(primes[j] == index){
								factor[j]++;
								break;
						}
				}
		}
		
			for(int j = lim - 1; j >= 0; j--){
					if(factor[j] != 0){
							val = j;
							break;
						}
			}
					 
			printf("%d! =", n);

			for(int i = 0; i <= val; i++){
					printf(" %d", factor[i]);
			}
	
		printf("\n");		

	}

  return 0;
}


