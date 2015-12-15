struct Line {
  double slope;
  double intercept;
};

typedef struct Point pt;
typedef struct Line ln;

struct hash_map{
  ln key;             /* key is slope + intercept*/
  int numPt;          /* numPt is the number of points on this line */
  int idxCrt;         /* Which point creates this line? */
  UT_hash_handle hh;  /* makes this structure hashable */
};

typedef struct hash_map map;
map* ht = NULL;
void htAdd(ln key, int numPt, int idxCrt);
map* htFind(ln key);
void htCleanup();
void htPrint();


void getLine(pt* a, pt* b, ln* l)
{
  if(!a || !b)
  {
    printf("ERROR: wrong points input\n");
    return;
  }

  double x1 = (double)a->x;
  double x2 = (double)b->x;
  double y1 = (double)a->y;
  double y2 = (double)b->y;

  if(x1 == x2)
  {
    /* special case */
    l->slope = INFINITY;
    l->intercept = a->x;
  }
  else
  {
    l->slope = (y1==y2)? 0.0 : (y1-y2)/(x1-x2);
    l->intercept = y1 - x1 * l->slope;    
  }
}

bool isSame(pt* a, pt*b)
{
  return (a->x == b->x) && (a->y == b->y);
}

int maxPoints(pt* points, int pointsS) {
  ht = NULL;

  if(pointsS <= 1 || !points) return pointsS;

  /* first check any point is duplicated, and for how many times  */
  int dup[pointsS];
  memset(dup, 0, sizeof(int)*pointsS);
  for(int i = 0; i <pointsS-1; i++)
    for(int j = i+1; j< pointsS && dup[i]!= -1; j++)
      if(isSame(points+i, points+j))
      {
        dup[i]++;
        dup[j] = -1;
      }

  /* the algorithm is looping through each point,
     check the line it's forming with each point after it,
     and update a counter for each line in the hast table
     then finally find the line with the largest count
   */
  ln l;
  map* s;
  for(int i = 0; i<pointsS-1; i++)
  {
    for(int j = i+1; j<pointsS && dup[i] !=-1; j++)
    {
      getLine(points+i, points + j, &l);
      s = htFind(l);
      if(s)
      {
        /* an existing line, check if created by this point only */
        if(i == s->idxCrt)
          (s->numPt)++;
      }
      else
      {
        /* insert the new line */
        if(isSame(points+i, points+j))
          htAdd(l, 2, i);         /* special case: same point */            
        else
          htAdd(l, 2+dup[i], i);         /* 2+dup points on a line */  
      }
    }
  }

  /*  htPrint(); */
  /* find the largest count in the hasttable */
  int ret = INT_MIN;
  for(s=ht; s; s=(map*)(s->hh.next))
    ret = (ret>s->numPt)? ret: s->numPt;

  htCleanup();
  return ret;
}

void htAdd(ln key, int numPt, int idxCrt) {
    map* s;

    s = (map*)malloc(sizeof(map));
    s->key.slope = key.slope;
    s->key.intercept = key.intercept;
    s->numPt = numPt;
    s->idxCrt = idxCrt;
    HASH_ADD(hh, ht, key, sizeof(ln), s); 
}

map* htFind(ln key) {
    map* s;

    HASH_FIND(hh, ht, &key, sizeof(ln), s);  /* s: output pointer */
    return s;
}

void htCleanup(){
    map* cur, *tmp;
    HASH_ITER(hh, ht, cur, tmp)
    {
        HASH_DEL(ht, cur);  /* delete it (users advances to next) */
        free(cur);            /* free it */
    }
}

void htPrint() {
    map* s;

    for(s=ht; s != NULL; s=(map*)(s->hh.next))
        printf("slope:%f, intercept:%f, numPt:%d, idxCrt:%d\n",
               s->key.slope, s->key.intercept, s->numPt, s->idxCrt);
}
