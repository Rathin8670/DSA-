#include<bits\stdc++.h>
using namespace std;
class Node{
    public:
    Node *left;
    int data;
    Node *right;
    int height;
};
Node *root=NULL;
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

Node *inPre(Node *p){
    while(p &&p->right){
        p=p->right;
    }
    return p;
}
Node *inSucc(Node *p){
    while(p&&p->left){
        p=p->left;
    }
    return p;
}

Node *Delete(Node *p,int key){
    Node *q;
    if(p==0) return nullptr;
    //for leaf node
    if(p->left==0 && p->right==0){
        if(p==root)
            root=nullptr;
        delete(p);
        return NULL;
    }
    if(key<p->data){
        p->left=Delete(p->left,key);
    }else if(key>p->data){
        p->right=Delete(p->right,key);
    }else{
        if(NodeHeight(p->left)>NodeHeight(p->right)){
            q=inPre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,key);

        }else{
            q=inSucc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,key);

        }
    }
    //update height
    p->height=NodeHeight(p);

    //balance factor and rotation
    //L1 or LL rotation
    if(balFactor(p)==2 && balFactor(p->left)==1){
        return LLrotation(p);
    }
    //L-1 or LR rotation
    else if(balFactor(p)==2 && balFactor(p->left)==-1){
        return LRrotation(p);
    }
    //R-1 rotation
    else if(balFactor(p)==-2 && balFactor(p->right)==-1){
        return RRrotation(p);
    }
    //R1 
    else if(balFactor(p)==-2 && balFactor(p->right)==1){
        return RLrotation(p);
    }
    //L0
    else if(balFactor(p)==2 && balFactor(p->left)==0){
        return LLrotation(p);
    }
    //R0
    else if(balFactor(p)==2 && balFactor(p->right)==0){
        return RRrotation(p);
    }
    return p;

}

int main(){
    vector<int>v={10,20,30,25,28,27,5};
    for(int i=0;i<v.size();i++){
        root=rinsert(root,v[i]);
    }
    inOrder(root);
    int x;
    cout<<"\nEnter the element to delete:"<<endl;
    cin>>x;
    Delete(root,x);
    inOrder(root);
    cout<<"\nThe root of AVL tree="<<root->data;


}