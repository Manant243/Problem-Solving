class Solution {
public:
    int search(vector<int>& a, int k) {
       int l=0;
       int h=a.size()-1;
       while(l<h){
            int mid=(l+h)/2;
            if(a[mid]==k) return mid;
            if(a[l]<=a[mid]){
                if(k>=a[l] && k<a[mid]){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(k<=a[h] && k>a[mid]){
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        if(a[l]==k)
        return l;
        else return -1;
    }
};