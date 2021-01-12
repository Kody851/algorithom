#include<iostream>
using namespace std;
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<vector>
#include<stack>

int process(vector<int>& arr, int index){
        if(index==0){
            return 1;
        }
        for(int i=0;i<index;i++){
            if(arr[index]==arr[i]){
                return process(arr, index-1);
            }
        }
        return process(arr, index-1) + 1;
    }
int maxLength(vector<int>& arr) {
        return process(arr, arr.size()-1);        
}

int main(){
    vector<int>arr{2,2,3,4,3};
    cout<<maxLength(arr);


    return 0;
}