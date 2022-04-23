#include<bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int w, int n){
	if(n==0 || w==0){
		return 0;
	}

	if(wt[n-1]<=w){
		return max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
	}
	else if(wt[n-1]>w){
		return knapsack(wt, val, w, n-1);
	}
}

int main(){

	int n, w, i=0;

	cout<<"Enter Value of N and W :: ";
	cin>>n>>w;
	
	int wt[n], val[n];

	cout<<"Enter Weight Array :: ";
	for(i=0; i<n; i++){
		cin>>wt[i];
	}

	cout<<"Enter Value Array :: ";
	for(i=0; i<n; i++){
		cin>>val[i];
	}

	cout<<"Maximum Possible Gain is :: "<<knapsack(wt, val, w, n);

	return 0;
}
