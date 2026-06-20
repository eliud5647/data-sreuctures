#ifndef SET_H_
#define SET_H_

#include <stdlib.h>
#include "datatypes.h"

typedef struct treenode_t {
	type_t *data;
	struct treenode_t *left;
	struct treenode_t *right;
} treenode_t;

typedef struct {
	treenode_t *tree;
	int size;
	comparator_t cf;
	printfunc_t pf;
} set_t;

int tree_height(treenode_t *t);
int tree_difheight(treenode_t *t);
treenode_t *tree_right_rotate(treenode_t *t);
treenode_t *tree_left_rotate(treenode_t *t);
treenode_t *tree_balance(treenode_t *t);
int tree_insert(treenode_t **t,type_t *d,comparator_t cf);
void tree_inorder(treenode_t *t,printfunc_t pf);
void tree_inorder_level(treenode_t *t,printfunc_t pf,int l);
void tree_preorder_level(treenode_t *t,printfunc_t pf,int l);
type_t *tree_successor(treenode_t *root);
type_t *tree_predecessor(treenode_t *root);
int tree_delete(treenode_t **root, type_t *d,comparator_t cf);

set_t *set_new(comparator_t cf,printfunc_t pf);
void set_add(set_t *s,type_t *d);
void set_print(set_t *s);
int set_size(set_t *s);
void set_remove(set_t *set,type_t *d);
treenode_t *remove_node(treenode_t **node, type_t *d, comparator_t cf, int *removed);
treenode_t *tree_min(treenode_t *node);


#endif /* SET_H_ */
