#include <bits/stdc++.h>
#define ll long long
#define nl "\n"
#define ii pair<int, int>
#define MOD 1000000007
#define inf 1 << 29
using namespace std;

const int M = 2e5 + 7;

struct Node{
    int data;
    Node* lft;
    Node* rgt;
};

Node* newNode(int val){
    Node* tmp = new Node();
    tmp->data = val;
    tmp->lft = tmp->rgt = NULL;
    return tmp;
}

Node* insert(Node* root, int val){
    if(root == NULL){
       return newNode(val);
    }
    if(val <= (root)->data) root->lft = insert((root)->lft, val);
    else if(val > root->data) root->rgt = insert((root)->rgt, val);
    return root;
}

bool search(Node* root, int val){

    if(root == NULL) return false;
    if(root->data == val) return true;
    else if(val <= root->data) return search(root->lft, val);
    else return search(root->rgt, val);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << ' ';  
    preorder(root->lft);
    preorder(root->rgt);
}

void inorder(Node* root){

    if(root == NULL) return;
    inorder(root->lft);
    cout << root->data << ' ';
    inorder(root->rgt);
}

void postorder(Node* root){

    if(root == NULL) return;
    postorder(root->lft);
    postorder(root->rgt);
    cout << root->data << ' ';
}

void solve(){
    Node* root = NULL;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(i == 0)
            root = insert(root, x);
        else insert(root, x);
    }

    // int key;
    // cin >> key;

    // if(search(root, key)){
    //     cout << "Found" << nl;
    // }
    // else cout << "Not Found !" << nl;
    preorder(root);
    cout << nl;
    inorder(root);
    cout << nl;
    postorder(root);
    cout << nl;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false), cin.tie(0);

    int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
