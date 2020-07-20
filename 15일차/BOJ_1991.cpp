#include <iostream>
#include <vector>
using namespace std;

void pre(int root);
void mid(int root);
void post(int root);

struct treenode
{
    char data = '.';
    treenode * left = nullptr;
    treenode * right = nullptr;
};

vector <treenode> tree(27);

int main () {
    int n;
    char v,l,r;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v >> l >> r;

        tree[v-'A'].data = v;

        if(l == '.') {
            tree[v-'A'].left = nullptr;
        } else {
            tree[v-'A'].left = &tree[l-'A'];
        }

        if(r == '.') {
            tree[v-'A'].right = nullptr;
        } else {
            tree[v-'A'].right = &tree[r-'A'];
        }

    }

    pre(0);
    cout << "\n";
    mid(0);
    cout << "\n";
    post(0);

}

void pre(int index) {

    cout << tree[index].data;

    if(tree[index].left != nullptr) {
        pre(tree[index].left->data - 'A');
    }
    
    if(tree[index].right != nullptr) {
        pre(tree[index].right->data - 'A');
    }

    

}

void mid(int index) {

    if(tree[index].left != nullptr) {
        mid(tree[index].left->data - 'A');
    }

    cout << tree[index].data;
    
    if(tree[index].right != nullptr) {
        mid(tree[index].right->data - 'A');
    }

}

void post(int index) {
    
    if(tree[index].left != nullptr) {
        post(tree[index].left->data - 'A');
    }

    if(tree[index].right != nullptr) {
        post(tree[index].right->data - 'A');
    }

    cout << tree[index].data;

}