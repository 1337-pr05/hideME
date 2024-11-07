#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
bool search_bst(Node*,int);
bool searchR_bst(Node*,int);
int min(Node*);
Node* deletion(Node*,int);
void levelOrderTravesal(Node * root){
    if(root!=NULL){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp ==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
  }else{
    cout<<"ROOT NODE EMPTY";
    return;
  }
}

void display_bst_inorderTraversal(Node*root){
    //base case
    if(root == NULL){
        return;
    }else{
    display_bst_inorderTraversal(root->left);
    cout<<root->data<<" ";
    display_bst_inorderTraversal(root->right);}
}

void create_bst(Node*&root,int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return;
    }
    if(data > root->data){
        create_bst(root->right,data);
    }
    else{
        create_bst(root->left,data);
    }
}

int main(){
    int arr[5] = {-10,-3,0,5,6};
    Node* root = NULL;
    int data;
    cout<<"enter the data";
    cin>>data;
    while(data != -1){
        create_bst(root,data);
        cout<<"enter the data";
        cin>>data;
    }
    // for(int i =0;i<5;i++){
    //     int data;
    //     cin>>data;
    //     create_bst(root,data);
    // }
    //levelOrderTravesal(root);
    cout<<endl<<search_bst(root,5);
    cout<<endl<<searchR_bst(root,5)<<endl;
    display_bst_inorderTraversal(root);
    cout<<endl<<"enter the element you want to delete : ";
    int del;
    cin>>del;
    root = deletion(root,del);
    cout<<endl;
    display_bst_inorderTraversal(root);
    return 0;

}
//recursion searching;

bool searchR_bst(Node* root, int data){
    //base case
    if(root ==NULL){
        return false;
    }if(root->data == data){
        return true;
    }else if(root->data > data){
        searchR_bst(root->left,data);
    }else{
        searchR_bst(root->right,data);
    }
}


// with iteration
bool search_bst(Node*root,int data){
    Node* temp = root;
    while(temp!=NULL){
        if(temp ->data == data){
            return true;
        }else if(temp->data > data){
            temp= temp->left;
        }else{
            temp = temp->right;
        }
        return false;
    }
}

Node* deletion(Node *root,int data){
    if(root ==NULL){
        return NULL;
    }
    if(root->data == data){
        // Zero child
        if(root->left ==NULL && root->left ==NULL){
            delete root;
            return NULL;
        }
        // 1 child node
        //left child node exists 
        if(root->left != NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //2 child nodes
        if(root->left != NULL && root->right != NULL){
            int min_right = min(root->right);
            root->data = min_right;
            root->right = deletion(root->right,min_right);
            return root;
        }
    }else if(data > root->data){
        root->right = deletion(root->right,data);
        return root;
    }else{
        root->left = deletion(root->left,data);
        return root;
    }
}

int min(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}