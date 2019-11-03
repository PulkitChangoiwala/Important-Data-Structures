#include<bits/stdc++.h>
using namespace std;
#define d 256


int search(char str[],char pat[],int q)
{
    int n=strlen(str);
    int m=strlen(pat);
    //Calculate Hash Value of Pattern
    int p=0;
    int s=0;
    int h=1;

    for (int i = 0; i < m - 1; i++)
       {
           h = (h * d) % q;
       }
    for(int i=0;i<m;++i)
    {
        p=(p*d+pat[i])%q; //pattern hash value
        s=(s*d+str[i])%q; //First window hash value
    }
    for(int i =0;i<=n-m;++i)
    {
        if(p==s)
        {   int f=1;
            for(int j=0;j<m;++j)
            { if(pat[j]!=str[j+i])
                 {f=0;break;}


            }
         if(f) {cout<<"String Found at index: "<<i<<endl;return 1;}

        }
        else if(i<=n-m)
        {
            s= ( (d*(s-str[i]*h))  +  str[i+m] )%q;
            if(s<0) s+=q;
        }
    }



return 0;
}



int main()
{
    char str[] ="CS204 is not consistent with CS203";
    char pat[]="consistEnt";
    int q = 123; //A prime number but usually the number of digits int can store;
    if(!search(str,pat,q)) cout<<"String Not Found\n";
    return 0;
}

//Rabin Karp Algorithm:::

