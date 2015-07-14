class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    list<int> list1, list2;
    list<int>::iterator it_list;
    vector<int> vv;

    if (m == 0 && n == 0) return;
    else if (m == 0 && n != 0){
        nums1.clear();
        for (int i = 0; i < n; i++){
            nums1.push_back(nums2[i]);
        }
        //nums2.clear();
    }
    else if (m != 0 && n != 0){
        for (int i = 0; i < m; i++){
            list1.push_back(nums1[i]);
        }
        for (int i = 0; i < n; i++){
            list2.push_back(nums2[i]);
        }
        list1.merge(list2);
        nums1.clear();
        for (it_list = list1.begin(); it_list != list1.end(); it_list++){
            nums1.push_back(*it_list);
        }
    }

}
};
