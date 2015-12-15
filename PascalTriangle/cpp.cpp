vector<vector<int> > generate(int numRows) {
    vector<vector<int> > vvi;
    if (numRows<=0) return vvi;
    for (int i=1; i<=numRows; i++) {
        vector<int> vi(i, 1);
        for (int j=1; j<i-1; j++) vi[j] = vvi[i-2][j-1]+vvi[i-2][j];
        vvi.push_back(vi);
    }
    return vvi;
}
///
just do it in a straightforward, each time generate a new line, first push all 1 vector into res and then update the elements from 1 to i-1.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};

///
vector<vector<int>> generate(int numRows) {

    vector<vector<int>> grid(numRows);

    // 1. Create and initialize grid
    for(int i = 0; i  < grid.size(); i++){

        // Insert 0's
        for(int j = 0; j < i+1; j++) grid[i].push_back(0);

        // insert 1's
        grid[i][0] = 1; 

    }

    // 2. Perform pascal operation
    for(int i = 1; i < grid.size(); i++){

        int a,b;
        for(int j = 1; j <= i; j++){

            int a = grid[i-1][j-1];
            int b;

            if(j == i) b = 0;
            else b = grid[i-1][j];

            grid[i][j] = a + b;

        }
    }

    return grid;

}
///
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret(numRows, vector<int>());
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<=i; j++) {
                ret[i].push_back(j == 0 ? 1 : j == i ? 1 : ret[i-1][j-1] + ret[i-1][j]);
            }
        }
        return ret;
    }
};
///
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res = {};
        for (int i = 0; i < numRows; i++) {
            res.push_back(vector<int>(i + 1, 1));
            for(int j = 1; j < i; j++) {
                res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]);
            }
        }
        return res;
    }
};
//////
class Solution {
public:
    vector< vector<int> > generate(int numRows) {
    vector< vector<int> > answer;
    if (numRows==0)
    return answer;
    vector<int> result(1,1); //one int with value 1, result(how_many, value)
    answer.push_back(result); // result = [1], answer = [1];
    for (int i=1;i!=numRows;++i){
        result.insert(result.begin(),1); // result = [1, 1] for i=1; result = [1, 1, 1] for i=2; result = [1, 1, 2, 1] for i=3; 
        for (int j=1;j!=result.size()-1;++j){
            result[j]=result[j]+result[j+1]; // result = [1, 1+1, 1] for j=1, i=2; result = [1, 1+2, 2, 1] for j=1, i=3; result = [1, 3, 2+1, 1] for j=2, i=3;
        }
    answer.push_back(result); //answer = [[1], [1,1]] for i=1; answer = [[1], [1,1], [1,2,1]] for i=2; answer = [[1], [1,1], [1,2,1], [1, 3, 3, 1]] for i=3;
    }
    return answer;
    }
};
