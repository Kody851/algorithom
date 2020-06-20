#include<iostream>
//#include<stdc++.h>
#include<vector>
using namespace std;
void insertionSort(vector<pair<string,int>>&arr, int t){
    if(arr.empty() || (t!=0 && t!=1)) return;
    for(int i=1;i<arr.size();i++){
        if(t==1){
            for(int j=i-1; j>=0 && arr[j].second>arr[j+1].second; j--){
                swap(arr[j],arr[j+1]);            }
        }
        else{
            for(int j=i-1; j>=0 && arr[j].second<arr[j+1].second; j--){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<pair<string,int>>input;
    //while(1){
        
        for(int i=0;i<n;i++){
            string name;
            int grade;
            cin>>name>>grade;
            input.push_back(make_pair(name,grade));
        }
    //}
    
    //swap(input[0].second,input[1].second);
    insertionSort(input, t);
    for(int i=0;i<n;i++){
        cout<<"ans:";
        //cout<<"size:"<<input.size();
        cout<<input[i].first<<" "<<input[i].second<<"\n";
    }
       
    return 0;
    
}