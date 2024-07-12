#include <iostream>
#include <sstream>
#include <queue>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string data = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                data += "#,";
                continue;
            } else {
                data += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            }
        }
        data.pop_back();
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        if (data[0] == '#') return NULL;
        stringstream ss(data);
        string node;
        getline(ss, node, ',');
        TreeNode* root = new TreeNode(stoi(node));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            getline(ss, node, ',');
            if (node == "#") {
                curr->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(node));
                curr->left = leftNode;
                q.push(leftNode);
            }
            getline(ss, node, ',');
            if (node == "#") {
                curr->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(node));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    Codec codec;

    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the string back to a tree
    TreeNode* deserializedRoot = codec.deserialize(serialized);

    // Print the deserialized tree
    cout << "Deserialized tree: ";
    printTree(deserializedRoot);

    // Cleanup
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
