#include<bits/stdc++.h>
using namespace std;

typedef struct node
{int k;
int v;
struct node  *l,*r;


}node;

node* rightrotate(node* y)
{
node* x= y->l;
node*t2 = x->r;
x->r=y;
y->l= t2;
return x;
}

node* leftrotate(node *x)
{
    node* y=x->r;
    node*t2=y->l;
    y->l= x;
    x->r=t2;
    return y;
}

node* newnode(int key)
{

    node* ptr= new node;
    ptr->l=ptr->r=NULL;
    ptr->k=key;
    ptr->v=rand()%100;
    return ptr;
}

node* srch(node* root , int key)
{
    if(root!= NULL)
    {
        if(root->k==key) return root;
        else if(key<=root->k) return (srch(root->l,key));
        else if(key>root->k) return (srch(root->r,key));

    }
    else return NULL;
}

node* insrt(node * root,int key)
{
    if(!root) return newnode(key);
    else if(key<=root->k)
        {root->l= insrt(root->l,key);
         if(root->l->v > root->v)
         root = rightrotate(root);
        }
    else if(key>root->k)
        {
            root->r= insrt(root->r,key);
            if(root->r->v > root->v)
            root= leftrotate(root);
        }
        return root;
}
node* dlt(node* root,int key)
{
    if(root==NULL)
        return root;
    else if(key<root->k) { root->l = dlt(root->l,key);}
    else if(key>root->k) { root->r = dlt(root->r,key);}
    //root contains the node with k= key
    else if(root->l==NULL)
    {
     node* temp= root->r;
     delete(root);
     root=temp;
     }
     else if(root->r == NULL)
     {
         node* temp= root->l;
         delete(root);
         root=temp;
     }

     else if(root->r->v>root->l->v)
     {
         root=leftrotate(root);
         root->l=dlt(root->l,key);
     }
     else
     {
         root=rightrotate(root);
         root->r=dlt(root->r,key);
     }
     return root;
}

void inorder(node* root)
{
    if(root==NULL)  return ;
    else {
            inorder(root->l);
            cout<<"Key: "<<root->k<<"Priority: "<<root->v;
            if (root->l)
            cout << " | left child: " << root->l->k;
        if (root->r)
            cout << " | right child: " << root->r->k;
        cout << endl;
        inorder(root->r);
         }
}
int main()
{   srand(time(NULL));
    node *root = NULL;
    root = insrt(root, 50);
    root = insrt(root, 30);
    root = insrt(root, 20);
    root = insrt(root, 40);
    root = insrt(root, 70);
    root = insrt(root, 60);
    root = insrt(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inorder(root);

    cout << "\nDelete 20\n";
    root = dlt(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = dlt(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = dlt(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

     node *res = srch(root, 50);
    (res == NULL)? cout << "\n50 Not Found ":
                   cout << "\n50 found";

    return 0;
}

