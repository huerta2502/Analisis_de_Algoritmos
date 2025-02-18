/**
 *  stores inorder traversal of given binary search tree
 *  into given array with given iterator.
 *  @param root binary search tree root node;
 *  @param arr array to store sorted elements
 *  @param i iterator
*/
void storeSorted(Node root, Entry *arr, int *i)
{
    if (root != NULL) 
    {
        storeSorted(root->left, arr, i);
        arr[(*i)++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/**
 *  Ordena el arreglo de tamaño n con el algoritmo de árbol
 *  utilizando un árbol binario de búsqueda.
 *  @param arr el arreglo a ordenar.
 *  @param n el tamaño del arreglo.
*/
void treeSort(int *arr, int n)
{
    Node root = insertNode(arr[0], NULL);
    int i = 0;
    for (i = 1; i < n; i++)
        root = insertNode(arr[i], root);
    i = 0;
    storeSorted(root, arr, &i);
}