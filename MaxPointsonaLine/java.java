import java.util.HashMap;
public class Solution {
    public int maxPoints(Point[] points) {
        if (points.length <= 2){
            return points.length;
        }
        int result=1;

      //A line is defined y=a/bx+c, so (a, b, c) will represent a unique line
     // run through each point and calculate (a, b, c) that defines the lines of itself 
     //with all the the remaining points 
        for (int i=0; i<points.length; i++){
            int max=0, countSame=0;
            HashMap<String, Integer> hm = new HashMap<String, Integer>();
            for (int j=i+1; j<points.length; j++){
                if (points[i].x == points[j].x && points[i].y == points[j].y){
                    countSame++;       //same points will just add to the result
                }
                else{
                    String key = normalize(points[i],points[j]);
                    if(hm.get(key) == null){
                        hm.put(key, 1);
                        if(max ==0){
                            max++;
                        }
                    }
                    else {
                       int count = hm.get(key)+1;
                       hm.put(key, count);

                        if (count > max)
                            max = count;
                    }
                }

            }
            result = Math.max(result, max+countSame+1);
        }


        return result;
    }

    //ax+by+c=0 or y=a/b x + c
    private String normalize(Point p1, Point p2){
        int a, b;
        float c;

        if (p1.x == p2.x){  //a line parallel to y axis
            a = 1;
            b = 0;
            c = -1 * p1.x;
        }
        else if (p1.y == p2.y){ //a line parallel to x axis
            a = 0;
            b = 1;
            c = p1.y;
        }
        else{
            int gcd = gcd(Math.abs(p1.x-p2.x), Math.abs(p1.y-p2.y));
            b = (p2.x-p1.x)/gcd;
            a = (p2.y-p1.y)/gcd;
            if (a*b<0){                   //if the slope<0, always put (-) in front of a 
                a = -1 * Math.abs(a);
                b = Math.abs(b); 
            }
            else {
                a = Math.abs(a);
                b = Math.abs(b); 
            }
            c = (float)(b*p1.y - a*p1.x)/(float)b;
        }
        return ""+a+"||"+b+"||"+c;     //use this presentation as a key

    }

    private int gcd(int x, int y) {
        if (y == 0) {
          return x;
        }
        return gcd(y, x % y);
  }
}
////
public class Solution 
    {
        public int maxPoints(Point[] points) 
        {
            int n=points.length;
            if (n<2) return n;
            int currentL=0,maxL=2,x=0,y=0,dx=0,dy=0,overlap=0,upperB=n;
            for(int i=0; i<upperB; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    currentL=1; 
/*
 * Given two points: (a,b) and (c,d), the corresponding normal vector is (b-d,c-a)
 * If another point (s,t) is in the same line uniquely defined by (a,b) and (c,d),
 * then (s-a,t-b) dot (b-d,c-a) = 0
 */
                    x=points[i].y-points[j].y;
                    y=points[j].x-points[i].x;

/* If two points are the same, there is no need to check further, 
 * since a line has to be defined by exactly two distinct points.
 */
                    if(x==0 && y==0) 
                        overlap++;

/* Well, it might be the case that duplicates are not consecutive, 
 * but as long as we can have a non-trivial normal vector, it won't matter.
 */ 
                    else 
                    {
                        currentL++;

/*  Explaining (currentL+n-k>maxL):
 *  no further checking is necessary when there isn't enough left to make it surpass maxL. 
 */ 
                        for(int k=j+1; k<n && currentL+n-k>maxL; k++)
                        {
                            dx=points[k].x-points[i].x;
                            dy=points[k].y-points[i].y;
                            if(x*dx+y*dy==0)
                                currentL++;
                        }
                    }
                    maxL=Math.max(currentL+overlap,maxL);
                }

/* Explaining (upperB=n-maxL): 
 * it would be crystal clear as soon as you draw a table for combinations of case n>3.
 */
                upperB=n-maxL;
                overlap=0;
            }
            return maxL;
        }
    }
////
public int maxPoints(Point[] points) {
    if (points.length < 3) {
        return points.length;
    }
    int max = 0;
    for (int a = 0; a<points.length-2; a++) {
        boolean[] checked = new boolean[points.length];
        for (int b = a+1; b<points.length; b++) {

            // Do not check the same line
            if (checked[b]) continue;

            // The point-b should differ from point-a
            while (b < points.length && points[b].x == points[a].x && points[b].y == points[a].y) {
                b++;
            }

            // Count all point between point-a and point-b 
            // witch have the same coordinates as point-a
            int count = b == points.length ? 1 : 2;
            for (int i=a+1; i<b; i++) {
                if (points[i].x == points[a].x && points[i].y == points[a].y) {
                    count++ ;
                }
            }

            // Count point-c if it lies on the point-a-point-b-line.
            for (int c = b+1; c<points.length; c++) {
                if (isOnLine(points[a], points[b], points[c])) {
                    count++ ;
                    checked[c] = true;
                }
            }

            if (count > max) {
                max = count;
            }
        }
    }
    return max;
}

private boolean isOnLine(Point a, Point b, Point c) {
    return (b.y - a.y)*(c.x - a.x) == (c.y - a.y)*(b.x - a.x);
}
//////
public class Solution {
    public int maxPoints(Point[] points) {
        if(points == null) return 0;
        int n = points.length;
        if(n <= 2) return n;
        Map<Long, Integer> map = new HashMap<>();
        int result = 0;
        for(int i = 0; i < n - 1; ++i){
            int localMax = 0, overlap = 0;
            map.clear();
            for(int j = i + 1; j < n; ++j){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    overlap++;
                }else{`enter code here`
                    long k = slope(points[i].x - points[j].x, points[i].y - points[j].y);
                    int t = map.containsKey(k) ? map.get(k) + 1 : 1;
                    map.put(k, t);
                    localMax = t > localMax ? t : localMax;
                }
            }
            localMax += overlap + 1;
            result = result < localMax ? localMax : result;
        }
        return result;
    }
    long slope(int a, int b){
        int c = gcd(a, b);
        if(c != 0){
            a /= c;
            b /= c;
        }
        long r = a;
        r = (r << 32) | b;
        return r;
    }
    int gcd(int a, int b){
        int r;
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
}
//////
public class Solution {
    public int maxPoints(Point[] points) {
        int length = points.length;
        int result = 0;
        for (int i = 0; i < length; ++i) {
            int same = 0;
            int zero = 1;
            HashMap<Double, Integer> map = new HashMap<Double, Integer>();
            for (int j = i + 1; j < length; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same++;
                } else if (points[i].x == points[j].x) {
                    zero++;
                } else {
                    double xielv = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    if ((points[i].y - points[j].y) == 0) xielv = 0.0;
                    if (!map.containsKey(xielv)) map.put(xielv, 1);
                    map.put(xielv, map.get(xielv) + 1);
                }
            }
            int max = 1;
            for (Map.Entry<Double, Integer> e : map.entrySet()) {
                if (max < e.getValue()) {
                    max = e.getValue();
                }
            }
            max += same;
            if (max > result) {
                result = max;
            }
            if (zero > result) {
                result = zero;
            }
        }
        return result;
    }
}
/////
public class Solution {

    static class Line {
        int deltax;
        int deltay;

        int cross1;
        int cross2;

        public Line(int deltax, int deltay, int x0, int y0) {
            // shrink 
            if (deltax == 0) {deltay = 1; cross1 = x0; cross2=0; }
            else if (deltay == 0) { deltax = 1; cross1 = y0; cross2 = 0;}
            else {
                int gcd = gcd(deltax, deltay);
                deltax = deltax/gcd;
                deltay = deltay/gcd;
                if (deltax <0) {
                    deltax = - deltax;
                    deltay = - deltay;
                }
                this.deltax = deltax;
                this.deltay = deltay;

                cross1 = y0 * deltax - x0 * deltay;
                cross2 = deltax * deltay;
                if (cross1 ==0) cross2 = 1;
                else {
                gcd = gcd(cross1, cross2);
                cross1 /= gcd;
                cross2 /= gcd;
                }
            }
        }

        public int hashCode() {
            return deltax*deltay + cross1 + cross2 + deltax;
        }
        public boolean equals(Object obj) {
            if (obj == null) return false;
            if (! (obj instanceof Line )) return false;
            Line obj2 = (Line) obj;
            return obj2.deltax == deltax && obj2.deltay == deltay && obj2.cross1 == cross1 && obj2.cross2 == cross2;
        }

  static int gcd(int a, int b)
{
  while(a!=0 && b!=0) // until either one of them is 0
  {
     int c = b;
     b = a%b;
     a = c;
  }
  return a+b; // either one is 0, so return the non-zero value
}
    }

    public int maxPoints(Point[] points) {
        Map<Line, Set<Integer>> map = new HashMap<Line, Set< Integer>>();
        if (points.length == 1 ) { return 1;}
        for(int i=0;i<points.length-1;i++) {
            for(int j=i+1;j<points.length;j++) {
                Line l = new Line(points[i].x - points[j].x, points[i].y - points[j].y, points[i].x, points[i].y );
                if( map.containsKey(l) ) {
                    map.get(l).add(i);
                    map.get(l).add(j);
                } else {
                    map.put(l,new HashSet<Integer>() );
                    map.get(l).add(i);
                    map.get(l).add(j);
                }
            }
        }

        int best = 0;
        for(Map.Entry e: map.entrySet()) {
            Set cnt = (Set)e.getValue();
            best = Math.max(cnt.size(),best);
        }
        return best;
    }
}
/////

Here is my solution. The idea others had, to use ax + by + c = 0 to store the lines has one big benefit: you can store these three values as integers and therefore can use your Line as key for a Hashmap. But it will also have one downside - you have to take care of cases like 1x + 1y + 0 and 2x+2y + 0 and therefore calculate the gcd which will bump your solution to O(n^2log(n))

Using the other format y = m*x + b you will end up with fractions which will be float or double which should NEVER be used in Objects that are supposed to be Hashmap keys.

So how to circumvent this problem? This is the idea: mulitply the slope m and y-distance b (don't know the technical english term) by 1000 and then store this value as int. Basically you're saying you will only need 3 digits after the decimal point with a multiplier by 1000.

There are two caveats: 1. We do have limited precision (but 3 digits after the decimal point should be enough here) 2. If we have "big" points we could get overflow problems (because multiplying by 1000).

What do you guys think?

public class Solution {
    public int maxPoints(Point[] points) {
        if(points == null || points.length == 0) { return 0; }
        if(points.length == 1) { return 1; }

        Map<Line, Set<Integer>> lineMap = new HashMap<>();
        int max = 2;

        for(int i = 0; i < points.length-1; i++) {
            for(int j = i+1; j < points.length; j++) {
                Line cur = new Line(points[i], points[j]);
                if(!lineMap.containsKey(cur)) {
                    Set<Integer> pointSet = new HashSet<>();
                    pointSet.add(i);
                    pointSet.add(j);
                    lineMap.put(cur, pointSet);
                } else {
                    Set<Integer> pointSet = lineMap.get(cur);
                    if(!pointSet.contains(i)) {
                        pointSet.add(i);
                    }
                    if(!pointSet.contains(j)) {
                        pointSet.add(j);
                    }
                    max = Math.max(pointSet.size(), max);
                }
            }
        }

        return max;
    }

    private static class Line {
        final static int ACC_MULT = 1000;

        // Note: slope and yDist are multiplied by ACC_MULT;
        int slope;
        int yDist;
        int xDist;
        boolean infSlope;

        Line(Point p1, Point p2) {
            if(p2.x - p1.x == 0) { 
                infSlope = true;
                xDist = p1.x;
            } else {
                slope = ((p2.y - p1.y) * ACC_MULT) / (p2.x - p1.x);
                yDist = ((p1.x*p2.y-p2.x*p1.y) * ACC_MULT) / (p1.x-p2.x);
            }
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) { return true; }
            if (!(o instanceof Line)) { return false; }
            Line line = (Line) o;
            return line.slope == this.slope &&
                   line.yDist == this.yDist &&
                   line.infSlope == this.infSlope &&
                   line.xDist == this.xDist;
        }

        @Override
        public int hashCode() {
            int result = 17;
            result = 31 * result + slope;
            result = 31 * result + yDist;
            result = 31 * result + xDist;
            result = 31 * result + ((infSlope) ? 1 : 0);
            return result;
        }
    }
}
///////
the idea is to basically calculate the slope between each point for a fixed point, and do this for all points. hash table helps count same slopes. things to note:

Beware of duplicate points
In java, 0 has two values for type Double, 0.0 and -0.0, be careful with these

public class Solution {
    public int maxPoints(Point[] points) {
        if (points.length <= 2) return points.length;

        // map slope to count
        HashMap<Double, Integer> hm = new HashMap<Double, Integer>();
        int maxCount = 1;

        for (int i = 0; i < points.length; i++) {
            // hash each slope and count duplicates
            hm = new HashMap<Double, Integer>();
            int duplicate = 0;
            int maxR = 0;

            for (int j = i + 1; j < points.length; j++) {
                double slope;
                if (isDupl(points[i], points[j])) {
                    duplicate++;
                    continue;
                }
                else slope = slopeFor(points[i], points[j]);

                if (hm.containsKey(slope)) {
                    int prevCount = hm.get(slope);
                    hm.put(slope, prevCount + 1);
                    maxR = Math.max(maxR, prevCount + 1);
                }
                else {
                    hm.put(slope, 1);
                    maxR = Math.max(maxR, 1);
                }
            }
            maxCount = Math.max(maxCount, maxR + duplicate);
        }
        return maxCount + 1;
    }

    private boolean isDupl(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }

    private double slopeFor(Point a, Point b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        if (dx == 0) return Double.POSITIVE_INFINITY;
        else if (dy == 0) return 0;
        return dy / dx;
    }
}

//////
public class Solution {

class Line{
    //slope is null iff it's vertical
    //if line is not vertical, intersect is y-intersection
    //if line is vertical, intersect is x-intersection
    Double slope; Double intersect;
    //some pseudo-pseudo random number
    static final int rand=65536123;

    //clean constructor interface
    Line (double slope,double intersect){
        this.slope=slope; 
        this.intersect=intersect;
    }

    //precondition: alpha and beta not same point
    Line (Point alpha,Point beta){
        if (alpha.x==beta.x){
            this.slope=null;
            this.intersect=(double)alpha.x;
        }
        else {
            this.slope=(double)((alpha.y-beta.y)/((double)(alpha.x-beta.x)));
            this.intersect=(beta.y*alpha.x-alpha.y*beta.x)/((double)alpha.x-beta.x);
        }
    }

    @Override
    public boolean equals(Object beta){
        boolean output=false;
        if (beta instanceof Line){
            Line betaLine=(Line) beta;
            return ((this.slope==null && betaLine.slope==null)||approxEqual(this.slope,betaLine.slope))&&approxEqual(this.intersect,betaLine.intersect);
        }
        return output;
    }

    @Override
    public int hashCode(){
            final int prime = 31; 
            int result = 1; 
            result = prime * result + (this.slope==null?rand:this.slope.hashCode()); 
            result = prime * result + (this.intersect==null?rand:this.intersect.hashCode()); 
            return result;
    }

    public String toString(){
        String output="";
        output+="slope: "+(this.slope==null?"null":this.slope)+"intersect: "+(this.intersect==null?"null":this.intersect);
        return output;
    }
}

public boolean approxEqual(double a,double b){
    return Math.abs(a-b)<0.0001;
}

//O(n^2) algo
public int maxPoints(Point[] points) {
    //case defense: there is always a line when only one point
    if (points==null || points.length==0) return 0;
    if (points.length==1) return 1;
    //key: Line; Value: the count of points in this line
    HashMap<Line,HashSet<Point>> H=new HashMap<Line,HashSet<Point>>();

    for (int i=1;i<points.length;i++){
        Point iPoint=points[i];
        for (int j=0;j<i;j++){
            Point jPoint=points[j];
            Line Line_IJ=new Line(iPoint,jPoint);  
            //if two same points, let the line be null
            if (approxEqual(iPoint.x,jPoint.x)&& approxEqual(iPoint.y,jPoint.y))  Line_IJ=null;

            //if H does not contain Line_IJ, just put (Line_IJ) into H, add iPoint & jPoint into Line_IJ's pointSet
            if (Line_IJ!=null && (!H.keySet().contains(Line_IJ))){
                HashSet<Point> pointSet=new HashSet<Point>();
                H.put(Line_IJ, pointSet);
            }
            //if H does contain Line_IJ, corresponding pointSet of Line_IJ
            //if pointSet does not iPoint/jPoint, add iPoint/jPoint to pointSet, 
            else if (Line_IJ!=null){
                HashSet<Point> pointSet=H.get(Line_IJ);
            }

        }
    }
    //now we have all the lines, we want to fit points on the lines

    //another defense
    if (H.size()==0){
        HashSet<Point> pointSet=new HashSet<Point>();
        H.put(new Line(points[0],points[1]),pointSet);
    }

    //sweep on the lines on all the points to see if it fits, if fit, add to corresponding HashSet
    for (Point p:points){
        for (Line L:H.keySet()){
            //L is vertical?
            if (L.slope==null){
                if (approxEqual(p.x,L.intersect)){H.get(L).add(p);}
            }
            else {
                if (approxEqual(L.slope*p.x+L.intersect,p.y)){H.get(L).add(p);}
            }
        }
    }

    int output=0;
    for (Line L:H.keySet()){
        if (H.get(L).size()>output) output=H.get(L).size();
    }
    return output;
}
}

//////
public class Solution {
    public int maxPoints(Point[] points) {
        if(points.length <= 0) return 0;
        if(points.length <= 2) return points.length;
        int result = 0;
        for(int i = 0; i < points.length; i++){
            HashMap<Double, Integer> hm = new HashMap<Double, Integer>();
            int samex = 1;
            int samep = 0;
            for(int j = 0; j < points.length; j++){
                if(j != i){
                    if((points[j].x == points[i].x) && (points[j].y == points[i].y)){
                        samep++;
                    }
                    if(points[j].x == points[i].x){
                        samex++;
                        continue;
                    }
                    double k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                    if(hm.containsKey(k)){
                        hm.put(k,hm.get(k) + 1);
                    }else{
                        hm.put(k, 2);
                    }
                    result = Math.max(result, hm.get(k) + samep);
                }
            }
            result = Math.max(result, samex);
        }
        return result;
    }
}
/////////
The idea is to encode each line into a String of 8 digits of accuracy for slope and intersection. After encoding, we can happily use HashSet, and with 8 digits of accuracy, we can avoid most (if not all) of the float point errors.

public class Solution {

public class Line{
    HashSet<Point> pointH;
    public Line(){this.pointH=new HashSet<Point>();}
}

//Precondition:A,B different Point
public String genEigen(Point A,Point B){
    String slope=""; String intersect="";
    if (A.x!=B.x) {
        slope=String.format("%.8f", (B.y-A.y)/(double)(B.x-A.x));
        intersect=String.format("%.8f", (A.y-((B.y-A.y)/(double)(B.x-A.x))*A.x));
    }
    else {intersect=String.format("%.8f", (double)A.x);}
    return slope+";"+intersect;
} 

public int maxPoints(Point[] points) {
    //case defense
    if (points==null || points.length==0) return 0;
    //normal
    HashMap<String,Line> H=new HashMap<String,Line>();
    for (int i=0;i<points.length;i++){
        for (int j=i+1;j<points.length;j++){
            Point A=points[i];Point B=points[j];
            if (A.x!=B.x || A.y!=B.y){
                String eigenString=genEigen(A,B);
                if (!H.containsKey(eigenString)){
                    H.put(eigenString,new Line());
                }
                H.get(eigenString).pointH.add(A);
                H.get(eigenString).pointH.add(B);
            }

        }
    }
    int maxOut=1;
    if (H.size()==0) return points.length;
    for (String eigenString:H.keySet()){
        maxOut=Math.max(maxOut, H.get(eigenString).pointH.size());
    }
    return maxOut;
}
}

///
public class Solution{
        public int maxPoints(Point[] points) {
            if (points==null) return 0;
            if (points.length<=2) return points.length;

            Map<Integer,Map<Integer,Integer>> map = new HashMap<Integer,Map<Integer,Integer>>();
            int result=0;
            for (int i=0;i<points.length;i++){ 
                map.clear();
                int overlap=0,max=0;
                for (int j=i+1;j<points.length;j++){
                    int x=points[j].x-points[i].x;
                    int y=points[j].y-points[i].y;
                    if (x==0&&y==0){
                        overlap++;
                        continue;
                    }
                    int gcd=generateGCD(x,y);
                    if (gcd!=0){
                        x/=gcd;
                        y/=gcd;
                    }

                    if (map.containsKey(x)){
                        if (map.get(x).containsKey(y)){
                            map.get(x).put(y, map.get(x).get(y)+1);
                        }else{
                            map.get(x).put(y, 1);
                        }                       
                    }else{
                        Map<Integer,Integer> m = new HashMap<Integer,Integer>();
                        m.put(y, 1);
                        map.put(x, m);
                    }
                    max=Math.max(max, map.get(x).get(y));
                }
                result=Math.max(result, max+overlap+1);
            }
            return result;


        }
        private int generateGCD(int a,int b){

            if (b==0) return a;
            else return generateGCD(b,a%b);

        }
    }
