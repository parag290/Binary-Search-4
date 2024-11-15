


/**
 * 
 * Approach 1 : using hashmap 
 * 
 * Time complexity = o(m+n)
 * Space complexity = o(n)
 * 
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return intersect(nums2, nums1);

        vector<int>result;
        unordered_map<int, int>hMap;

        for(int i=0; i<n1; i++){
            if(hMap.find(nums1[i]) == hMap.end()){
                hMap[nums1[i]] = 1;
            } else {
                hMap[nums1[i]]++;
            }
        }

        for(int i=0; i<n2; i++){
            if(hMap.find(nums2[i]) != hMap.end()){
                result.push_back(nums2[i]);
                hMap[nums2[i]]--;
                if(hMap[nums2[i]] == 0){
                    hMap.erase(nums2[i]);
                }
            }
        }

        return result;
    }
};