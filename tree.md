# Everything about tree

## Search data structure

searching algorithm | wst search | wst insert | avg search | avg insert
--------------------|------------|------------|------------|-----------
sequential search   |    N       |     N      |     N      |    N
binary search       |    logN    |     N      |     logN   |    N
BST                 |    N       |     N      |     logN   |    logN
B-Tree              |   logN     |    logN    |     logN   |    logN
RB-Tree             |   logN     |    logN    |     logN   |    logN
AVL-Tree            |   logN     |    logN    |     logN   |    logN
Splay-Tree          |   logN     |    logN    | logN(amort)|    logN(amort)
hash table          |   logN     |    logN    |     1      |    1

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

## random insert a tree

```
insertRandom(tree, item):

if tree is empty
   return new tree with item
end if

if random() % 3 < 10 then
   return insertAtRoot(tree, item)
else
   return insertAtLeaf(tree, item)
end if
```

## insert a splay tree

```
// total: O(nlogn)
insertSplay(tree, item):
   
   if tree is empty then 
      return newNode(item)
   else if item = data(tree) then
      return tree
   else if item < data(tree) then
      if left(tree) is empty then   // item is left child
         left(tree) = newNode(item)
         tree = rotateRight(tree)
      else if item < data(left(tree)) then // left of left
         left(left(tree)) = insertSplay(left(left(tree)), item)
         tree = rotateRight(tree)
         tree = rotateRight(tree)
      else if item > data(left(tree)) then // right of left
         right(left(tree)) = insertSplay(right(left(tree)), item)
         tree = rotateLeft(tree)
         tree = rotateRight(tree)
      else
         tree = rotateRight(tree)
      end if
   else if item > data(tree) then
      if left(tree) is empty then   // item is right child
         right(tree) = newNode(item)
         tree = rotateLeft(tree)
      else if item < data(right(tree)) then // left of right
         left(right(tree)) = insertSplay(left(right(tree)), item)
         tree = rotateRight(tree)
         tree = rotateLeft(tree)
      else if item > data(right(tree)) then // right of right
         right(right(tree)) = insertSplay(right(right(tree)), item)
         tree = rotateLeft(tree)
         tree = rotateLeft(tree)
      else
         tree = rotateLeft(tree)
      end if
   end if
   return tree
```

## AVR Tree

### AVR Tree insert

```
insertAVL(tree, item):

   if tree is empty then
      return newNode(item)
    else if item = data(tree) then
      return tree
    else
      // insert
      if item < data(tree) then
         left(tree) = insertAVL(left(tree), item)
      else if item > data(tree) then
         right(tree) = insertAVL(right(tree), item)
      end if
      // rotate
      if height(left(tree)) - height(right(tree)) > 1 then
        if item > date(left(tree)) then // on the right
            left(tree) = rotateLeft(left(tree))
        end if
        tree = rotateRight(tree)
      else if height(right(tree)) - height(left(tree)) > 1 then
        if item < data(right(tree)) then
            right(tree) = rotateRight(right(tree))
        end if
        tree = rotateLeft(tree)
      end if
    return tree
    end if
```