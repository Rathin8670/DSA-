#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* rchild;
    int data;
    Node* lchild;
};
 Node *root;

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
/*Displaying binary Tree in diff form*/
// void preOrder(Node *p){
//     if(p){      //means p!=NULL
//     cout<<p->data<<" ";
//     preOrder(p->lchild);
//     preOrder(p->rchild);
//     }
// }
// void inOrder(Node *p){
//     if(p){
//         inOrder(p->lchild);
//         cout<<p->data<<" ";
//         inOrder(p->rchild);
//     }
// }
// void postOrder(Node *p){
//     if(p){
//         postOrder(p->lchild);
//         postOrder(p->rchild);
//         cout<<p->data<<" ";
//     }
// }


/*Iterative form of traversing a binary tree*/
void preOrder(Node *p){
    stack<Node*>st;
    while(p!=NULL || !st.empty()){
        if(p){
            cout<<p->data<<" ";
            st.push(p);
            p=p->lchild;
        }else{
            p=st.top();
            st.pop();
            p=p->rchild;
        }
    }
    
}
void inOrder(Node *p){
    stack<Node*>st;
    while(p!=NULL || !st.empty()){
        if(p){
            st.push(p);
            p=p->lchild;
        }else{
            p=st.top();
            st.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
}

// void postOrder(Node *p){
//     stack<long int>st;
//     long int temp;
//     while(p!=NULL || !st.empty()){
//         if(p){
//             st.push((long int)p);
//             p=p->lchild;
//         }else{
//             temp=(long int)st.top();
//             st.pop();
//             if(temp>0){
//                 st.push(-1*temp);
//                 p=((Node*)temp)->rchild;
//             }else{
//                 cout<<((Node*)(-1*temp))->data<<" ";
//                 p=NULL;
//             }


//         }
//     }
// }
void levelOrder(Node *p){
    queue<Node*>q;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            q.push(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            q.push(p->rchild);
        }
    }
}


/*counting height and nodes*/
int nodeCount(Node *p){
    int a,b;
    if(p){
        a=nodeCount(p->lchild);
        b=nodeCount(p->rchild);
        return a+b+1;
    }
    return 0;
}
int height(Node *p){
    int x=0,y=0;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
    }else{
        return 0;
    }
    return x>y?x+1:y+1;
}
/*count leaf nodes*/
int leafCount(Node *p){
    int x,y;
    if(p){
        x=leafCount(p->lchild);
        y=leafCount(p->rchild);
        if(!p->lchild && !p->rchild){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}
int main(){

    create();
    preOrder(root);
    cout<<endl;
    //  inOrder(root);
    // // cout<<endl;
   // postOrder(root);
   levelOrder(root);
   cout<<endl;
   cout<<nodeCount(root)<<endl;
   cout<<height(root)<<endl;
   cout<<leafCount(root)<<endl;


}
