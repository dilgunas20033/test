#include <iostream>
// the tree node struct
struct TreeNode {
    int info;
    TreeNode *left, *right;
};
// the binary search tree class
// this is a very minimal implementation
// for example we should have destructor
// also we could have search, delete etc.
class BinSearchTree {
public:
    bool insert(int newInt);
    void traverseNodes(TreeNode* root);
    void traverseNodes();
    int findMax(TreeNode* root);
    int findMax();
private:
    TreeNode* root = nullptr;
};
// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root;
    TreeNode* q = nullptr;
    while (p != nullptr) {
        if (p->info == newInt) {
            return false;
        }
        q = p;
        if (newInt < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
// new node
    TreeNode* v = new TreeNode;
    v->info = newInt;
    if (q == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < q->info) {
        std::cout << "Insert " << v->info << " left to " << q->info <<
                  std::endl;
        q->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << q->info <<
                  std::endl;
        q->right = v;
    }
    return true;
}
// traversal
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}
void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr)
        return;
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}

int BinSearchTree::findMax() {
    int q = findMax(root);
    return q;
}

int BinSearchTree::findMax(TreeNode* root) {


    if (root == nullptr) {
       return 0;
    }

    int max = root->info;
    int q = findMax(root->left);
    int p = findMax(root->right);

    if (q > max) {
        max = q;
    }

    if (p > max) {
        max = p;
    }


    return max;
}
////////////////////////////////////////////
int main() {
    BinSearchTree st = BinSearchTree(); // the tree object
    st.insert(8); //the root
// where will each of this go in the BST?
    st.insert(3);
    st.insert(11);
    st.insert(9);
    st.insert(10);
    st.insert(14);
// now traverse
    std::cout << "inorder traversal: ";
    st.traverseNodes();
    int q = st.findMax();
    std::cout << std::endl << "The maximum value is: " << q;
}
