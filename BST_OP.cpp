#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
Node *root=NULL;

void create(){
    Node *p,*t;
    int x;
    cout<<"enter root value: "<<endl;
    cin>>x;
    queue<Node*>q;
    root=new Node;
    root->data=x;
    root->rchild=root->lchild=NULL;
    q.push(root);
    while(!q.empty()){       //continue still q is not empty
        p=q.front();
        q.pop();
        cout<<"enter left child of "<<p->data<<" ";
        cin>>x;
        /*for left child */
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.push(t);
        }
        cout<<"enter right child of "<<p->data<<" ";
        cin>>x;
        /*for right child*/
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.push(t);
        }
    }
}
Node* search(Node *p,int key){
    if(p==NULL) return NULL;
    while(p!=NULL){
        if(p->data==key)
            return p;
        else if(p->data>key)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return NULL;        //return null while key is not found
}
Node* rSearch(Node *p,int key){
    if(p==NULL) return NULL;
    if(p->data==key) return p;
    else if(p->data>key) rSearch(p->lchild,key);
    else rSearch(p->rchild,key);
}

void insert(int key){
    Node *p=new Node;
    p->data=key;
    p->lchild=NULL;
    p->rchild=NULL;

   //for 1st element
   if(root==NULL){
    root=p;
    return;      //terminate the program bcz 1st node is inserted....for this return use
   }


   Node *t=root;
   Node *r;
   while(t!=NULL){
    r=t;
    if(key<t->data){
        t=t->lchild;
    }
    else if(key>t->data){
        t=t->rchild;
    }else{
        return ;
    }
   }

if(key<r->data)
    r->lchild=p;
else
    r->rchild=p;
    
}
/*=========================================*/
/*for displaying the bst */
//Inorder traversal method
void inOrder(Node *p){
    if(p){
        inOrder(p->lchild);
        cout<<p->data<<" ";
        inOrder(p->rchild);
    }

}
/*=======================================*/
int Height(Node *p){
    int x,y;
    if(p==nullptr) 
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}


/*Inorder predecessor*/
Node* Inpre(Node *p){
    while(p&&p->rchild){
        p=p->rchild;
    }
    return p;
}


/*Inorder successor*/
Node* Insucc(Node *p){
    p=p->rchild;
    while(p&&p->lchild){
        p=p->lchild;
    }
    return p;
}

Node* Delete(Node* p, int key) {
    Node* q;
    if (p == 0)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root)
            root = NULL;
        delete (p);
        return NULL;
    }
    if (key < p->data) {
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Delete(p->rchild, key);
    }
    else {      /*found the key element*/
        if (Height(p->lchild) > Height(p->rchild)) {
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

//deleting nodes
Node* remove(Node* root1,int key){
    if(!root1) return NULL;
    Node* x=root1;
    Node* parent=NULL;

    //for single child or no child
    while(x!=NULL || key!=x->data){
        parent=x;
        if(key<x->data)
        x=x->lchild;
        else
        x=x->rchild;
    }
    if(!x){
        cout<<"Item not found\n";
        return NULL;
    } 
    Node* temp;
    if(!x->lchild || !x->rchild){
        if(!x->lchild) temp=x->rchild;
        else temp=x->lchild;
    }
        //for root=null 
        if(!parent){
            delete root1;
            root1=temp;
            return root1;
        }else{
        if(x==parent->lchild)
        parent->lchild=temp;
        else
        parent->rchild=temp;
        delete x;
        }
    Node* succ=x->rchild;
    Node* psucc=x;
    while(succ->lchild){
        psucc=succ;
        succ=succ->lchild;
    }
    //replace the value
    x->data=succ->data;
    //for succ have no left child
    if(psucc==x)
    x->rchild=succ->rchild;
    //for succ have left child
    else
    psucc->lchild=succ->rchild;
    delete succ;
    return root1;
}

int main(){
   // create();
   // inOrder(root);
    // cout<<"enter the key to search in the tree"<<endl;
    // int key;
    // cin>>key;
    // Node *ans=search(root,key);
    // if(ans!=NULL){
    //     cout<<"Element Found"<<endl;
    // }else{
    //     cout<<"Element Not Found"<<endl; 
    // }
    // int k;
    // cout<<"enter the element for delete:"<<endl;
    // cin>>k;
   // Delete(root,k);
    //remove(root,k);
    insert(90);
    insert(80);
    insert(70);
    inOrder(root);
}