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
int sumTree(std::vector<node> binaryTree, int currentIndex);

int main() {
    // Reading binary tree
    in = fopen("difsub.in", "r");
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

    // Call recursive sum function
    int sumLeftBranch = sumTree(biTree, biTree[rootIndex -1].left);
    int sumRightBranch = sumTree(biTree, biTree[rootIndex -1].right);

    // Writing absolute difference
    out = fopen("difsub.out", "w");
    int diff = std::max(sumLeftBranch, sumRightBranch) - std::min(sumLeftBranch, sumRightBranch);
    fprintf(out, "%d", diff);
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
// Recursive! Sum of tree values
int sumTree(std::vector<node> binaryTree, int currentIndex) {
    int sum{0};
    if(binaryTree[currentIndex -1].value) {
        sum += binaryTree[currentIndex -1].value;
        sum += sumTree(binaryTree, binaryTree[currentIndex -1].left);
        sum += sumTree(binaryTree, binaryTree[currentIndex -1].right);
    }
    return sum;
}