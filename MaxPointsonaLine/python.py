def maxPoints(self, points):
    answer = 0
    for p in points:
        pctr = 0
        ctr = collections.Counter()
        for q in points:
            x, y = q.x - p.x, q.y - p.y
            pctr += x == y == 0
            ctr[float(y)/x if x else 'inf'] += 1
        ctr['inf'] -= pctr
        answer = max(answer, pctr + max(ctr.values()))
    return answer

#####
Main algorithm: Compute slope for each pair and increment the counter of the same slope.

The idea is that for each point, get the total number of points on the same line with respect to that point, and then find the max total. There's some redundant comparisons for the subsequent pairs if they are on the same line with previous points, because it should have been already accounted for in the previous iterations, but I found this solution to be easy to understand.

def maxPoints(self, points):
    if len(points) < 2:
        return len(points)

    max_cnt = 0

    for i, p1 in enumerate(points[:-1]):
        occurence = 0
        slope_dict = {}

        for j, p2 in enumerate(points[i+1:]):
            x = p2.x - p1.x
            y = p2.y - p1.y

            slope = 0 if x==0 else y*1.0/x

            increment = 1
            if x == y == 0:
                # If two points are exactly the same
                occurence += 1
                increment = 0

            same_slope = slope_dict.get(slope, 1)
            slope_dict[slope] = same_slope + increment

        max_cnt = max(max_cnt, occurence + max(slope_dict.values()))
    return max_cnt

######
def maxPoints(self, points):
        l = len(points)
        m = 0
        for i in range(l):
            dic = {'i': 1}
            same = 0
            for j in range(i+1, l):
                tx, ty = points[j].x, points[j].y
                if tx == points[i].x and ty == points[i].y: 
                    same += 1
                    continue
                if points[i].x == tx: slope = 'i'
                else:slope = (points[i].y-ty) * 1.0 /(points[i].x-tx)
                if slope not in dic: dic[slope] = 1
                dic[slope] += 1
            m = max(m, max(dic.values()) + same)
    return m
#####

The first solution uses slope directly as the key for the dictionary. Python can handle it. The second solution uses a tuple of integer (dx, dy) as the key.

Solution 1:

def maxPoints(self, points):
    if len(points) <= 2: return len(points)
    d = collections.defaultdict(int) # slope : count
    result = 0
    for i in range(len(points)):
        d.clear()
        overlap, curmax = 0, 0
        for j in range(i+1, len(points)):
            dx, dy = points[j].x - points[i].x, points[j].y - points[i].y
            if dx == 0 and dy == 0:
                overlap += 1
                continue
            slope = dy * 1.0 / dx if dx != 0 else 'infinity'
            d[slope] += 1
            curmax = max(curmax, d[slope])
        result = max(result, curmax+overlap+1)
    return result
Solution 2:

def maxPoints(self, points):
    if len(points) <= 2: return len(points)
    d = collections.defaultdict(int) # (x,y) : count
    result = 0
    for i in range(len(points)):
        d.clear()
        overlap = 0
        curmax = 0
        for j in range(i+1, len(points)):
            dx = points[j].x - points[i].x
            dy = points[j].y - points[i].y
            if dx == 0 and dy == 0:
                overlap += 1
                continue
            gcd = self.getGcd(dx, dy)
            dx //= gcd
            dy //= gcd
            d[(dx,dy)] += 1
            curmax = max(curmax, d[(dx,dy)])
        result = max(result, curmax+overlap+1)
    return result

def getGcd(self, a, b):
    if b == 0: return a
    return self.getGcd(b, a%b)

###
'''
for every line L consists of only two points (p1,p2):
    if p1.x!=p2.x:
        line must cross y axis
        y(0)=y1-(y2-y1)/(x2-x1)*x1
        key(L)=(y(0),(p2.y-p1.y)/(p2.x-p1.x))
    elif p1.x==p2.x:
        line must cross x axis
        x(0)=x1-(x2-x1)/(y2-y1)*y1
        key(L)=(x(0),Infinity)
'''

#Definition for a point
class Point:
    def __init__(self, a=0, b=0):
        self.x = float(a)
        self.y = float(b)
        self.copy=1

    def __repr__(self):
        return str((self.x,self.y,self.copy))

    def tuple(self):
        return (self.x,self.y,self.copy)

class Line:
    def __init__(self,p1=None,p2=None):
        self.p1=p1
        self.p2=p2

    def __repr__(self):
        return str((self.p1,self.p2))

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):

        #calculate duplicates
        uniquePoints={}
        for point in points:
            key=(point.x,point.y)
            if uniquePoints.__contains__(key):
                uniquePoints[key].copy=uniquePoints[key].copy+1
            else:
                uniquePoints[key]=point
        points=list(uniquePoints.values())
        #print('unique points:',points)

        if len(points)<1:
            return 0
        if len(points)==1:
            return points[0].copy

        #calculate lines with two points
        lines=[]
        for i in range(0,len(points)-1):
            for j in range(i+1,len(points)):
                line=Line(points[i],points[j])
                lines.append(line)
        #print('line pairs:',lines)

        #calculate line key
        lineSets={}
        for line in lines:
            p1=line.p1
            p2=line.p2
            if p1.x!=p2.x:
                ka=p1.y-(p2.y-p1.y)/(p2.x-p1.x)*p1.x
                kb=(p2.y-p1.y)/(p2.x-p1.x)
            else:
                ka=p1.x-(p2.x-p1.x)/(p2.y-p1.y)*p1.y
                kb=None
            key=(ka,kb)
            if lineSets.__contains__(key)==False:
                lineSets[key]=set()
            lineSets[key].add(p1.tuple())
            lineSets[key].add(p2.tuple())
        #print('lineSets:',lineSets)

        #calculate line sizes
        lineSizes=map(lambda s:sum(map(lambda e:e[2],s)),lineSets.values())
        #print(lineSizes)
        return max(lineSizes)

