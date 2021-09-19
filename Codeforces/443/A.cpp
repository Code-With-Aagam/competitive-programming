/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

class Node{
    public :
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(vector<int> &arr){
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    bool isLeft = true;
    Node* curr = NULL;
    q.push(root);
    int n = arr.size();
    for(int i = 1; i < n; i++){
        Node* node = NULL;
        if(arr[i] != -1){
            node = new Node(arr[i]);
            q.push(node);
        }
        if(isLeft){
            curr = q.front();
            q.pop();
            curr->left = node;
            isLeft = false;
        }
        else{
            curr->right = node;
            isLeft = true;
        }
    }
    return root;    
}

void printTopView(Node* node){
    if(node == NULL)
        return;
    queue<Node*> q;
    map<int, int> mp;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /**
    vector<int> arr;
    int ele;
    while(cin >>ele)
        arr.push_back(ele);
    Node* root = createTree(arr);
    printTopView(root);
    */
    set<char> st;
    char ch;
    // skip {
    cin >>ch;
    while(1){
        cin >>ch;
        // reached end
        if(ch == '}')
            break;
        // skip ,
        if(ch != ',')
            st.insert(ch);
    }
    cout <<st.size();
    return 0;
}
