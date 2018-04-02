#include <iostream>
using namespace std;

class node{
public:
int data;
node *parent;
node *left;
node *right;
node(){
data=0;
parent=NULL;
left=right=NULL;
}
};

class bTree{
public:
node *root;
int c,s=0,cr=0,cl=0,ci=0;

public:
bTree(){
root=NULL;
}

void insert(node *t, int x)
{
 node *v=new node;
 v->data=x;

 if(root==NULL)
  {
   root=v;
   c=1;
  }

 else
  {
   if(x < t->data)
     {
      if(t->left==NULL)
      {
       t->left=v;
       v->parent=t;
       c++;
      }
      else
      {
       insert(t->left, x);
      }
     }
   else
    {
     if(x > t->data)
      {
       if(t->right==NULL)
        {
         t->right=v;
         v->parent=t;
         c++;
        }
       else
        {
         insert(t->right, x);
        }
       }
      }
    }
  }

int count(node *r){
  if(r==NULL){
     return 0;
    }

  count(r->left);
  if(r->parent==NULL)
    cr++;
  else if(r->left==NULL && r->right==NULL)
    cl++;
  else 
    ci++;
  count(r->right);

  

   
return c;
}


void display(node *v){
  if(v==NULL){
   return;
  }
  display(v->left);
  cout<<v->data;
  display(v->right);
 
}


int range(node *v, int k1, int k2)
  {
   if(v==NULL)
     {
      return 0;
     }
   
   if(k1< v->data)
          {
           range(v->left, k1, k2);
          }
   if(k2 >= v->data && k1 <= v->data)
          {
           cout<<v->data<<"\t";
           s++;
          }
   if(k2 >v->data)
          {
           range(v->right, k1, k2);
   
   return s;
       }
  }
   

};


int main(){
  int en,n,j,k;
  bTree b;
  cout<<"How many entries??\n";
  cin>>n;
  cout<<"Enter 'em\n";
  for(int i=0; i<n; i++)
    {
     cin>>en;
     b.insert(b.root,en);
    }
 int co=b.count(b.root);
 cout<<"Total number of nodes="<<co<<"\n";

 cout<<"Number of roots(trivial really)="<<b.cr<<"\n";
  cout<<"Number of leaves="<<b.cl<<"\n";
  cout<<"Number of internal nodes="<<b.ci<<"\n";

  cout<<"Enter lower and upper limits\n";
  cin>>j;
  cin>>k;
  
  int rc=b.range(b.root,j,k);
  cout<<"Number of nodes within range="<<rc<<"\n";
  

  /* if(co==n)
   {
    cout<<"\niT wOrKs!\n";
   }
  else
   {
    cout<<"\ntry again\n";
   } */
 return 0;
}
