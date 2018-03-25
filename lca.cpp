#include <iostream>
using namespace std;

struct Node {
  struct Node *left, *right;
  int key;
};

struct Node *newNode(int item) {
  struct Node *temp = new Node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key;
    inorder(root->right);
  }
}

struct Node *insert(struct Node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  return node;
}

int check_element(Node *root, int x) {
  if (root != NULL) {
    if (root->key == x)
      return true;

    else
      return check_element(root->left, x) || check_element(root->right, x);
  }
  return false;
}
struct Node *check_lca(struct Node *root, int a, int b) {
  if (root == NULL) return NULL;

  if (root->key == a || root->key == b) return root;

  Node *left = check_lca(root->left, a, b);
  Node *right = check_lca(root->right, a, b);

  if (left && right) return root;
  if (left != NULL)
    return left;
  else
    return right;
}

int main() {
  int i = 1, arr[100000], n;
  cout << "enter the no of elements in the tree " << endl;
  cin >> n;
  Node *root = NULL;
  cout << "Enter the elements:" << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  root = insert(root, arr[0]);
  n = n - 1;
  while (n--) {
    insert(root, arr[i]);
    i++;
  }
  inorder(root);
  int ele1, ele2;
  cout << "\nEnter the elements of which lca has to be found " << endl;
  cin >> ele1 >> ele2;

  if (check_element(root, ele1) && check_element(root, ele2))
    cout << "LCA OF\t" << ele1 << "and\t" << ele2 << "is"
         << "\t" << check_lca(root, ele1, ele2)->key;
  else
    cout << "Element not present in the tree" << endl;

  return 0;
}
