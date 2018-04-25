 
#include <iostream>
using std::cout;
using std::endl;

enum RBTColor(RED,BLACK);
template <typename T>
class RBTNode{
	public:
		RBTColor color;//颜色
		T key;			//关键字
		RBTNode *left;  //左孩子
		RBTNode *right; //右孩子
		RBTNode *parent; //父节点
		RBTNode(T value,RBTColor c,RBTNode *p,RBTNode *l,RBTNode *r)
		:key(value)
		 ,color(c)
		 ,parent(p)
		 ,left(l)
		 ,right(r){};
}
template <typename T>
class RBTree{
	private:
		RBTNode<T> *mRoot;
	public:
		RBTree();
		~RBTree();

		//前序遍历“红黑树”
		void preOrder();
		//中序遍历
		void inOrder();
		//后序遍历
		void postOrder();

		//递归实现查找“红黑树”中键值为key的节点
		RBTNode<T> * search(T key);
		//非递归实现查找红黑树的键值key的节点
		RBTNode<T> * iterativeSearch(T key);

		//查找最小节点：返回最小节点的键值
		T minimum();
		//查找最大节点：返回最大节点的键值
		T maximum();
		//找节点x的后继节点，即，查找红黑树中数据值大于该节点的最小节点
		RBTNode<T> * successor(RBTNode<T> *x);
		//找节点x的前驱结点，即查找红黑树中数据值小于该节点的最大节点
		RBTNode<T> *ptrdecessor(RBTNode<T> *x);
		//将节点（key为节点的键值）插入到红黑树中
		void insert(T key);
		//删除节点（key 为节点的键值）
		void remove(T key);
		//销毁红黑树
		void destroy();

	private:
		//前序遍历红黑树
		void preOrder (RBTNode<T> * tree) const;
		//中序遍历红黑树
		void inOrder(RBTNode<T> * tree)const;
		//后序遍历红黑数
		void postOrder(RBTNode<T> *tree)const;
		

		//递归实现查找红黑树x中的键值为key的节点
		RBTNode<T> *search(RBTNode<T> *x,T key)const;
		//非递归实现查找红黑数x中的键值为key的节点
		RBTNode<T>* iterativeSearch(RBTNode<T>* x,T key)const;

		//查找最小节点：返回tree为根节点的红黑树的最小节点
		RBTNode <T> * minimum(RBTNode<T> *tree);
		//查找最大节点：返回tree为根节点的红黑树的最大节点
		RBTNode<T> *maximum(RBTNode<T> *tree);

		//左旋
		void leftRotate(RBTNode<T>* &root,RBTNode<T> *x);
		//右旋
		void rightRotate(RBTNode<T> *&root,RBTNode<T> *y);
		//插入函数
		void insert(RBTNode<T> *&root,RBTNode<T> *node);

		//插入修正函数
		void insertFixUp(RBTNode<T> *&root,RBTNode<T> *node);
		//删除函数
		void remove(RBTNode<T> *&root,RBTNode<T> *node);
		//删除修正函数
		void removeFixUp(RBTNode<T> *&root,RBTNode<T> *node,RBTNode<T> *parent);
		//销毁红黑树
		void destroy(RBTNode<T> * &tree);
		//打印红黑树
		void print(RBTNode<T> *tree,T key,int direction);

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color==RED)
#define rb_is_black(r) ((r)->color==BLACK)
#define rb_set_black(r) do{(r)->color=BLACK;}while(0)
#define rb_set_red(r) do{(r)->color=RED;}while(0)
#define rb_set_parent(r,p) do{ (r)->parent=(p);} while(0)
#define rb_set_color(r,c) do{(r)->color=(c);}while(0)

};

