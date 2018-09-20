#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define char	TypeElem
#define END		'#'
/*定义二叉树*/
typedef _btree struct {
	TypeElem elem;
	struct _btree *lchild;
	struct _btree *rchild;
} Bnode;

/*相关规章
 *	先序遍历: 先根遍历
 *	中序遍历: 中根遍历
 *	后续遍历: 后根遍历
 * */

/*创建二叉树*/
class Btree{
			Bnode *root;
		/*购买节点*/
		static Bnode buy_node(){
			Bnode *ptr = (Bnode*)malloc(sizeof(Bnode)*1);
			if(ptr == NULL){
				exit(EXIT_FAILURE);
			}
			memset(ptr, '\0', sizeof(Bnode)*1);
			return ptr;
		}
	public:
		/*构造函数*/
		Btree(){
			root = buy_node();
			root->lchild = create_btree();
		}
		/*创建二叉树*/
		Bnode* create_btree(){
			Bnode *ptr = NULL;
			char elem;
			scanf("%c", &elem);
			if(elem != '#'){
				ptr = buy_node();
				ptr->elem = elem;
				ptr->lchild = create_btree();
				ptr->rchild = create_btree();
				return ptr;
			}
			return NULL;
		}
		/*先跟遍历 非递归*/
		void 


};
