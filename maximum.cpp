class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n= arr.size();
        int pre =0;
        int suf =0;
        int maxi1 =INT_MIN;
        int maxi2 =INT_MIN;
        int del1=1;
        int del2=1;
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            pre +=arr[i];
            suf +=arr[j];
            maxi2 =max(maxi2,suf);
            maxi1=max(maxi1,pre);
            if(pre <0 && del1>0){
                pre = pre-arr[i];
                del1=0;
            }
            if (pre<0 && del1==0){
                pre =0;
                del1=1;
            }
            if(suf <0 && del2>0){
                suf = suf-arr[j];
                del2=0;
            }
             if(suf<0 && del2==0){
                suf =0;
                del2=1;
            }

        }
        int ans = max(maxi1,maxi2);

        return ans;        
    }
};
