The idea is very simple: just extract the numbers from each version number and compare the numbers from beginning to the end. However, C++ seems to have no split functions like those of Java and Python. So we need to split it by our code. A final note, remember to handle version numbers of different lengths.

The code is as follows.

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = version(version1);
        vector<int> v2 = version(version2);
        int m = v1.size(), n = v2.size(), i, j;
        for (i = 0, j = 0; i < m && j < n; i++, j++)
            if (v1[i] > v2[j]) return 1;
            else if (v1[i] < v2[j]) return -1;
        while (i < m && v1[i++]) return 1;
        while (j < n && v2[j++]) return -1;
        return 0;
    }
private:
    vector<int> version(string& version) {
        int n = version.length();
        string vs;
        vector<int> v;
        for (int i = 0; i <= n; i++) {
            if (i == n || version[i] == '.') { 
                v.push_back(stoi(vs));
                vs.clear();
                if (i == n) break;
            }
            else vs += version[i];
        }
        return v;
    }
};
These two lines in the above handle the case of version numbers with different lengths.

while (i < m && v1[i++]) return 1;
while (j < n && v2[j++]) return -1;
We may also implement version using some system functions like stringstream and getline.

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = version(version1);
        vector<int> v2 = version(version2);
        int m = v1.size(), n = v2.size(), i, j;
        for (i = 0, j = 0; i < m && j < n; i++, j++)
            if (v1[i] > v2[j]) return 1;
            else if (v1[i] < v2[j]) return -1;
        while (i < m && v1[i++]) return 1;
        while (j < n && v2[j++]) return -1;
        return 0;
    }
private:
    vector<int> version(string& version) {
        version += "."; 
        stringstream vs(version);
        vector<int> v;
        string t;
        while (getline(vs, t, '.'))
            v.push_back(stoi(t));
        return v;
    }
};
