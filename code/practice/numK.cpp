#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int partition(vector<int>&a, int start, int end){
        int small = start-1;
        for(int i=start;i<end;i++){
            if(a[i]<a[end]){
                small++;
                if(i != small){
                    swap(a[i],a[small]);
                }
            }
        }
        small++;
        swap(a[end],a[small]);
        return small;
    }
    int helper(vector<int>&a, int start, int end, int K){
        int index = partition(a, start, end);
        if(index == K-1){
            return a[index];
        }
        else if(index < K-1){
            return helper(a, index+1, end, K);
        }
        else{
            return helper(a, start, index-1, K);
        }
    }
    int findKth(vector<int>& a, int n, int K) {
        return helper(a, 0, n-1, K);
    }
};

int main(){
    Solution solu;
    vector<int>a{1332802,1177178,1514891,871248,753214,123866,1615405,328656,1540395,968891,1884022,252932,1034406,1455178,821713,486232,860175,1896237,852300,566715,1285209,1845742,883142,259266,520911,1844960,218188,1528217,332380,261485,1111670,16920,1249664,1199799,1959818,1546744,1904944,51047,1176397,190970,48715,349690,673887,1648782,1010556,1165786,937247,986578,798663};
    int x = solu.findKth(a, 49,24);
    cout<<x<<"\n";
    for(auto i:a){
        cout<<i<<",";
    }
    cout<<"\n";
    sort(a.begin(),a.end());
    for(auto i:a){
        cout<<i<<",";
    }
    cout<<"\n";
    cout<<a[22]<<","<<a[23]<<","<<a[24]<<","<<a[25];

}