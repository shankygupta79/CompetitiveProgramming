#include <iostream>
#include<queue>
using namespace std;
int distan=0;
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

node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }
    node * root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(node*root){
    if(root==NULL){
        return;
    }
    //Otherwise Left Root Right
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node*root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printKthLevel(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;

}
int diameter(node*root){
	//largest distance btw any two nodes!
	if(root==NULL){
		return 0;
	}
	int op1 = height(root->left) + height(root->right);
	int op2 = max(diameter(root->left),diameter(root->right));
	return max(op1,op2);
}
void root2LeafAllPaths(node*root,vector<int> &v){

	if(root==NULL){
		return;
	}

	if(root->left==NULL and root->right==NULL){
		v.push_back(root->data);
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" --> ";
		}
		cout<<endl;
		v.pop_back();
		return;
	}
	//rec case
	v.push_back(root->data);
	root2LeafAllPaths(root->left,v);
	root2LeafAllPaths(root->right,v);
	v.pop_back();
	return;
}

void printAllLevels(node*root){
    int H = height(root);

    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}

int count(node*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}
//Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
node *LCA(struct node* root, int n1, int n2){
    if (root == NULL){
        return NULL;
    }
    if (root->data==n1 || root->data == n2){
        return root;
    }
    node *l  = LCA(root->left, n1, n2);
    node *r = LCA(root->right, n1, n2);

    if (l!=NULL && r!=NULL){
        return root;
    }

    if(l != NULL){
        return l;
    }else{
        return r;
    }
}

void dist(node*root,int n1,int n2,int lvl){

    if(root==NULL){
        return;
    }
    if(root->data==n1 || root->data==n2){
        distan=distan+lvl;
    }
    dist(root->left,n1,n2,lvl+1);
    dist(root->right,n1,n2,lvl+1);


}

node*mirror(node*root){
    if(root==NULL){
        return NULL;
    }
    mirror(root->left);
    mirror(root->right);
    node*temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}


void bfs(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        cout<<f->data<<",";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}
void lvl2(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        int n=size;
        cout<<endl;
        while(n--){
            node* f = q.front();
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



int main(){
    //TREE
    //         8
    //       /   \
    //      10    3
    //     /  \     \
    //    1    6     14
    //       /   \   /
    //       9   7   13
    node* root = buildTree();
    //INPUT FILE IS (8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1)
    //cout<<count(root)<<endl;
    //printAllLevels(root);
    bfs(root);
    cout<<endl;
    cout<<"ALL LEVELS"<<endl;
    printAllLevels(root);
    cout<<"Printing Tree PRE"<<endl;
    print(root);
    cout<<endl;
    cout<<"Printing Tree INORDER"<<endl;
    printIn(root);
    cout<<endl;
    cout<<"Printing Tree POSTORDER"<<endl;
    printPost(root);
    cout<<"\nRoot to Leaf"<<endl;
    vector<int> v;
    root2LeafAllPaths(root,v);
    cout<<"\nLCA of 8 and 13 is "<<LCA(root,8,13)->data<<endl;
    node*lca=LCA(root,3,13);
    dist(lca,3,13,0);
    cout<<"Distance "<<distan<<endl;
    cout<<"Diameter of Binary Tree i.e max distance "<<diameter(root)<<endl;
    cout<<"Level order ( everylevel ) ";
    lvl2(root);
    node*mroot=mirror(root);
    cout<<"\nMirror Tree"<<endl;
    lvl2(mroot);

return 0;
}










