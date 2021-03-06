#include <iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Accepts the old root node & data and returns the new root node
node* insertInBST(node *root,int data){
    //Base Case
    if(root==NULL){
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

bool search(node*root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    //Recursively search in left and right subtree
    if(data<=root->data){
        return search(root->left,data);
    }
    else{
        return search(root->right,data);
    }
}

node* build(){
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin>>d;

    node*root = NULL;

    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}
//Inorder Print
void inorder(node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}
node* arr2bst(int *arr,int s,int e){
	//base case
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = arr2bst(arr,s,mid-1);
	root->right = arr2bst(arr,mid+1,e);
	return root;

}

node* deleteInBST(node*root,int data){
    if(root==NULL){
        return NULL;
    }
    else if(data<root->data){
        root->left = deleteInBST(root->left,data);
        return root;
    }
    else if(data==root->data){
        //Found the node to delete 3 Cases
        //1. Node with 0 children - Leaf Node
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //2. Case Only 1 child
            if(root->left!=NULL && root->right==NULL){
                node* temp = root->left;
                delete root;
                return temp;
            }
            if(root->right!=NULL && root->left==NULL){
                node* temp = root->right;
                delete root;
                return temp;
            }
        //3. Case 2 children
            node *replace = root->right;
            //Find the inorder successor from right subtree
            while(replace->left!=NULL){
                replace = replace->left;
            }
            root->data = replace->data;
            root->right = deleteInBST(root->right,replace->data);
            return root;
    }
    else{
        root->right = deleteInBST(root->right,data);
        return root;
    }
}
int isBSTUtil(node* node, int min, int max){
    if (node==NULL){
        return 1;
    }
    if (node->data < min || node->data > max){
        return 0;
    }
    return isBSTUtil(node->left, min, node->data-1) && isBSTUtil(node->right, node->data+1, max);
}
int isBST(node* node){
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
struct node *lca(struct node* root, int n1, int n2)
{
    if (root == NULL){
        return NULL;
    }

    if (root->data > n1 && root->data > n2){
        return lca(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2){
        return lca(root->right, n1, n2);
    }

    return root;
}


int main(){
    node*root = build();
    //INPUT 5 3 7 1 6 8 -1
    //      5
    inorder(root);
    cout<<endl;

    int s;
    cin>>s;
    root = deleteInBST(root,s);
    inorder(root);
    cout<<endl;
    bfs(root);
    cout<<isBST(root)<<endl;
    cout<<lca(root,3,1)->data;



return 0;
}










