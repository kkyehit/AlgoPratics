#include "stdConvert.h"
#define MAX_N 5
#include <algorithm>
#include <math.h>

void setStd(){
	char in[] = "RootsInput.txt";
	char out[] = "Output.txt";
	convertStd c(in,out);
}

void test(vector<double> degree){
	for(int i = 0; i < degree.size(); i++)
		cout<<degree[i]<<" ";
	cout<<endl;
}

int n;
vector<double> differential(vector<double> degree){
	if(degree.size() <= 1) return vector<double>(0);
	
	vector<double> res;
	int maxDegress = degree.size() - 1;
	while(maxDegress > 0){
		res.push_back(degree[0] * maxDegress);
		maxDegress--;
		degree.erase(degree.begin());
	}
	return res;
}

vector<double> solve(vector<double> degree){
	vector<double> res;
	if(degree.size() == 2){
		res.push_back(-degree[1]/degree[0]);
	}
	else if(degree.size() == 3){
		res.push_back((-degree[1] + 
					   sqrt(degree[1]*degree[1] - 4* degree[0]*degree[2]) ) 
					  /  (2 * degree[0] ) );
		res.push_back((-degree[1] - 
					   sqrt(degree[1]*degree[1] - 4* degree[0]*degree[2]) ) 
					  /  (2 * degree[0] ) );
		if(res[0] == res[1])
			res.erase(res.begin());
	}
	sort(res.begin(), res.end() );
	return res;
}
double getY(double x, vector<double> degree){
	double y = 0;
	int maxDegress = degree.size() - 1;
	while(maxDegress > 0){
		y += pow(x,maxDegress--)*degree[0];
		degree.erase(degree.begin());
	}
	y+=degree[0];
	return y;
}

vector<double> search(vector<double> degree){
	int maxDegress = degree.size() - 1;
	
	if(maxDegress <= 2 ) return solve(degree);
	
	vector<double> deriv = differential(degree);
	vector<double> inflection = search(deriv);
	
	inflection.insert(inflection.begin(), -100);
	inflection.insert(inflection.end(), 100);
	vector<double> res;
	for(int i = 0; i < inflection.size() -1; i++){
		double x1 = inflection[i], x2 = inflection[i+1];
		double y1 = getY(x1,degree), y2 = getY(x2,degree);
		
		if(y1*y2 > 0) continue;
		if(y1 > y2){
			swap(y1,y2);
			swap(x1,x2);
		}
		for(int iter = 0; iter < 100; iter++){
			double midX = (x1 + x2) / 2;
			double midY = getY(midX,degree);
			if(y1*midY > 0){
				y1 = midY;
				x1 = midX;
			}else{
				y2 = midY;
				x2 = midX;
			}
		}
		res.push_back((x1 + x2) / 2);
	}
	sort(res.begin(), res.end() );
	return res;
}

int main(void){
	setStd();
	int C;
	double temp;
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		vector<double> degree;
		scanf("%d",&n);
		for(int j = 0; j <= n; j++){
			scanf("%lf",&temp);
			degree.push_back(temp);
		}
		vector<double> res = search(degree);
		for(int j = 0; j < res.size(); j++)
			printf("%0.12lf ",res[j]);
		printf("\n");
	}
}