#include <bits/stdc++.h>
#include <time.h>
using namespace std;


int hts =13;
int Hash(int x,int i)
{
    return( (x%10 + i)%hts);
}
void insert(int a[],int x)
{
    int h = Hash(x,0); //mod 10
    if(a[h]==0 || a[h]==-1) //0 for empty and -1 for deleted
        a[h]=x;
    else { while(a[h]!=0 && a[h]!=-1)
              h=(h+1)%hts;
            a[h]=x;

         }

}
int search(int a[],int x)
{
    int h = Hash(x,0); //mod 10
    if(a[h]==x) {cout<<x<<" Found at index: "<<h<<endl; return h;}
        //0 for empty and -1 for deleted

    else {  int Hi=h;
            h=(h+1)%hts;
            while(a[h]!=0 && Hi!=h)
              {
               
               if(a[h]==x) {cout<<x<<" Found at index: "<<h<<endl; return h;}
               h=(h+1)%hts;  
            }



         }
         cout<<x<<" is Not Found"<<endl; return -1;
}

void Delete(int a[],int x)
{
int pos = search(a,x);
if(pos!=-1)
 {cout<<"Deleting: "<<a[pos]<<endl;
a[pos]=-1;}
}

void show(int a[])
{
for(int i =0;i<hts;++i)
    cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{   int n=6;//Number of keys
    int a[13] ={0};
    insert(a,9);
    insert(a,8);
    insert(a,19);
    insert(a,7);
    insert(a,29);
    insert(a,1);
    show(a);
    int pos;
    pos =search(a,1);
    pos =search(a,29);
    pos= search(a,28);
    Delete(a,29);
    Delete(a,26);
    show(a);

}
