#include<stdio.h>
#include<iostream>
#include<cstring>
#define MAX_W 500000
#define MAX_H 10

using namespace std;

int W,H;
char map[MAX_H][MAX_W];

void test(){
	for(int i = 0; i < 10; i++)
		cout<<i<<"  ";
	for(int i = 10; i < W; i++)
		cout<<i<<" ";
	cout<<endl;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++)
			cout<<map[i][j]<<"  ";
		cout<<endl;
	}
}
/*
int cache[MAX_W][MAX_H][3][2];
int search(int locate, int h, int flag){
	if(locate > W || h < 0 || h >= H) return 0;
	if(locate == W) return locate;
	if(map[h][locate] == '#') return locate;
	if(h == 0) return search(locate + 1, h + 1, 0); 
	
	int &ret = cache[locate][h][flag];
	if(ret != -1) return ret;
	
	ret = locate;
	//map[h][locate] = '@';
	//test();
	//cout<<endl;
	if(h == H - 1){
		ret = max(ret, search(locate + 1, h, 0,1));
		ret = max(ret, search(locate + 1, h - 1, 1,1));
	}else if( flag == 0){
		ret = max(ret, search(locate + 1, h + 1, 0,jump));
		if(jump == 1) 
			ret = max(ret, search(locate + 1, h - 1, 1, 2));
	}else if( flag == 1){
		if(h == 0) 
			ret = max(ret, search(locate + 1, h + 1, 0,jump)); 
		else
			ret = max(ret, search(locate + 1, h - 1, 1,jump));
	}
	
	//map[h][locate] = '.';
	return ret;
}*/
/*
bool jumpOk = true;
bool jump(int locate, int heght, int &nextLocation, bool &jumpOk){
	//cout<<" locate "<<locate<<" heght "<<heght<<" nextLocation "<<nextLocation<<endl;
	int i;
	for(i = heght; i >= 0; i--){
		if(locate >= W || map[i][locate] != '.'){
			nextLocation = locate;
			break;
		}
		locate++; 
	}
	if(locate == W || i != -1) {
		if(locate == W) nextLocation = W;
		jumpOk = false;
		return false;
	}
	jumpOk = true;
	if(i == -1) locate--;
	for(i = 0; i < H; i++){
		if(locate >= W || map[i][locate ] != '.'){
			nextLocation = locate;
			break;
		} 
		locate++;
	}
	//cout<<" locate "<<locate <<" nextLocation "<<nextLocation<<endl;
	
	if(locate == W || i != H){ 
		if(locate == W) nextLocation = W;
		return false;
	}
	nextLocation = locate -1;
	//cout<<" nextLocation "<<nextLocation<<endl;
	return true;
}
int cache[MAX_W];
int search(int locate){//wrong answer
	//cout<<" locate "<<locate<<" map "<<map[H - 1][locate]<<endl;
	if(locate == W) return W;
	if(map[H - 1][locate] != '.' ) return locate;
	
	int &ret = cache[locate];
	if(ret != -1) return ret;
	
	int res = search(locate + 1);
	int nextLocation = locate, i;
	
	if(!jump(locate,H - 1,nextLocation,jumpOk)) res = max(res,nextLocation);
	else res = max(res,search(nextLocation) );
	
	if(!jumpOk) return ret = res;
	locate += H - 1;
	for(int i = 0; i < H; i++){
		//cout<<"  locate "<<locate + i<<" heght "<<i<<" nextLocation "<<nextLocation<<endl;
		if((locate + i < W) && (map[i][locate + i] == '.')){
			if(!jump(locate+i,0+i,nextLocation,jumpOk)){
				res = max(res, nextLocation);
				//cout<<"   locate "<<locate + i<<" heigh "<<i<<" nextLocation "<<nextLocation<<endl;
			}else{
				res = max(res, search(nextLocation));
			}
		}else{
			res = max(res,locate + i);
			break;
		}
	}
	return ret = res;
}*/

int search(int locate);

bool up(int locate, int hight, int &next){
	//cout<<"up()"<<endl;
	int i = hight - 1;
	for(; i>= 0; i--){
		if(++locate == W || map[i][locate] == '#'){
			next = locate;
			break;
		}
	}
	if(locate == W || i != -1) return false;
	next = locate;
	return true;
}

int down(int locate, int jump){
	//cout<<"down()"<<endl;
	int i = 1, res = 0, next = locate;
	for(; i < H; i++){
		if(++locate == W || map[i][locate] == '#'){
			res = max(res,locate);
			break;
		}else if(jump == 1){
			if(!up(locate,i,next)) res = max(res,next);
			else res = max(res,down(next,jump + 1));
		}
	}
	if(i == H) res = max(res,search(locate));
	return res;
}

int search2(int locate);
int upAndDown(int locate, int hight, int jump){
	//cout<<"upAmdDown("<<locate<<","<<jump<<","<<hight<<")"<<endl;
	int i = hight - 1, res = 0;
	for(; i>= 0; i--){
		if(++locate == W || map[i][locate] == '#'){
			break;
		}
	}
	if(locate == W || i != -1) return locate;
	
	i = 1;
	for(; i < H; i++){
		if(++locate == W || map[i][locate] == '#'){
			res = max(res,locate);
			break;
		}else if(jump == 1){
			res = max(res, upAndDown(locate,i,jump + 1));
		}
	}
	if(i == H) res = max(res,search2(locate));
	return res;
}

int cache[MAX_W];
int search(int locate){ // problem : stack Overflow
	//cout<<"search("<<locate<<")"<<endl;
	if(locate == W) return W;
	if(map[H-1][locate]=='#') return locate;
	
	int& ret = cache[locate];
	if(ret != -1) return ret;
	
	int res = max(locate,search(locate + 1));
	
	int next = locate;
	if(!up(locate,H-1,next)) res = max(next,res);
	else res=max(res,down(next,1));
	
	return ret = res;
}
int search2(int locate){
	//cout<<"search2("<<locate<<")"<<endl;
	if(locate == W) return W;
	if(map[H-1][locate]=='#') return locate;
	
	int& ret = cache[locate];
	if(ret != -1) return ret;
	
	int res = max(locate,search2(locate + 1));
	res = max(res,upAndDown(locate,H - 1,1));
	
	return ret = res;
}
	

int main(void){
	freopen("CogiRunInput.txt","r",stdin);
	int M;
	scanf("%d",&M);
	while(M--){
		memset(cache,-1,sizeof(cache));
		scanf("%d %d",&W,&H);
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++){
				scanf("%c",&map[i][j]);
				if(map[i][j] =='\n') j--;
			}
		//test();
		//cout<<search(0,H - 1,0)<<endl;
		cout<<search2(0)<<endl;
	}
}