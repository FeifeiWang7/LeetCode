#define max(a,b) ((a)>(b) ? a : b)
#define min(a,b) ((a)<(b) ? a : b)
#define f(a) (a - '0')

char* addBinary(char* a, char* b) {
if(!a && !b) return NULL;
if(!a)  return b;
if(!b)  return a;
int maxstrlen = (max(strlen(a),strlen(b))+2);
char* r = (char*)malloc(sizeof(char)*maxstrlen);

if(!r) 
    return NULL;
int asize = strlen(a);
int bsize = strlen(b);
int apos = asize, bpos = bsize, rpos = 0;

int Ci = 0;
int Ai = 0;
int Bi = 0;

r[rpos++] = '\0';
while(apos > 0  && bpos > 0)
{
     Ai = f(a[--apos]);
     Bi = f(b[--bpos]);
     r[rpos++] = (Ai ^ Bi ^ Ci) + 48;
     Ci = (Ai * Bi) + Ci * (Ai ^ Bi) ;
}
if(apos > bpos)
{
    while(apos > 0)
    {
        Ai = f(a[--apos]);
        r[rpos++] = (Ai  ^ Ci) + 48;
        Ci = Ai * Ci ;
    }
}
else if(bpos > apos)
{
    while(bpos > 0)
    {
        Bi = f(b[--bpos]);
        r[rpos++] = (Bi  ^ Ci) + 48;
        Ci = Bi * Ci ; 
    }
}
if(Ci == 1)
    r[rpos++] = Ci + 48;

int i = 0;
int g = rpos/2;
//char* r1 = (char*)malloc(sizeof(char)*maxstrlen);
for(i=0;i<g;i++)
{
    //r1[i] = r[--rpos];
    int tem = r[i];
    r[i] = r[--rpos];
    r[rpos] = tem;
}

return r;
