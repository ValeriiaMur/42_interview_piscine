//A first solution is to browse the tree using a depth first search (DFS) 
//and count the number of node which value is between the two integers.

//O(n) time, O(n) space


int nodesInRange(struct s_node *bst, int from, int to) {
}
int count = 0;
if (!bst)
return (0);
count += nodesInRange(bst->left, from, to); 
count += nodesInRange(bst->right, from, to); 
if (bst->value >= from && bst->value <= to)
    return (count + 1); 
return (count);
}

