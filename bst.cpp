#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
};
class BST{
    public:
    Node* root;
    BST(){
        root=nullptr;
    }
    void insert(int);
    void inOrder(Node*);
    Node* getR(){
        return root;
    }
    int findmin();
    int findmax();
    bool search(int);
    int totalNode(Node*);
    int tExternalNode(Node*);
    int tInternalNode(Node*);
    void delNode(int key);
};
void BST::delNode(int key){
    if(!root){
        return;
    }
    Node* p=NULL;
    Node* x=root;
    
    //delete single child node or 0 child
    while(x&&x->data!=key){
        p=x;
        if(key<x->data){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    if(!x)return;
    if(x->left==NULL || x->right==NULL){
        Node* temp;
        if(x->left==NULL)
        temp=x->right;
        else
        temp=x->left;
    
    //for only root present case
    if(!p){
        delete root;
        root=temp;
        return;
    }
    if(p->left->data==key)
        p->left=temp;
    else
        p->right=temp;
    delete x;
    return;
}else{
    //for 2child  node
    Node* succ=x->right;
    Node* psucc=x;
    while(succ->left){
        psucc=succ;
        succ=succ->left;
    }
    x->data=succ->data;
    //succ have no right node
    if(psucc==x){
        x->right=succ->right;
    }else{
        //succ have right node
        psucc->left=succ->right;
    }
    delete succ;
    return;
}
    
}
int BST::tExternalNode(Node* p){
    if(!p) return 0;
    if(p->left==NULL && p->right==NULL) return 1;
    int left=tExternalNode(p->left);
    int right=tExternalNode(p->right);
    return left+right;
}
int BST::tInternalNode(Node* p){
    if(!p || (!p->left && !p->right )) return 0;
    int left=tExternalNode(p->left);
    int right=tExternalNode(p->right);
    return left+right+1;
}
int BST::totalNode(Node* p){
    if(!p) return 0;
    int left=totalNode(p->left);
    int right=totalNode(p->right);
    return left+right+1;
}
int BST::findmin(){
    Node* p=root;
    while(p->left){
        p=p->left;
    }
    return p->data;
}
int BST::findmax(){
    Node* p=root;
    while(p->right){
        p=p->right;
    }
    return p->data;
}
bool BST::search(int key){
    Node* temp=root;
    while(temp){
        if(key<temp->data)
            temp=temp->left;
        else if(key>temp->data)
            temp=temp->right;
        else
            return true;
    }
    return false;
}
void BST::insert(int key){
    Node* temp=new Node;
    temp->data=key;
    temp->left=temp->right=NULL;
    if(!root){
        root=temp;
        return;
    }
    Node* p=root;
    Node* parent;
    while(p){
        parent=p;
        if(key>p->data){
            p=p->right;
        }else if(key<p->data){
            p=p->left;
        }else{
            return;
        }
    }
    if(key<parent->data)
        parent->left=temp;
    else
        parent->right=temp;
    

}
void BST::inOrder(Node* p){
    if(p){
    inOrder(p->left);
    cout<<p->data<<" ";
    inOrder(p->right);
    }
}
int main(){
    BST b;
    b.insert(90);
   // b.insert(100);b.insert(110);
    b.insert(70);b.insert(80);
//In your main function, you first create a BST object b, and then you call b.getR() to get the root of the tree and store it in the pointer r. However, at this point in your code, the BST object b has an empty tree because you haven't inserted any elements into it yet.

// So, when you call b.inOrder(r);, you are trying to perform an in-order traversal of an empty tree, which will lead to undefined behavior and likely a segmentation fault or crash.

// To fix this issue, you should move the b.inOrder(r); call after you have inserted elements into the tree. Here's the corrected main function:

    Node* r=b.getR();
    b.inOrder(r);
    cout<<endl;
    cout<<b.findmin()<<endl;
    cout<<b.findmax()<<endl;
    //cout<<b.search(900)<<endl;
    // cout<<b.totalNode(r)<<endl;
    // cout<<b.tExternalNode(r)<<endl;
    // cout<<b.tInternalNode(r)<<endl;
    b.delNode(90);
    Node* r0=b.getR();
    b.inOrder(r0);
    

}