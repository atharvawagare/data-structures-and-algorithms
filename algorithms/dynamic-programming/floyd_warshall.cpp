#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n, i=0, j=0, k=0;
    
    cout<<"Enter No of Vertices :: ";
    cin>>n;
    
    int graph[n][n];
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                cout<<"Enter Weight of Edge from "<<i+1<<" to "<<j+1<<" :: ";
                cin>>graph[i][j];
            }
        }
    }
    
    cout<<"\n\nGraph Before Processing"<<endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i!=j){
                    graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]);
                }
            }
        }
    }
    
    cout<<"\n\nGraph After Processing"<<endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
}