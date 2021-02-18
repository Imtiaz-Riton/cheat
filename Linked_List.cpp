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
    Node* next;
};
Node* head;

void insertBeg(int x){
    Node* cur = new Node();
    cur->data = x;
    cur->next = head;
    head = cur;
}

void insertEnd(int x){

    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else{
        Node* cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}

void insertNthPos(int pos, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* cur = head;
    for(int i = 0; i < pos - 2; i++){
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
}

void Delete(int pos){

    Node* cur = head;
    if(pos == 1){
        head = cur->next;
        delete(cur);
        return;
    }
    for(int i = 0; i < pos - 2; i++){
        cur = cur->next;
    }
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete(tmp);
}

void reverse(Node* cur){
    if(cur->next == NULL){
        head = cur;
        return;
    }
    reverse(cur->next);
    Node* q = cur->next;
    q->next = cur;
    cur->next = NULL;
}

void travarse(){
    Node* cur = head;
    bool ok = false;
    while(cur != NULL){
        cout << cur->data << ' ';
        cur = cur->next;
        ok = true;
    }
    if(!ok){
        cout << "the list is empty" << nl;
    }
    cout << nl;
}

void solve(){
    head = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, pos;
        cin >> x;

        //insertBeg(x);
        insertEnd(x);
        //insertNthPos(pos, x);
    }
    travarse();
    reverse(head);
    travarse();
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
