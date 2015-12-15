int maxPoints(vector<Point> &points) {
    int result = 0;
    for(int i = 0; i < points.size(); i++){
        int samePoint = 1;
        unordered_map<double, int> map;
        for(int j = i + 1; j < points.size(); j++){
            if(points[i].x == points[j].x && points[i].y == points[j].y){
                samePoint++;
            }
            else if(points[i].x == points[j].x){
                map[INT_MAX]++;
            }
            else{
                double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                map[slope]++;
            }
        }
        int localMax = 0;
        for(auto it = map.begin(); it != map.end(); it++){
            localMax = max(localMax, it->second);
        }
        localMax += samePoint;
        result = max(result, localMax);
    }
    return result;
}
/////
class Solution{
    public:
        int maxPoints(vector<Point> &points){
            if (points.size()<=2) return points.size();

            std::unordered_map<long long,int> map;
            int result=0,localmax,overlap,x,y,gcd,curr;
            long long key;

            for (unsigned int i=0,size=points.size();i<size;i++){
                if (result>=size-i) break;
                map.clear();
                localmax=0,overlap=0;
                for (unsigned int j=i+1;j<size;j++){
                    x=points[j].x-points[i].x;
                    y=points[j].y-points[i].y;
                    //check overlap
                    if ((x==0)&&(y==0)){
                        overlap++;
                        continue;
                    }
                    gcd=generateGCD(x,y);
                    x/=gcd; y/=gcd;
                    //Calculate the key by shifting left 'x' 32 bits, and then add 'y' 
                    key=0L;key+=x;key<<=32;key+=y;
                    //find x,then y;
                    int curr=++map[key];
                    localmax=max(curr,localmax);
                }
                result=max(result,localmax+overlap+1);
            }
            return result;
        }
    private:
        int generateGCD(int a, int b){
            if (b==0) return a;

            return generateGCD(b,a%b);

        }
    };
//////
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        auto comp = [] (Point& a, Point& b) { return a.x < b.x; };
        int n = points.size();
        int max_count = 0;
        std::sort(points.begin(), points.end(), comp);
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> slope_map;
            Point& p1 = points[i];
            int same_point = 1;
            int local_max = 1; // local max to get the number of points passing through max slope line starting at i

            // only look for points after the current one since ,
            // we have taken care of line segments before i with j when
            // running iteration for previous values of i
            for (int j = i+1; j < n; ++j) {
                double m = 0.0;
                Point& p2 = points[j];
                if (p1.x == p2.x && p1.y == p2.y) {
                    same_point++;
                    local_max = max(local_max, same_point);
                    continue;
                } else if (p1.x == p2.x) {
                    m = INT_MAX;
                } else {
                    m = ((double)(p2.y-p1.y))/(p2.x-p1.x);
                }
                if (slope_map.find(m) == slope_map.end()) {
                    slope_map[m] = same_point;
                }
                slope_map[m]++;
                local_max = max(local_max, slope_map[m]);
            }
            max_count = max(local_max, max_count);
        }
        return max_count;
    }
};
////
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        if(points.size()<=2) return points.size();
        int res=0;
        for(int i=0;i<points.size()-1;i++) {
            int numVertical=1,local=1,duplicate=0;
            unordered_map<double,int> map;
            for(int j=i+1;j<points.size();j++) 
                if(points[i].x==points[j].x) // special cases
                    if(points[i].y==points[j].y) // duplicate 
                        duplicate++;
                    else // vertical
                        numVertical++;
                else {
                    double slope=(points[i].y-points[j].y)*1.0/(points[i].x-points[j].x);
                    map[slope]==0?map[slope]=2:map[slope]++;
                    local=max(local,map[slope]);
                }
            local=max(local+duplicate,numVertical+duplicate);
            res=max(res,local);
        }
        return res;
    }
};
///
int maxPoints(vector<Point> &points) {
    unordered_map<float, int> statistic;   
        int maxNum = 0;       
        for (int i = 0; i< points.size(); i++)       
        {         
             statistic.clear();   
             statistic[INT_MIN] = 0; // for processing duplicate point  
             int duplicate = 1;        
             for (int j = i+1; j<points.size(); j++)        
             {         
                  if (points[j].x == points[i].x && points[j].y == points[i].y) // count duplicate  
                  {            
                       duplicate++;            
                       continue;          
                  }          
                  float key = (points[j].x - points[i].x) == 0 ? INT_MAX :   
                                 (float) (points[j].y - points[i].y) / (points[j].x - points[i].x);       
                  statistic[key]++;         
             }   
             for (unordered_map<float, int>::iterator it = statistic.begin(); it != statistic.end(); ++it)       
             {          
                  if (it->second + duplicate >maxNum)          
                  {           
                       maxNum = it->second + duplicate;          
                  }      
             }      
        }   
        return maxNum;
}
////
I sort the points first, which can avoid processing duplicated points.

int maxPoints(vector<Point>& points) {
    int ret = 0;
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2)
    {if (p1.x == p2.x) return p1.y < p2.y; else return p1.x < p2.x;});
    for (auto i = points.begin(); i != points.end(); ++i) {
        if (i != points.begin() && i->x == (i-1)->x && i->y == (i-1)->y) continue;
        unordered_map<float,int> m;
        int same = 1;
        for (auto j = i + 1; j != points.end(); ++j) {
            if (i->x == j->x && i->y == j->y) ++same;
            else if (i->x == j->x) ++m[(float)INT_MAX];
            else {
                float slope = (float)(j->y - i->y)/(j->x - i->x);
                ++m[slope];
            }
        }
        ret = max(ret, same);
        for (const auto& k:m) ret = max(ret, same + k.second);
    }
    return ret;
}
//////
This problem has a naive idea, which is to traverse all possible pairs of two points and see how many other points fall in the line determined by them. This idea is of O(n^3) time complexity and will meet TLE.

Well, let's focus on lines instead of pairs of points. Could we just find out how many points fall in all possible lines? The answer is yes. Remember that a line is determined by its slope and intercept. In fact, if two lines with the same slope share a common point, then they are just the same line. So to determine a line, we need its slope and a point.

Now comes the idea to solve this problem. We start from a specific point p, and compute all the slopes of the lines between p and the remaining points. Then those with the same slopes will be the same line. We can find out the maximum number of points fall on a line containing p. We exhaust all possible p's and record the largest number we have seen. This number is just answer.

Well, there are still two special cases to handle:

Duplicate points: a pair of duplicate points give no determined line, so we just count the number of duplicates and add them to the result.
Vertical lines: the slope of these lines is infinity mathematically. We simply set it to be INT_MAX in the following code.
Now we have the following code, using an unordered_map<float, int> slopes to record how many points fall in the line of a specific slope and containing points[i]. Since all the operations of unordered_map is O(1), this code is of O(n^2) complexity.

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> slopes;
        int maxp = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                float slope = (points[j].x == points[i].x) ? INT_MAX : 
                              (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                slopes[slope]++;
            }
            maxp = max(maxp, duplicate);
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp) 
                    maxp = slope.second + duplicate; 
        }
        return maxp;
    }
};
Well, since the representation of floating point numbers is sometimes inaccurate, we may use a more safer way to represent the slope (dy / dx), which is to record dx and dy in a pair<int, int>. However, once we use pair<int, int> for the key of the map, we cannot use an unordered_map since pair<int, int> is unhashable. We now change to map and the time complexity becomes O(n^2logn). Also, since dy = 4, dx = 2 and dy = 8, dx = 4 represents the same slope, we need to divide both of them by their gcd first.

The code is as follows. The logic is the same of the one above, just introducing pair and gcd.

class Solution { 
public: 
    int maxPoints(vector<Point>& points) {
        map<pair<int, int>, int> slopes;
        int maxp = 0, n = points.size();
        for (int i = 0; i < n; i++) {
            slopes.clear();
            int duplicate = 1;
            for (int j = i + 1; j < n; j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int dvs = gcd(dx, dy);
                slopes[make_pair(dx / dvs, dy / dvs)]++;
            }
            maxp = max(maxp, duplicate); 
            for (auto slope : slopes)
                if (slope.second + duplicate > maxp)
                    maxp = slope.second + duplicate;
        } 
        return maxp;
    }
private:
    int gcd(int num1, int num2) {
        while (num2) {
            int temp = num2; 
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
};

/////////
int maxPoints(vector<Point>& points) {
    int n = (int)points.size();
    if(n<3) return n;
    int result = 0;
    for(int i=0;i<n;i++) {
        int duplicate = 1;
        int localMax = 0;
        unordered_map<float,int> m;
        for (int j=i+1; j<n; j++) {
            if(points[j].x==points[i].x && points[j].y==points[i].y) duplicate++;
            else if(points[j].x==points[i].x) m[INFINITY]++;
            else {
                float k = (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                m[k]++;
            }
        }
        for(auto i=m.begin();i!=m.end();i++)
            localMax = max(localMax,i->second);
        result = max(result,localMax+duplicate);
    }
    return result;
}
/////
Quite standard solution. Go through each possible point (for i loop) and check all the lines that connect the point and one of the other points (for j loop); check if i and j are duplicated points, if so, increase samePt (duplicated point counter). otherwise, calculate the slope of the line i-j and updated the hashtable slopeMap. all the j points that have the same slope are on the same line (i.e. the line passing point i with the slope of "dy/dx"). Also for the duplicated points j (marked as checked), we don't need to check them anymore

class Solution {
public:
    int maxPoints(vector<Point>& points) {
       int pSize = points.size(), dx, dy, samePt, i, j, res=0, maxPt;
       if(pSize<3) return pSize;
       unordered_map<float, int> slopeMap;
       bool checked[pSize];
       fill_n(checked, pSize, false);
       for(i=0; i<pSize-res; ++i)
       {
            if(checked[i]) continue; // if i is a duplicated point, which is checked before, then skip
            for(j=i+1, maxPt =0, samePt = 1; j<pSize; ++j)
            {
                dx = points[i].x - points[j].x;
                dy = points[i].y - points[j].y;
                if(!dx && !dy)  {++samePt; checked[j]=true; continue;} // j is duplicated point of i 
                dx!=0? ++slopeMap[dy * 1.0 /dx]:++slopeMap[INT_MAX]; // updated the slope hashtable
            }
            for(auto it : slopeMap) maxPt = max(maxPt, it.second);
            res = max(res, maxPt + samePt);
            slopeMap.clear(); // don't forget to clear the hashtable
       }
       return res;
    }
};
/////
int maxPoints(vector<Point> &points) {
    size_t size = points.size();
    if (size < 3) return size;
    size_t mx = 0;
    for (size_t i = 0; i<size; ++i){
        unordered_map< double, size_t> hsh;
        size_t extra_points = 0;
        for (int j = i; j<size; ++j){
            double dy = points[j].y - points[i].y;
            double dx = points[j].x - points[i].x;
            if (!dy && !dx) 
                extra_points++;
            else {
                double A = dx != 0 ? dy / dx : 0;
                hsh[A]++;
            }
        }
        size_t new_mx = 0;
        for (auto l : hsh)
            new_mx = max(new_mx, l.second);
        new_mx += extra_points;
        mx = max(mx, new_mx);
    }
    return mx;
}
////
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

struct Point{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// Equal function for Point struct
bool operator==(const Point &p1, const Point &p2){
    return p1.x == p2.x && p1.y == p2.y;
}

// HashCode fuction for Point struct
struct hashPoint{
    size_t operator()(const Point &point) const{
        hash<int> tmp;
        return tmp(point.x) ^ (tmp(point.y) << 1);
    }
};

// Find the greatest common division for two integers,
// useful in building a Line struct
int gcd(int x, int y){
    if (x < y) return gcd(y, x);
    if (y < 0) return gcd(x, -y);
    if (y == 0) return x;
    return gcd(y, x%y);
}

struct Line{
    // Formula: a * x + b * y = c
    int a;
    int b;
    int c;

    // Make sure that the same line in 2D space will have the same expression
    Line(int _a, int _b, int _c){
        a = _a; b = _b; c = _c;
        if (a < 0){
            a = -a; b = -b; c = -c;
        }
        if (a == 0){
            c = c / b; b = 1; return;
        }
        int max = gcd(a, b);
        a = a / max; b = b / max; c = c / max;
    }
};

// Equal function for Line struct
bool operator==(const Line &l1, const Line &l2){
    return l1.a == l2.a && l1.b == l2.b && l1.c == l2.c;
}

// Hash function for Line struct
struct hashLine{
    size_t operator()(const Line &line) const{
        hash<int> tmp;
        return tmp(line.a) ^ (tmp(line.b) << 1) ^ (tmp(line.c) << 2);
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {

        if (points.size() == 0){
            return 0;
        }

        // hashMap to keep all points and their counts
        unordered_map<Point, int, hashPoint> record;

        typedef pair<unordered_set<Point, hashPoint>, int> pSet;

        // hashMap to keep all lines, their component points and counts of points.
        unordered_map<Line, pSet, hashLine> lineMap;
        for (Point pt : points) {
            if (record.find(pt) == record.end()) {
                record[pt] = 1;
            }else{
                record[pt] ++;
            }
        }

        if (record.size() == 1) {
            return record.begin()->second;
        }

        // Search all possible lines
        for (auto iter = record.begin(); iter != record.end(); iter ++) {
            auto iter2 = iter;
            for (iter2 ++; iter2 != record.end(); iter2 ++) {
                int x1 = iter->first.x, x2 = iter2->first.x;
                int y1 = iter->first.y, y2 = iter2->first.y;
                // Build a line with two given points.
                Line line(y2 - y1, x1 - x2, x2 * y1 - x1 * y2);
                if (lineMap.find(line) == lineMap.end()) {
                    // If this is a new line.
                    pSet tmp;
                    tmp.first.insert(iter->first);
                    tmp.first.insert(iter2->first);
                    tmp.second = iter->second + iter2->second;
                    lineMap[line] = tmp;
                }else{
                    // If this line already exist, check if the second point is added.
                    // If not, add it.
                    // No need to check the first point.
                    // It should be added because it can be scanned before as the line already exist.
                    if (lineMap[line].first.find(iter2->first) == lineMap[line].first.end()) {
                        lineMap[line].first.insert(iter2->first);
                        lineMap[line].second += iter2->second;
                    }
                }
            }
        }

        // Find the maximum, return it.
        int max = 2;
        for (auto iter = lineMap.begin(); iter != lineMap.end(); iter ++) {
            if (max < iter->second.second) {
                max = iter->second.second;
            }
        }

        return max;
    }
};
//////
use slope and translation for each line as the key in map;

overload < and == for map. set for counting.

map and set may be little bit slower but the code is clear

#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Line {
    double r;  // ratio ; slope
    double t;  // translation

    Line(Point p, Point q) { // math
        if (q.x == p.x) r = 1e20, t = p.x;
        else 
        {
            r = (double) (q.y-p.y) / (double) (q.x-p.x);
            t = p.y - p.x * r;
        }
    }
};

bool operator < (const Line& a, const Line& b) {
    return a.r == b.r ? a.t < b.t : a.r < b.r;
}

bool operator == (const Line& a, const Line& b) {
    return a.r == b.r && a.t == b.t;
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;

        map<Line, set<Point*> > line_map;
        for (auto & a : points)
        for (auto & b : points)
        {
            Line line(a,b);
            line_map[line].insert(&a);
            line_map[line].insert(&b);
        }

        int ret = 1;
        for (auto & pr : line_map) ret = max(ret,(int)pr.second.size());

        return ret;
    }
};
Nov. 20

Well, actually shiyan2 raised a very interesting question. I tried to make it faster by add

 for (auto & a : points)
       for (auto & b : points)
       {
           if ( (&a) >= (&b) ) continue;
           Line line(a,b);
           line_map[line].insert(&a);
           line_map[line].insert(&b);
       }
suppose it will be two times faster than the prev 1. but it failed on case

 [(3,10),(0,2),(0,2),(3,10)]
it said the output it 3 rather than 4. And I test on my machine it's 4.

Anyone have any clue about this ?

Nov. 25

Finally I got answer for the problems on Nov 20. It is due to the type "double" accuracy.

now I changed the == and < to

inline bool double_equal(double a, double b) { return abs(a-b) < 1e-10; }
inline bool double_less (double a, double b) { return a-b < -1e-10; }
and it just works well.

but the time is still high, due to the func calling.
////////
class Solution {
public:
    int maxPoints(vector<Point> &points) {

        if(points.size()<2) return points.size();

        int result=0;

        for(int i=0; i<points.size(); i++) {

            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;

            for(int j=i+1; j<points.size(); j++) {

                if(points[j].x==points[i].x && points[j].y==points[i].y) {

                    overlap++;
                    continue;
                }
                else if(points[j].x==points[i].x) vertical++;
                else {

                    int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
                    int gcd=GCD(a, b);

                    a/=gcd;
                    b/=gcd;

                    lines[make_pair(a, b)]++;
                    localmax=max(lines[make_pair(a, b)], localmax);
                }

                localmax=max(vertical, localmax);
            }

            result=max(result, localmax+overlap+1);
        }

        return result;
    }

private:
    int GCD(int a, int b) {

        if(b==0) return a;
        else return GCD(b, a%b);
    }
};
