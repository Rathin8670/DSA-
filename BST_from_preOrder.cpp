#include<bits/stdc++.h>
using namespace  std;
class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *root=NULL;
void createPre(int pre[],int n){
    Node *t,*p;
    stack<Node*>st;
    int i=0;
    root=new Node;
    root->data=pre[i++];
    root->lchild=root->rchild=nullptr;
    
    p=root;
    while(i<n){
        if(pre[i]<p->data){
            t=new Node;
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            st.push(p);
            p=t;
        }else{
            if(pre[i]>p->data && pre[i]<(st.empty()?32767:st.top()->data)){
            t=new Node;
            t->data=pre[i++];
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            p=t; 
            }else{
                p=st.top();
                st.pop();
            }
        }
    }
}
void inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }

}
void preOrder(Node *p){
    if(p){      //means p!=NULL
    cout<<p->data<<" ";
    preOrder(p->lchild);
    preOrder(p->rchild);
    }
}

void postOrder(Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main(){
    int arr[]={30,20,10,15,25,40,50,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    createPre(arr,n);
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
}
