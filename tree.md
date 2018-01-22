# Everything about tree

## Kinds of tree

- m-ary tree
- ordered tree
- balanced tree
- degenerate tree

## Binary Search Tree

- binary tree
- orderd tree

## properties of BST

- Level of node: path length from root to node
- height of tree: max length from root to leaf

## Representation of BST

```
// a Tree is represented by a pointer to its root node
typedef struct Node *Tree;

// a Node contains its data, plus left and right subtrees
typedef struct Node {
   int  data;
   Tree left;       // which means Node *left
   Tree right;
} Node;

// some macros that we will use frequently
#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

```

## Search

```
TreeSearch(tree, item):
    Input: tree, item
    Output: true if found, false otherwise
    
    if tree is empty then
        return false
    end if
    if item = data(tree) then
        return true
    end if
    if item < data(tree) then
        return TreeSearch(left(tree), item)
    end if
    if item > data(tree) then
        return TreeSearch(left(tree), item)
    end if
```

## Insert

```
TreeInsert(tree, item):
    Input: tree, item
    Output: void
    
    if tree is empty then
        insert item here
        return
    end if
    if item = data(tree) then
        return         // avoid duplicate
    end if
    if item < data(tree) then
        return TreeInsert(left(tree), item)
    end if
    if item > data(tree) then
        return TreeInsert(left(tree), item)
    end if
```

## Traversal

- preorder(NLR): root->left->right(building tree)
- inorder(LNR): left->root->right(natural order)
- postorder(LRN): left->right->root(evaluation)
- level- order(print)

```
ShowNLR(tree):

push tree onto stack
while stack is not empty do 
    tree = pop(stack)
    print data(t)
    if right(tree) is not empty then
        push(right(tree))
    end if
    if left(tree) is not empty then
        push(left(tree))
    end if
end while
```

## Join two trees

preconditon: max(t1) < min(t2)

- find the min node in t2
- replace min node by its right subtree
- using this node as root


```
JoinTree(t1, t2):

    if t1 is empty then return t2
    end if
    if t2 is empty then return t1
    end if
    min = t2
    parent = NULL
    while left(min) is not empty do     // find min in t2 and its parent
        parent = min
        min = left(min)
    end while
    if parent is NULL   // no left subtree of t2
        left(min) = t1
    else
        left(parent) = right(min)
        right(min) = t2
        left(min) = t1
    end if
    return(min)
```

## delete

- empty tree
- no subtree
- one subtree
- two subtree (join two subtree)

```
TreeDelete(tree, item):
    if tree is empty then
        return tree
    end if 
    if item = data(tree) then 
        new = tree
        if left(tree) and right(tree) are empty then
             new = empty tree
        else if left(tree) is empty then
             new = right(tree)
        else if right(tree) is empty then
             new = left(tree)        
        else
             new=JoinTree(left(tree), right(tree))
        end if    
        free(tree)
        return new
    end if
    if item < data(tree) then 
        left(tree) = TreeDelete(left(tree), item)
    end if
    if item > data(tree) then 
        right(tree) = TreeDelete(right(tree), item)
    end if
    
```

## Balanced BST

- minimum height = log2N
- diff(Number of node in left subtree - Number of node in right subtree) <= 1

### tree rotation

```
RotateRight(tree)
    if tree is empty or left(tree) is empty     // can not right rotate a tree without left subtree
        return tree
    end if
    newRoot = left(tree)
    right(newRoot) = tree
    left(tree) = right(newRoot)
    return newRoot
```

### Rebalance tree

```
BalanceTreeInsert(tree , item):

    tree = TreeInsert(tree, item)
    if #node(tree) mod k = 0 then
        tree = rebalance(tree)
    end if
    return tree


rebalance(tree):

    if nodes(tree) >= 3 then
        tree = partition(tree, [n/2])
        left(tree) = rebalance(left(tree))
        right(tree) = rebalance(right(tree))
    end if 
    return tree


partition(tree, i):

    middle = nodes(left(tree))
    if i < middle then
        left(tree) = partition(tree, i)
        tree = rotationRight(tree)
    else if i > middle then
        right(tree) = partition(tree, i - (m + 1))
        tree = rotationLeft(tree)
    end if
    return tree

```