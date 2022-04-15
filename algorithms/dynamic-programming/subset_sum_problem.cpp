#include<bits/stdc++.h>

using namespace std;

bool subset_sum(int n, int sum, int set[]){
	if(sum==0){
		return true;
	}
	else if(n==0){
		return false;
	}

	if(set[n-1]<=sum){
		return subset_sum(n-1, sum-set[n-1], set)||subset_sum(n-1, sum, set);
	}
	else{
		return subset_sum(n-1, sum, set);
	}
}

int main(){

	int n, i=0, sum;

	cout<<"Enter Number of Elements and Sum :: ";
	cin>>n>>sum;

	int set[n];

	cout<<"Enter Elements :: ";
	for(i=0; i<n; i++){
		cin>>set[i];
	}

	if(subset_sum(n, sum, set)){
		cout<<"Possible";
	}
	else{
		cout<<"Not Possible";
	}

	return 0;
}