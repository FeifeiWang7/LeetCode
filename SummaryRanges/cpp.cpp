class Solution { public:

vector<string> summaryRanges(vector<int>& nums) {

    vector<string> result;
    for(int i = 0; i < nums.size();)
    {
        int j = i + 1;
        while(j < nums.size() && ((j-i) == (nums[j]-nums[i]))) j++;  //(j-i) == (nums[j]-nums[i])

        if(j-1 > i)
        {
            result.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
        }
        else
        {
            result.push_back(to_string(nums[i]));
        }

        i = j; //Update i
    }

    return result;
}
};


/////
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if (nums.empty()) return ans;

    int l = nums[0], r = nums[0];
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == r + 1) r++;
        else{
            if (l == r)
                ans.push_back(to_string(l));
            else
                ans.push_back(to_string(l) + "->" + to_string(r));
            l = r = nums[i];
        }
    }

    if (l == r)
        ans.push_back(to_string(l));
    else
        ans.push_back(to_string(l) + "->" + to_string(r));

    return ans;
}
////
class Solution { public: vector summaryRanges(vector& nums) { vector res; if (nums.empty()) return res; string curr; curr += to_string(nums[0]); int start = 0; int end = 1;

    while (end < nums.size()) {
        int tmp = start;
        while (nums[end] == nums[tmp] + 1 && end < nums.size()) {
            end++;
            tmp++;
        }

        if (nums[tmp] != nums[start])   curr = curr + "->" + to_string(nums[tmp]);
        res.push_back(curr);
        curr.clear();

        if (end == nums.size()) {
            break;
        }
        else {
            start = end;
            end = start + 1;
            curr += to_string(nums[start]);
        }

    }

    if (!curr.empty())
        res.push_back(curr);

    return res;
}
};

///////
class Solution { public: vector summaryRanges(vector& nums) { string item; vector ret; int start, end,prev,i; if(nums.size()==0) return {};

    if(nums.size()==1)
        {
        ret.push_back(to_string(nums[0]));
        return ret;
        }

    start=nums[0];
    end=nums[0];
    prev=nums[0];

    for(i=1;i<nums.size();i++)
        {
            end=nums[i];
            if(i==(nums.size()-1))
                if((end-prev)==1)
                    ret.push_back(to_string(start)+"->"+to_string(end));
                else
                    if(start==prev)
                        {
                        ret.push_back(to_string(start));
                        ret.push_back(to_string(end));
                        }
                    else
                        {
                        ret.push_back(to_string(start)+"->"+to_string(prev));
                        ret.push_back(to_string(end));
                        }
            else
                if((end-prev)!=1)
                    if(start==prev)
                        {
                        ret.push_back(to_string(start));
                        start=end;
                        prev=end;
                        }
                    else
                        {
                        ret.push_back(to_string(start)+"->"+to_string(prev));
                        start=end;
                        prev=end;
                        }
                else
                    prev=end;
        }

    return ret;

  }
};
///////
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; 
        stringstream sstm;
        if(nums.size()==0){
            return res;
        }

        int start;
        start = nums[0];
        int index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=start+i-index){
                if(nums[i-1] == start){
                    sstm<<start;
                    res.push_back(sstm.str());
                    sstm.str("");
                    start = nums[i];
                    index = i;
                }
                else if(nums[i-1]> start){
                    sstm<<start;
                    sstm<<"->";
                    sstm<<nums[i-1];
                    res.push_back(sstm.str());
                    sstm.str("");
                    start = nums[i];
                    index =i;
                }
            }
            if(i == nums.size()-1){
                if(nums[i]==start){
                    sstm<<start;
                    res.push_back(sstm.str());
                    sstm.str("");
                    start = nums[i];
                    index = i;
                }else{
                    sstm<<start;
                    sstm<<"->";
                    sstm<<nums[i];
                    res.push_back(sstm.str());
                    sstm.str("");
                    start = nums[i];
                    index =i;
                }
            }
        }

        return res;

    }
};
///////
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> ranges;
        if(!len){
            return ranges;
        }
        int start = 0 , end = 0;

        while(end+1 < len){
            if(nums[end]+1 != nums[end+1]){
                if(start == end){
                    ranges.push_back(to_string(nums[start]));
                }else{
                    ranges.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                }
                start = end+1;
            }
            end++;
        }
        if(start == end){
            ranges.push_back(to_string(nums[start]));
        }else{
            ranges.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
        }
        return ranges;
    }
};
To solve this there are two pointers 'start' and 'end' which keeps track of where the range lies. Keep iterating the end pointer and check if the next value lies within range . if not , update start and end pointers and push back to the list. If start == end it means we have just one element in that range otherwise more than one. Last code it because we are left with last range of elements. Please comment for further improvement.

/////
vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        string str;
        if(nums.size()==0)
            return ret;
        int start = nums[0];   
        int end=0;
        for(int i=1;i<nums.size();i++){
            str = to_string(start);
            if(nums[i]==nums[i-1]+1)
                end = nums[i];
            if(nums[i]!=nums[i-1]+1){
                if(end != 0)
                    str = str + "->" + to_string(end);
                ret.push_back(str);
                start = nums[i];
                end = 0;
            }
        }
        if(end!=0)
            str = to_string(start) + "->" + to_string(end);
        if(end==0)
            str = to_string(start);
        ret.push_back(str);
        return ret;
    }
/////
class Solution {
public:
vector<string> summaryRanges(vector<int>& nums) {

    vector<string> res;
    if (nums.size() == 0) return res;


    int pos = 0;
    while(pos <nums.size())
    {
        string cur;
        int p = pos +1;
        cur += to_string(nums[pos]);
        while(p < nums.size() && nums[p] == (nums[p-1] + 1))
        {
            p++;
        }

        if (p!= (pos + 1))
        {
            cur += "->";
            cur += to_string(nums[p-1]);
        }
        res.push_back(cur);

        pos = p;
    }
    return res;
}
};
