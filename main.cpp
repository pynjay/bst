#include <iostream>
using namespace std;

struct bstNode{
    int data;
    struct bstNode *left;
    struct bstNode *right;
};

bool isBst(struct bstNode *x, int min, int max){
    if(x == NULL) return true;
    if(x->data >= min && x->data <= max && isBst(x->left, min, x->data) && isBst(x->right, x->data, max)){
        return true;
    } else return false;

}

bstNode* findMin(bstNode* r){
    bstNode* temp = r;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

struct bstNode* newNode(int x){
    struct bstNode *temp = new bstNode();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


class Bst {
    private:
        struct bstNode *root;
        int itemNumber;

        struct bstNode* insertUtil(int, struct bstNode*);
        void insertUtil2(int, struct bstNode*);
        void inorderPrintUtil(struct bstNode*);
        void delTree(struct bstNode*);


        struct bstNode* delUtil(int, struct bstNode*);

    public:
        Bst();
        ~Bst();

        void insert(int);
        void insert2(int);
        
        int getTreeHeight();
        int getitemNumber();
        bool search(int);


        void inorderPrint();
        void postorderPrint();
        void preorderPrint();

        void levelPrint();

        void del(int);

        void setRoot(struct bstNode*);


};

Bst::Bst(){
    root = NULL;
    itemNumber = 0;
}


void Bst::delTree(struct bstNode *node){
    if(node == NULL){
        return;
    }
    delTree(node->left);
    delTree(node->right);
    delete node;
}

Bst::~Bst(){
    delTree(root);
}


struct bstNode* Bst::delUtil(int x, struct bstNode *node){
    if(node == NULL) return NULL;
    if(node->data > x){
        node->left = delUtil(x, node->left);
    } else if(node->data < x) {
        node->right = delUtil(x, node->right);
    } else {
        if(node->left == NULL && node->right == NULL){
            delete node;
            return NULL;
        } else if (node->left == NULL){
            bstNode *temp = node->right;
            delete node;
            return temp;
        } else if (node->left == NULL){
            bstNode *temp = node->left;
            delete node;
            return temp;
        } else {
            bstNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = delUtil(node->data, node->right);
        }
    }
     return node;
}

void Bst::del(int x){
    if(root==NULL) return;
    root = delUtil(x, root);
}


struct bstNode* Bst::insertUtil(int x, struct bstNode *r){
    if(r == NULL){
        r = newNode(x);
    } else if(x < r->data){
        cout << r << endl;
        r->left = insertUtil(x, r->left);
    } else{
        r->right = insertUtil(x, r->right);
    }
    return r;
}

void Bst::insert(int x){
    if(root == NULL){
        root = newNode(x);
        cout << root << endl;
        return;
    }
    insertUtil(x, root);
}

void Bst::insertUtil2(int x, struct bstNode *r){
    if(r->data > x){
       if(r->left == NULL){
           r->left = newNode(x);
           return;
       } else insertUtil2(x, r->left);
    } else if(r->data < x){
        if(r->right == NULL){
           r->right = newNode(x);
           return;
       } else insertUtil2(x, r->right);
    } else return;
}

void Bst::insert2(int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    insertUtil2(x, root);
}


void Bst::inorderPrintUtil(struct bstNode* node){
    if(node == NULL){
        return;
    }
    inorderPrintUtil(node->left);
    cout << node->data << ' ';
    inorderPrintUtil(node->right);
}

void Bst::inorderPrint(){
    inorderPrintUtil(root);

    cout << endl;

    cout << isBst(root, -1000, 1000) << endl;
}

int main(){

    Bst tree;
    tree.insert2(8);
    tree.insert2(3);
    tree.insert2(4);
    tree.insert2(7);
    tree.insert2(10);
    tree.insert2(12);
    tree.insert2(9);
    tree.insert2(0);
    tree.insert2(1);
    tree.insert2(75);
    tree.insert2(9);

    tree.del(12);
    tree.del(1);
    tree.del(2);
    tree.del(0);
    tree.del(3);
    tree.del(10);
    tree.del(9);
    tree.del(4);
    tree.del(7);
    tree.del(8);
    tree.del(75);

    tree.inorderPrint();

    

}