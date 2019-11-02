#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<limits>

using namespace std; 


void _1991(){
	freopen("2250in.txt","w",stdout);
	srand((unsigned) time(NULL));
	
	int n = 10000;
	int i;
	cout<<n<<endl;
	for(i = 1; i < n; i++){
		cout<<i<<" "<<i+1<<" "<<-1<<endl;
	}
	cout<<i<<" "<<-1<<" "<<-1<<endl;
}

void _1654(){
	freopen("1654in.txt","w",stdout);
	srand((unsigned) time(NULL));
	
	int k = 10000;
	int N = 1000000;
	/*while(k > N){
		k = rand()%10000 + 1;
		N = rand()%1000000 + 1;
	}*/
	
	cout<<k<<" "<<N<<endl;
	for(int i = 0 ; i < k; i++)
		cout<<rand()%numeric_limits<int>::max()<<endl;
}

int main(void){
	_1654();
}