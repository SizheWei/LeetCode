////
////  main.cpp
////  TreeClass
////
////  Created by 魏思哲 on 2022/7/31.
////  Copyright © 2022 SizheWei. All rights reserved.
////
//
//#include <queue>
//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class bTree {
//public:
//    virtual void clear() = 0;
//    virtual bool isEmpty() const = 0;
//    virtual T Root(T flag) const = 0;
//    virtual T parent(T x, T flag) const = 0;
//    virtual T lchild(T x, T flag) const = 0;
//    virtual T rchild(T x, T flag) const = 0;
//    virtual void delLeft(T x) = 0;
//    virtual void delRight(T x) = 0;
//    virtual void preOrder() const = 0;
//    virtual void midOrder() const = 0;
//    virtual void postOrder() const= 0;
//    virtual void levelOrder() const = 0;
//};
//
//template<class T>
//class binaryTree : public bTree<T> {
//     friend void printTree(const binaryTree &t, T flag);
//private:
//    struct Node {  //二叉树的结点类
//        Node  *left , *right ;
//        T data;
//        Node():left(NULL), right(NULL) {}
//        Node(T item, Node *L = NULL, Node * R =NULL ):data(item), left(L), right(R) {}
//        ~Node() {}
//     };
//     Node *root;
//
//public:
//    binaryTree() : root(NULL) {}
//    binaryTree(T x) { root = new Node(x); }
//    ~binaryTree();
//    void clear() ;
//    bool isEmpty() const;
//    T Root(T flag) const;
//    T lchild(T x, T flag) const;
//    T rchild(T x, T flag) const;
//    void delLeft(T x) ;
//    void delRight(T x);
//    void preOrder() const;
//    void midOrder() const;
//    void postOrder() const;
//    void levelOrder() const;
//    void createTree(T flag);
//    T parent(T x, T flag) const { return flag; }
//private:
//    Node *find(T x, Node *t ) const;
//    void clear(Node *&t) ;
//    void preOrder(Node *t)  const;
//    void midOrder(Node *t) const;
//    void postOrder(Node *t)  const;
//};
//
//template<class T>
//bool binaryTree<T>::isEmpty() const {
//    return root == NULL;
//}
//
//template <class T>
//T binaryTree<T>::Root(T flag) const {
//    if (root == NULL) return flag;
//    else return root->data;
//}
//
//template<class T>
//void binaryTree<T>::clear(binaryTree<T>::Node *&t) {
//    if (t == NULL)  return;
//    clear(t->left);
//    clear(t->right);
//    delete t;
//    t = NULL;
//}
//
//template<class T>
//void binaryTree<T>::clear() {
//    clear(root);
//}
//
//template <class T>
//binaryTree<T>::~binaryTree() {
//    clear(root);
//}
//
//template<class T>
//void binaryTree<T>::preOrder(binaryTree<T>::Node *t)  const {
//    if (t == NULL) return;
//    cout << t->data << ' ';
//    preOrder(t->left);
//    preOrder(t->right);
//}
//
//template<class T>
//void binaryTree<T>::preOrder() const {
//    cout << "\n前序遍历：";
//    preOrder(root);
//}
//
//template<class T>
//void binaryTree<T>::levelOrder() const
//{
//    queue< Node * > que;
//    Node *tmp;
//
//    cout << "\n层次遍历：";
//    que.enQueue(root);
//
//    while (!que.isEmpty()) {
//        tmp = que.deQueue();
//        cout << tmp->data << ' ';
//        if (tmp->left) que.enQueue(tmp->left);
//        if (tmp->right) que.enQueue(tmp->right);
//    }
//}
//
//template<class T>
//class binaryTree<T>::Node * binaryTree<T>::find(T x, binaryTree<T>::Node *t) const{
//    Node * tmp;
//    if(t==NULL) return NULL;
//    if(t->data == x) return t;
//    if(tmp = find(x, t->left)) return tmp;
//    else return find(x, t->right);
//}
//
//template <class T>
//void binaryTree<T>::delLeft(T x){
//    Node *tmp = find(x, root);
//    if (tmp == NULL) return;
//    clear(tmp->left);
//}
//
//template <class T>
//void binaryTree<T>::delRight(T x){
//    Node *tmp = find(x, root);
//    if (tmp == NULL) return;
//    clear(tmp->right);
//}
//
//template <class T>
//T binaryTree<T>::lchild(T x, T flag) const{
//    Node * tmp = find(x, root);
//    if (tmp == NULL || tmp->left == NULL) return flag;
//    return tmp->left->data;
//}
//
//template<class T>
//T binaryTree<T>::rchild(T x, T flag) const{
//    Node *tmp = find(x, root);
//    if (tmp == NULL || tmp->right == NULL) return flag;
//    return tmp->right->data;
//}
//
//template <class Type>
//void binaryTree<Type>::createTree(Type flag){
//    queue< Node * > que;
//    Node *tmp;
//    Type x, ldata, rdata;
//
//    //创建树，输入flag表示空
//    cout << "\n输入根结点：";
//    cin >> x;
//    root = new Node(x);
//    que.enQueue(root);
//
//    while (!que.isEmpty()) {
//        tmp = que.deQueue();
//        cout << "\n输入" << tmp->data
//                << "的两个儿子(" << flag
//                << "表示空结点)：";
//        cin >> ldata >> rdata;
//        if (ldata != flag)
//            que.enQueue(tmp->left = new Node(ldata));
//        if (rdata != flag)
//           que.enQueue(tmp->right = new Node(rdata));
//    }
//    cout << "create completed!\n";
//}
//
//template <class T>
//void printTree(const binaryTree<T> &t, T flag){
//    queue<T> q;
//    q.enQueue(t.root->data);
//    cout << endl;
//    while (!q.isEmpty()) {
//        char p, l, r;
//        p = q.deQueue();
//        l = t.lchild(p,flag);
//        r = t.rchild(p,flag);
//        cout << p << "  " << l  << "  " << r << endl;
//        if (l != '@') q.enQueue(l);
//        if (r != '@') q.enQueue(r);
//    }
//}
//
//
//
//int main(int argc, const char * argv[]) {
//    binaryTree<char> tree;
//
//    tree.createTree('@');
//    tree.preOrder();        tree.midOrder();
//    tree.postOrder();        tree.levelOrder();
//    printTree(tree, '@');
//    tree.delLeft('L');
//    tree.delRight('C');   tree.delLeft('C');
//    printTree(tree, '@');
//    return 0;
//
//}
