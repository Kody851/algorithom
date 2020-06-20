#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<pair<string,int>>&arr, int t){//插入排序是稳定的，满足要求
    if(arr.empty() || (t!=0 && t!=1)) return;
    for(int i=1;i<arr.size();i++){
        if(t==1){//asc
            for(int j=i-1; j>=0 && arr[j].second>arr[j+1].second; j--){
                swap(arr[j],arr[j+1]);
            }
        }
        else{//desc
            for(int j=i-1; j>=0 && arr[j].second<arr[j+1].second; j--){
                swap(arr[j],arr[j+1]);
            }
        }
        
    }
}
int main(){
    int n,t;
    while(cin>>n>>t){//整体需要在while中，否则输入会出错
        vector<pair<string,int>>input;
        for(int i=0;i<n;i++){
            string name;
            int grade;
            cin>>name>>grade;
            input.push_back(make_pair(name,grade));
        }
        insertionSort(input, t);
        for(int i=0;i<n;i++){
            cout<<input[i].first<<" "<<input[i].second<<"\n";
        }
    }
    return 0;
    
}