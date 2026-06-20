
#include <stdlib.h>
#include <stdio.h>
#include "set.h"

int tree_height(treenode_t *t)
{
	int retval = 0;
	int lheight,rheight;
	if(t!=NULL)
	{
		lheight = tree_height(t->left);
		rheight = tree_height(t->right);
		if(lheight>rheight)
			retval = lheight + 1;
		else
			retval = rheight + 1;
	}
	return retval;
}

int tree_difheight(treenode_t *t)
{
	int dif_height=0;
	if(t!=NULL)
		dif_height = tree_height(t->left) - tree_height(t->right);

	return dif_height;
}

treenode_t *tree_right_rotate(treenode_t *t)
{
	treenode_t *newroot = t->left;
	treenode_t *newright = t;
	newright->left = newroot->right;
	newroot->right = newright;
	return newroot;
}

treenode_t *tree_left_rotate(treenode_t *t)
{
	treenode_t *newroot = t->right;
	treenode_t *newleft = t;
	newleft->right = newroot->left;
	newroot->left = newleft;
	return newroot;
}

treenode_t *tree_balance(treenode_t *t)
{
	if(tree_difheight(t) > 1) // Es más profundo el lado izquierdo
		t = tree_right_rotate(t);
	else if(tree_difheight(t) < -1) // Es más profundo el lado derecho
		t = tree_left_rotate(t);

	return(t);
}

int tree_insert(treenode_t **t,type_t *d,comparator_t cf)
{
	int inserted=0;
	if(*t==NULL)
	{
		*t = malloc(sizeof(treenode_t));
		(*t)->data = d;
		(*t)->left = NULL;
		(*t)->right = NULL;
		inserted = 1;
	}
	else if(cf(d,(*t)->data) < 0)
		inserted=tree_insert(&((*t)->left),d,cf);
	else if(cf(d,(*t)->data) > 0)
		inserted=tree_insert(&((*t)->right),d,cf);

	if(inserted)
		*t = tree_balance(*t);

	return inserted;
}

void tree_inorder(treenode_t *t,printfunc_t pf)
{
	if(t!=NULL)
	{
		tree_inorder(t->left,pf);
		pf(t->data);
		tree_inorder(t->right,pf);
	}
}

void tree_inorder_level(treenode_t *t,printfunc_t pf,int l)
{
	int i;
	if(t!=NULL)
	{
		tree_inorder_level(t->left,pf,l+1);
		printf("\n");
		for(i=0;i<l;i++)
			printf("\t");
		pf(t->data);
		tree_inorder_level(t->right,pf,l+1);
	}
}

void tree_preorder_level(treenode_t *t,printfunc_t pf,int l)
{
	int i;
	if(t!=NULL)
	{
		for(i=0;i<l;i++)
			printf("\t");
		pf(t->data);
		printf("\n");
		tree_preorder_level(t->left,pf,l+1);
		tree_preorder_level(t->right,pf,l+1);
	}
}





set_t *set_new(comparator_t cf,printfunc_t pf)
{
	set_t *new = malloc(sizeof(set_t));
	new->tree = NULL;
	new->size = 0;
	new->cf = cf;
	new->pf = pf;
	return new;
}

void set_add(set_t *s,type_t *d)
{
	if(tree_insert(&(s->tree),d,s->cf))
		s->size++;
}

void set_print(set_t *s)
{
	printf("{");
	tree_inorder(s->tree,s->pf);
	printf("}\n");
}

int set_size(set_t *s)
{
	return s->size;
}

void set_remove(set_t *set, type_t *d)
{	/*Variable auxiliar para saber si hubo un retiro de dato o no*/
    int removed = 0;

    set->tree = remove_node(&(set->tree), d, set->cf, &removed);

    if(removed)
        set->size--;
}


/*Metodo auxiliar para usar recursión*/
treenode_t *remove_node(treenode_t **node, type_t *d, comparator_t cf, int *removed)
{
    treenode_t *temp;
    treenode_t *min;

	/*fin del arbol*/
    if(*node == NULL)
        return NULL;
	/*Valor mas grande*/
    if(cf(d, (*node)->data) < 0)
    {
        (*node)->left = remove_node(&((*node)->left), d, cf, removed);
    }
	/*Valor mas chico */
    else if(cf(d, (*node)->data) > 0)
    {
        (*node)->right = remove_node(&((*node)->right), d, cf, removed);
    }
	/*valor encontrado*/
    else
    {
        *removed = 1;
		/*Sin hijos*/
        if((*node)->left == NULL && (*node)->right == NULL)
        {
            free(*node);
            return NULL;
        }
		/*sin hijo izquiero*/
        else if((*node)->left == NULL)
        {
            temp = (*node)->right;
            free(*node);
            return temp;
        }
		/*sin hijo derecho*/
        else if((*node)->right == NULL)
        {
            temp = (*node)->left;
            free(*node);
            return temp;
        }
		/*con los dos hijos*/
        else
        {
            /*Se siguio la sugerencia de insertar el valor mas a la izquierda del subarbol derecho*/
			min = tree_min((*node)->right);
            (*node)->data = min->data;
            (*node)->right = remove_node(&((*node)->right), min->data, cf, removed);
			
        }
    }
	/*balanceo y return para los valores de nodos*/
    return *node;
}

/*Metodo que busca el valor mas chico del arbol o subarbol*/
treenode_t *tree_min(treenode_t *node)
{
    while(node->left != NULL)
        node = node->left;

    return node;
}