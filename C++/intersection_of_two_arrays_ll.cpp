class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> dic;
        vector<int> result;
        
        for(int i = 0; i < nums1.size(); i++) {
            if(dic.find(nums1[i]) == dic.end()) dic[nums1[i]] = 1;
            else if(dic.find(nums1[i]) != dic.end()) dic[nums1[i]] ++;
        }
        
        for(int i = 0; i < nums2.size(); i++) {
            if(dic.find(nums2[i]) != dic.end() && dic[nums2[i]] != 0) {
                result.push_back(nums2[i]);
                dic[nums2[i]] --;
            }
        }
        
        return result;
    }
};
