#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// STRUCTURE DEFINITION
// -----------------------------

typedef struct FunnelNode {
    char *stageName;              // Dynamic string for stage
    char *description;            // Dynamic string description
    struct FunnelNode *left;      // Left child
    struct FunnelNode *right;     // Right child
} FunnelNode;

// -----------------------------
// FUNCTION DECLARATIONS
// -----------------------------

FunnelNode* createNode(const char *stage, const char *desc);
FunnelNode* insertNode(FunnelNode *root, const char *stage, const char *desc);
FunnelNode* searchNode(FunnelNode *root, const char *stage);
void updateNode(FunnelNode *root, const char *stage);
FunnelNode* deleteNode(FunnelNode *root, const char *stage);
void displayTree(FunnelNode *root, int level);
int countNodes(FunnelNode *root);
void showLeafNodes(FunnelNode *root);
int treeDepth(FunnelNode *root);
void freeTree(FunnelNode *root);

// -----------------------------
// CREATE NODE
// -----------------------------
FunnelNode* createNode(const char *stage, const char *desc) {
    FunnelNode *newNode = (FunnelNode*)malloc(sizeof(FunnelNode));

    newNode->stageName = (char*)malloc(strlen(stage) + 1);
    strcpy(newNode->stageName, stage);

    newNode->description = (char*)malloc(strlen(desc) + 1);
    strcpy(newNode->description, desc);

    newNode->left = newNode->right = NULL;

    return newNode;
}

// -----------------------------
// INSERT NODE (BST BASED ON NAME)
// -----------------------------
FunnelNode* insertNode(FunnelNode *root, const char *stage, const char *desc) {
    if (root == NULL) {
        return createNode(stage, desc);
    }

    if (strcmp(stage, root->stageName) < 0)
        root->left = insertNode(root->left, stage, desc);
    else if (strcmp(stage, root->stageName) > 0)
        root->right = insertNode(root->right, stage, desc);

    return root;
}

// -----------------------------
// SEARCH NODE
// -----------------------------
FunnelNode* searchNode(FunnelNode *root, const char *stage) {
    if (root == NULL || strcmp(root->stageName, stage) == 0)
        return root;

    if (strcmp(stage, root->stageName) < 0)
        return searchNode(root->left, stage);
    else
        return searchNode(root->right, stage);
}

// -----------------------------
// UPDATE NODE
// -----------------------------
void updateNode(FunnelNode *root, const char *stage) {
    FunnelNode *node = searchNode(root, stage);

    if (node == NULL) {
        printf("Stage not found!\n");
        return;
    }

    char newDesc[200];
    printf("Enter new description: ");
    getchar(); // clear buffer
    fgets(newDesc, 200, stdin);

    newDesc[strcspn(newDesc, "\n")] = 0;

    free(node->description);
    node->description = (char*)malloc(strlen(newDesc) + 1);
    strcpy(node->description, newDesc);

    printf("Stage updated successfully!\n");
}

// -----------------------------
// FIND MIN NODE (HELPER)
// -----------------------------
FunnelNode* findMin(FunnelNode *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// -----------------------------
// DELETE NODE
// -----------------------------
FunnelNode* deleteNode(FunnelNode *root, const char *stage) {
    if (root == NULL) return NULL;

    if (strcmp(stage, root->stageName) < 0)
        root->left = deleteNode(root->left, stage);
    else if (strcmp(stage, root->stageName) > 0)
        root->right = deleteNode(root->right, stage);
    else {
        // Node found
        if (root->left == NULL) {
            FunnelNode *temp = root->right;
            free(root->stageName);
            free(root->description);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            FunnelNode *temp = root->left;
            free(root->stageName);
            free(root->description);
            free(root);
            return temp;
        }

        FunnelNode *temp = findMin(root->right);

        free(root->stageName);
        root->stageName = strdup(temp->stageName);

        free(root->description);
        root->description = strdup(temp->description);

        root->right = deleteNode(root->right, temp->stageName);
    }

    return root;
}

// -----------------------------
// DISPLAY TREE (HIERARCHY)
// -----------------------------
void displayTree(FunnelNode *root, int level) {
    if (root == NULL) return;

    displayTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");

    printf("%s: %s\n", root->stageName, root->description);

    displayTree(root->left, level + 1);
}

// -----------------------------
// COUNT NODES
// -----------------------------
int countNodes(FunnelNode *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// -----------------------------
// SHOW LEAF NODES
// -----------------------------
void showLeafNodes(FunnelNode *root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        printf("Leaf: %s\n", root->stageName);
    }

    showLeafNodes(root->left);
    showLeafNodes(root->right);
}

// -----------------------------
// TREE DEPTH
// -----------------------------
int treeDepth(FunnelNode *root) {
    if (root == NULL) return 0;

    int left = treeDepth(root->left);
    int right = treeDepth(root->right);

    return (left > right ? left : right) + 1;
}

// -----------------------------
// FREE MEMORY
// -----------------------------
void freeTree(FunnelNode *root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);

    free(root->stageName);
    free(root->description);
    free(root);
}

// -----------------------------
// MAIN FUNCTION (MENU)
// -----------------------------
int main() {
    FunnelNode *root = NULL;
    int choice;
    char stage[100], desc[200];

    while (1) {
        printf("\n==== DIGITAL MARKETING FUNNEL MENU ====\n");
        printf("1. Create Root Stage\n");
        printf("2. Add Funnel Stage\n");
        printf("3. Update Stage\n");
        printf("4. Delete Stage\n");
        printf("5. Search Stage\n");
        printf("6. Display Funnel Tree\n");
        printf("7. Count Stages\n");
        printf("8. Show Leaf Stages\n");
        printf("9. Funnel Depth\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter root stage name: ");
                scanf("%s", stage);
                printf("Enter description: ");
                scanf(" %[^\n]", desc);
                root = createNode(stage, desc);
                break;

            case 2:
                printf("Enter stage name: ");
                scanf("%s", stage);
                printf("Enter description: ");
                scanf(" %[^\n]", desc);
                root = insertNode(root, stage, desc);
                break;

            case 3:
                printf("Enter stage to update: ");
                scanf("%s", stage);
                updateNode(root, stage);
                break;

            case 4:
                printf("Enter stage to delete: ");
                scanf("%s", stage);
                root = deleteNode(root, stage);
                break;

            case 5: {
                printf("Enter stage to search: ");
                scanf("%s", stage);
                FunnelNode *found = searchNode(root, stage);
                if (found)
                    printf("Found: %s -> %s\n", found->stageName, found->description);
                else
                    printf("Not found!\n");
                break;
            }

            case 6:
                displayTree(root, 0);
                break;

            case 7:
                printf("Total stages: %d\n", countNodes(root));
                break;

            case 8:
                showLeafNodes(root);
                break;

            case 9:
                printf("Funnel depth: %d\n", treeDepth(root));
                break;

            case 10:
                freeTree(root);
                printf("Memory freed. Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}