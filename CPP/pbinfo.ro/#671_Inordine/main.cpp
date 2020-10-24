#include <stdio.h>
#include <vector>

struct node {
    int index, value, left, right;
};

FILE *in, *out;
int n;
std::vector<node> biTree;

//* Pre-declaring functions
int findRoot(std::vector<node> binaryTree);
void printTreeInorder(std::vector<node> binaryTree, int currentIndex);

int main() {

    // Reading binary tree
    in = fopen("inordine.in", "r");
    fscanf(in, "%d", &n);
    for(int i = 1; i <= n; ++i) {
        node tmp;
        tmp.index = i;
        fscanf(in, "%d%d%d", &tmp.value, &tmp.left, &tmp.right);
        biTree.push_back(tmp);
    }
    fclose(in);

    // Calling function for finding the root's index
    const int rootIndex = findRoot(biTree);

    // Calling recursive function
    out = fopen("inordine.out", "w");
    printTreeInorder(biTree, rootIndex);
    fclose(out);

    return 0;
}

//* Functions
// Find root of a binary tree
int findRoot(std::vector<node> binaryTree) {
    bool isNotRoot[1005];

    // Invalidate left and right nodes of every node
    for(std::vector<node>::iterator it = binaryTree.begin(); it != binaryTree.end(); ++it) {
        isNotRoot[it->left] = true;
        isNotRoot[it->right] = true;
    }

    // Find unmarked nodes
    for(int i = 1; i <= n; ++i)
        if(!isNotRoot[i])
            return i;
    return -1;
}
// Recursive! Print binary tree from leftmost leaf
void printTreeInorder(std::vector<node> binaryTree, int currentIndex) {
    if(binaryTree[currentIndex -1].value) {
        printTreeInorder(binaryTree, binaryTree[currentIndex -1].left);
        fprintf(out, "%d ", binaryTree[currentIndex -1].value);
        printTreeInorder(binaryTree, binaryTree[currentIndex -1].right);
    }
}