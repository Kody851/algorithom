class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        int m=array.size(),n=array[0].size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(array[i][j]==target) return true;
            else if(array[i][j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};