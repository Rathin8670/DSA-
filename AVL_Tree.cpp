#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *left;
    int data;
    Node *right;
    int height;
};
Node *root;
// class AVL{
//     public:
//     Node *root;
//     AVL(){root=nullptr;}
//     int NodeHeight(Node *p);
//     int balFactor(Node *p);
//     Node* LLrotation(Node *p);
//     void rinsert(Node *p,int key);
//     //traversal
//     void inOrder(Node *p);
// };


int NodeHeight(Node *p){
    int lh,rh;
    lh=(p&&p->left)?p->left->height:0;
    rh=(p&&p->right)?p->right->height:0;
    return lh>rh?lh+1:rh+1;
}

int balFactor(Node *p){
    int lh,rh;
    lh=(p&&p->left)?p->left->height:0;
    rh=(p&&p->right)?p->right->height:0;
    return lh-rh;
}

Node* LLrotation(Node *p){
    Node *pl=p->left;
    Node *plr=pl->right;
    pl->right=p;
    p->left=plr;

    //update height
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    //update root
    if(root==p){
        root=pl;
    }
    return pl;
}

Node* LRrotation(Node *p){
    Node *pl=p->left;
    Node *plr=pl->right;

    pl->right=plr->left;
    p->left=plr->right;

    plr->left=pl;
    plr->right=p;

    //update height
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    //update root
    if(root==p){
        root=plr;
    }
    return plr;
}


Node* RRrotation(Node *p) {
    Node* pr = p->right;
    Node* prl = pr->left;
 
    pr->left = p;
    p->right = prl;
 
    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}

Node* RLrotation(Node *p) {
    Node* pr = p->right;
    Node* prl = pr->left;
 
    pr->left = prl->right;
    p->right= prl->left;
 
    prl->right = pr;
    prl->left = p;
 
    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}


void inOrder(Node *p){
    if(p){
        inOrder(p->left);
        cout<<p->data<<" ";
        inOrder(p->right);
    }
}


Node* rinsert(Node *p,int key){
    Node *t;
    if(p==NULL){
        t=new Node;
        t->data=key;
        t->left=t->right=nullptr;
        t->height=1;
        return t;
    }
    if(key<p->data){
        p->left=rinsert(p->left,key);
    }
    else if(key>p->data){
        p->right=rinsert(p->right,key);
    }

    //update height
    p->height=NodeHeight(p);

    //balance factor and rotation 
    if(balFactor(p)==2 && balFactor(p->left)==1){
        return LLrotation(p);
    }
    else if(balFactor(p)==2 && balFactor(p->left)==-1){
        return LRrotation(p);
    }
    else if(balFactor(p)==-2 && balFactor(p->left)==-1){
        return RRrotation(p);
    }
    else if(balFactor(p)==-2 && balFactor(p->left)==1){
        return RLrotation(p);
    }
    return p;
}

int main(){
    
    root=rinsert(root,30);
    rinsert(root,40);
    rinsert(root,20);
    rinsert(root,10);
    rinsert(root,25);
    rinsert(root,50);
    rinsert(root,5);
    rinsert(root,15);
    rinsert(root,28);
   //rinsert(root,4);
    inOrder(root);
    
    cout<<"\nRoot is="<<root->data<<endl;
}
