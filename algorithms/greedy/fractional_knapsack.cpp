#include<bits/stdc++.h>

using namespace std;

struct item{
	int weight, profit;
	float ratio;
};

void sort_items_by_ratio(int n, struct item items[]){

	int i=0, j;
	struct item key;

	for(i=0; i<n; i++){
		key=items[i];
		j=i-1;
		while(j>=0 && items[j].ratio>key.ratio){
			items[j+1]=items[j];
			j=j-1;
		}
		items[j+1]=key;
	}
}

void knapsack(int n, int max_weight, struct item items[]){
	int i=n-1;
	float remain, w=0, profit=0;

	while(w<max_weight && i>=0){
		if(w+items[i].weight<=max_weight){
			w+=items[i].weight;
			profit+=items[i].profit;
		}
		else{
			remain=(max_weight-w)/items[i].weight;
			w+=(items[i].weight*remain);
			profit+=(items[i].profit*remain);
		}

		i--;
	}
		cout<<"\nMax Profit is "<<profit<<" and Current Weight is "<<w<<endl;
}

int main(){

	int n, i=0, max_weight, choice;


	cout<<"Enter Number of Items :: ";
	cin>>n;

	cout<<"Enter Max Weight :: ";
	cin>>max_weight;

	struct item items[n];

	for(i=0; i<n; i++){
		cout<<"Enter Weight and Profit for "<<i+1<<" Item :: ";
		cin>>items[i].weight>>items[i].profit;
		items[i].ratio=items[i].profit/items[i].weight;
	}

	sort_items_by_ratio(n, items);
	knapsack(n, max_weight, items);

	return 0;
}
