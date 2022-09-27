#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Tree{
    private:
    int data;
    Tree *left,*right;

    public:

    Tree(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }

    Tree* insert(int val,Tree* root){
        if(root==NULL){
            return new Tree(val);
        }
        else if(val < root->data){
            root->left = insert(val,root->left);
        }
        else{
            root->right = insert(val,root->right);
        }
        return root;
    }

    void inorder(Tree *root){
        if(root==NULL) return;
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void levelOrder(Tree *root){
        if(root==NULL) return;
        vector<int> result;
        queue<Tree*> q;
        q.push(root);
        
        while(!q.empty()){

            int count = q.size();
            int print = q.size();
            while(count>0){
            Tree *curr = q.front();
            q.pop();
            //cout<<curr->data<<" ";
            if(count==print) cout<<curr->data<<" "; //left view
            //if(count==1) cout<<curr->data<<" "; //right view
            
            //result.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            count--;
            }
            cout<<endl;
        }

        /*for(auto it : result){
            cout<<it<<" ";
        }*/
    }

    void topView(Tree *root){
        map<int,int> m;
        queue<pair<Tree*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            Tree* node = q.front().first;
            int position = q.front().second;
            q.pop();
            if(m.count(position)==0){
                //m[position] = node->data;
                m[position] = node->data;
            }
            if(node->left){
                q.push({node->left,position-1});
            }
            if(node->right){
                q.push({node->right,position+1});
            }
        }

        for(auto x : m){
            cout<<x.second<<" ";
        }
    }

};

int main(){
    Tree *root=NULL;
    root= root->insert(7,root);
    root= root->insert(5,root);
    root= root->insert(4,root);
    root= root->insert(6,root);
    root= root->insert(8,root);
    root= root->insert(9,root);
    
    root->inorder(root);
    cout<<endl;
    root->levelOrder(root);
    cout<<endl;
    root->topView(root);
}