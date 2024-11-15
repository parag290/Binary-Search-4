




/**
 * Approach 1 : Similar to merge sort
 * Combine two arrays into one array and find median from it
 * 
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>store;
        int idx1 = 0;
        int idx2 = 0;

        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] <= nums2[idx2]){
                store.push_back(nums1[idx1]);
                idx1++;
            } else {
                store.push_back(nums2[idx2]);
                idx2++;
            }
        }

        while(idx1 < nums1.size()){
            store.push_back(nums1[idx1]);
            idx1++;
        }

        while(idx2 < nums2.size()){
            store.push_back(nums2[idx2]);
            idx2++;
        }

        for(auto i : store){
            cout << i << " ";
        }
        int mid = store.size()/2;

        if(store.size()%2 == 1){
            return store[mid];
        } else {
            return static_cast<double>(store[mid] + store[mid-1])/2;
        }

        
    }
};