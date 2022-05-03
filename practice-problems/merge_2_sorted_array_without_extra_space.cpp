#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

void merge(int n, int v1[], int m, int v2[]){
	int i=0, j=0, k=n-1;
	while(i<=k && j<m){
		if(v1[i]<v2[j]){
			i++;
		}
		else{
			swap(&v1[k], &v2[j]);
			k--;
			j++;
		}
	}

	sort(v1, v1+n);
	sort(v2, v2+m);

	cout<<"Final Sorted Merged Array is :: ";
	for(i=0; i<n; i++){
		cout<<v1[i]<<" ";
	}

	for(i=n; i<n+m; i++){
		cout<<v2[i-n]<<" ";
	}
}

int main(){

	int n, m, x, i=0;
	cout<<"Enter Sizes of Array 1 & Array 2 :: ";
	cin>>n>>m;

	int v1[n], v2[m];

	cout<<"Enter Elements of Array 1 :: ";
	for(i=0; i<n; i++){
		cin>>v1[i];
	}

	cout<<"Enter Elements of Array 2 :: ";
	for(i=0; i<m; i++){
		cin>>v2[i];
	}

	sort(v1, v1+n);
	sort(v2, v2+m);
	merge(n, v1, m, v2);

	return 0;
}
