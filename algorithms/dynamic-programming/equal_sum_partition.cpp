#include<bits/stdc++.h>

using namespace std;

bool equal_sum(int n, int sum, int set[]){
	if(sum==0){
		return true;
	}
	else if(n==0){
		return false;
	}

	if(set[n-1]<=sum){
		return equal_sum(n-1, sum-set[n-1], set)||equal_sum(n-1, sum, set);
	}
	else{
		return equal_sum(n-1, sum, set);
	}
}

int main(){

	int n, i=0, sum, set_sum=0;

	cout<<"Enter Number of Elements :: ";
	cin>>n;

	int set[n];

	cout<<"Enter Elements :: ";
	for(i=0; i<n; i++){
		cin>>set[i];
		set_sum+=set[i];
	}

	if(set_sum%2!=0){
		cout<<"Not Possible";
		exit(0);
	}
	else{
		sum=set_sum/2;
		if(equal_sum(n, sum, set)){
			cout<<"Possible";
		}
		else{
			cout<<"Not Possible";
		}
	}

	return 0;
}