#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *left;
    int data;
    Node *right;
    int height;
};
class AVL{
    Node* root;
    public:
    AVL(){
        root=NULL;
    }
    Node* getR(){
        return root;
    }
    int getH(Node*);
    int getBal(Node*);
    Node* rightR(Node*);
    Node* leftR(Node*);
    Node* newNode(int);
    Node* insert(Node*,int);
    void inOrder(Node*);
    Node* delNode(Node*,int);

};
Node* AVL::delNode(Node* r,int key){
    if(!r) return r;
    if(key<r->data)
        r->left=delNode(r->left,key);
    else if(key>r->data)
        r->right=delNode(r->right,key);
    else{
        Node* temp;
        //have right child case
        if(!r->left){
        temp=r->right;
        delete r;
        return temp;
        }//have left child case
        else if(!r->right){
            temp=r->left;
            delete r;
            return temp;
        }//have two child case
        else{
            temp=r->right;
            r->data=temp->data;
            r->right=delNode(r->right,temp->data);
        }
    }
    r->height=1+max(getH(r->left),getH(r->right));
    int balance=getBal(r);
     //LL case
    if(balance>1 && key<r->left->data)
        return rightR(r);
    // LR CASE
    if(balance>1 && key>r->left->data){
        r->left=leftR(r->left);
        return rightR(r);
    }
    //RR case
    if(balance<-1 && key>r->right->data)
        return leftR(r);
    // RL CASE
    if(balance<-1 && key<r->right->data){
        r->right=rightR(r->right);
        return leftR(r);
    }
    return r;


}

Node* AVL::newNode(int key){
    Node* temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    temp->height=1;
    return temp;
}

int AVL::getH(Node* p){
    if(!p) return 0;
    return p->height;
}

int AVL::getBal(Node* p){
    if(!p) return 0;
    return getBal(p->left)-getBal(p->right);
}

//LL case means right rotation
Node* AVL::rightR(Node* x){
    Node* y=x->left;
    Node* temp=y->right;
    //ekhanei khela holo🤓🤪
    y->right=x;
    x->left=temp;
    //change the heights
    x->height=1+max(getH(x->left),getH(x->right));
    y->height=1+max(getH(y->left),getH(y->right));

    return y;
}

//RR case means left rotation
Node* AVL::leftR(Node* x){
    Node* y=x->right;
    Node* temp=y->left;

    y->left=x;
    x->right=temp;
    
    x->height=1+max(getH(x->left),getH(x->right));
    y->height=1+max(getH(y->left),getH(y->right));

    return y;
}

Node* AVL::insert(Node* p,int key){
    if(!p){
       return newNode(key);
    }
    if(key<p->data)
        p->left=insert(p->left,key);
    else
        p->right=insert(p->right,key);

    //update height
    p->height=1+max(getH(p->left),getH(p->right));

    int balance=getBal(p);
    //LL case
    if(balance>1 && key<p->left->data)
        return rightR(p);
    // LR CASE
    if(balance>1 && key>p->left->data){
        p->left=leftR(p->left);
        return rightR(p);
    }
    //RR case
    if(balance<-1 && key>p->right->data)
        return leftR(p);
    // RL CASE
    if(balance<-1 && key<p->right->data){
        p->right=rightR(p->right);
        return leftR(p);
    }

    return p;
}

void AVL::inOrder(Node *p){
    if(p){
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}
int main(){
    AVL a;
    Node* r1=NULL;
    r1=a.insert(r1,50);
    r1=a.insert(r1,40);
    r1=a.insert(r1,60);
    r1=a.insert(r1,65);
    r1=a.insert(r1,55);
   // r1=a.insert(r1,40);
    
    a.inOrder(r1);
    cout<<endl;
    Node* r2;
    r2=a.delNode(r1,60);

    a.inOrder(r2);
}
