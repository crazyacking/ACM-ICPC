#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
//int czy[100001];
long long tab[100], tab2[100];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		unsigned long long a,b;
		scanf("%llu%llu", &a, &b);
		b++;
		for(int i=1; i<=64; i++){
			tab[i]=a%2;
			a/=2;
			tab2[i]=b%2;
			b/=2;
		}	
	
			int k=0;
			for(int i=64; i>=1; i--)
				if(tab[i]==0 && tab2[i]==1){
					k=i;
					break;
				}
			for(int i=1; i<k; i++)
				tab[i]=1;
			unsigned long long p=1;
			unsigned long long c=0;
			for(int i=1; i<=64; i++){
				c+=p*tab[i];
				p*=2;
			}
				printf("%llu\n", c);
	}
	
}
