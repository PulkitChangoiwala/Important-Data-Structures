#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
int a;
}node;
typedef struct detail
{
    int parent;
    int r;
}detail;
int find(detail info[],int x)
{
    if(info[x].parent !=x)
        info[x].parent = find(info,info[x].parent);
    return info[x].parent;
}

void Union(detail info[],int x, int y)
{
 x=find(info,x);
 y=find(info,y);
 if(x!=y)
 {   if(info[x].r==info[y].r)
     {
      info[y].parent=x;
      info[x].r++;
     }
     else if(info[x].r>info[y].r)
     {
        info[y].parent=x;
     }
     else info[x].parent=y;


 }
}

int isCycle(list<int> *adj,int v, int e)
{
   detail * info = new detail[v];
   for(int i=0;i<v;++i )
   {
       info[i].parent=i;
       info[i].r=0;
   }

   for(int i=0;i<v;++i)
   {   list<int>::iterator it;
       for( it = adj[i].begin();it!=adj[i].end();++it)
       {
           int x= find(info,i);
           int y= find(info,*it);
           if(x==y) return 1;
           Union(info,x,y);

       }
   }
   return 0;
}
int main()
{   int v=7,e=6;//Number of edges or vertices
    list<int> *adj= new list<int>[v];//Graph as adjancey list

    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);

    if(isCycle(adj,v,e)) cout<<"Cycle is Present";
    else cout<<"Cycle is not present";

    return 0;
}
