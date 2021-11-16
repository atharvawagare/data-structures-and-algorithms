#include<iostream>
#include<math.h>

using namespace std;

// ---------------------- Get Parity Function Below ----------------------------------------
int getParityBit(int start, int end, int array[]){
	int i, count_one;

	for(i=start+1; i<=end; i++){
		if(i&start){
			if(array[i]==1){
				count_one++;
			}
		}
	}

// --------------- Check for Even Parity of Bits -------------------------------------------
	if(count_one%2==0){
		return 0;
	}
	else{
		return 1;
	}
// ------------------------------------------------------------------------------------------
}

// ----------------------------------- Main Function Below ----------------------------------
int main(){

	int m, r, i=0, j=0;
	int index;
// ------------------- Accepting Input ------------------------------------------------------
	cout<<"No of Data Bits : ";
	cin>>m;

	int dataBits[m]={0};

	cout<<"Input Data Bits : ";
	for(i=0; i<m; i++){
		cin>>dataBits[i];
	}
// -----------------------------------------------------------------------------------------

// --------------------------- Determining count of redundant bits -------------------------
	i=0;
	while(++i>0){
		if(pow(2, i)>=(m+i+1)){
			r=i;
			break;
		}
	}
// -----------------------------------------------------------------------------------------

// ---------------- Generating Hamming Code Array ------------------------------------------
	int hammingCode[m+r]={0};

	for(i=0; i<r; i++){
		index=pow(2, i)-1;
		hammingCode[index]=-1;
	}

	for(i=0; i<m+r; i++){
		if(hammingCode[i]!=-1){
			hammingCode[i]=dataBits[j++];
		}
	}
// ------------------------------------------------------------------------------------------

// --------------------- Calling a Parity Bit Generation Function ---------------------------
	for(i=0; i<r; i++){
		index=pow(2, i)-1;
		hammingCode[index]=getParityBit(index, m+r, hammingCode);
	}
// ------------------------------------------------------------------------------------------
	
// ---------------------- To Print the Hamming Code Array -----------------------------------
	cout<<"The Generated Hamming Code for Given Message Bits is ";
	for(i=0; i<m+r; i++){
		cout<<hammingCode[i]<<" ";
	}
// ------------------------------------------------------------------------------------------
	return 0;
}
