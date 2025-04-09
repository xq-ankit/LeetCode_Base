class Solution {
public:
using ll=long long;
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        
        ll low=-1e10;
        ll high=1e10;
        ll ans=0;
        while(low<=high){
            ll mid=(low+high)/2;
            if(countproduct(nums1,nums2,mid)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    ll countproduct(vector<int>& nums1, vector<int>& nums2, ll dot_product){
        ll total_count=0;
        for(int e:nums1){
            int c=0;
            int low=0;
            int high=nums2.size()-1;
            if(e>=0){
                while(low<=high){
                    int mid=(low+high)/2;
                    if((long)e*nums2[mid]<=dot_product){
                        c=mid+1;
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                total_count+=c;
            }
        else{
            while(low<=high){
                    int mid=(low+high)/2;
                    if((long)e*nums2[mid]<=dot_product){
                        c=nums2.size()-mid;
                       high=mid-1;
                    }
                    else{
                        low=mid+1;
                    }
                }
                total_count+=c;
            }

        }
        return total_count;
        }

};