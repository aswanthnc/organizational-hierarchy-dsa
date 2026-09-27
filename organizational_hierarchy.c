#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
#define NAME_LEN 30

struct Node {
    char name[NAME_LEN];
    struct Node *firstChild;
    struct Node *nextSibling;
};

struct Node *createNode(const char *name) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newNode->name, name);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

void addChild(struct Node *parent, struct Node *child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        struct Node *temp = parent->firstChild;

        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }

        temp->nextSibling = child;
    }
}

void levelOrder(struct Node *root) {
    if (root == NULL)
        return;

    struct Node *queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("Level Order Traversal:\n");

    while (front < rear) {
        struct Node *current = queue[front++];

        printf("%s ", current->name);

        struct Node *child = current->firstChild;

        while (child != NULL) {
            queue[rear++] = child;
            child = child->nextSibling;
        }
    }

    printf("\n");
}

int height(struct Node *root) {
    if (root == NULL)
        return -1;

    int maxHeight = -1;
    struct Node *child = root->firstChild;

    while (child != NULL) {
        int childHeight = height(child);

        if (childHeight > maxHeight)
            maxHeight = childHeight;

        child = child->nextSibling;
    }

    return maxHeight + 1;
}

int linearSearch(char departments[][NAME_LEN], int n,
                 const char *key, int *comparisons) {
    *comparisons = 0;

    for (int i = 0; i < n; i++) {
        (*comparisons)++;

        if (strcmp(departments[i], key) == 0)
            return i;
    }

    return -1;
}

int binarySearch(char departments[][NAME_LEN], int n,
                 const char *key, int *comparisons) {
    int low = 0;
    int high = n - 1;

    *comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        (*comparisons)++;

        int result = strcmp(departments[mid], key);

        if (result == 0)
            return mid;
        else if (result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    struct Node *child = root->firstChild;

    while (child != NULL) {
        struct Node *next = child->nextSibling;
        freeTree(child);
        child = next;
    }

    free(root);
}

int main(void) {
    /* Construct the organizational hierarchy */
    struct Node *CEO = createNode("CEO");
    struct Node *HR = createNode("HR");
    struct Node *Finance = createNode("Finance");
    struct Node *IT = createNode("IT");
    struct Node *Development = createNode("Development");
    struct Node *Testing = createNode("Testing");
    struct Node *Frontend = createNode("Frontend");
    struct Node *Backend = createNode("Backend");

    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    addChild(IT, Development);
    addChild(IT, Testing);

    addChild(Development, Frontend);
    addChild(Development, Backend);

    printf("ORGANIZATIONAL HIERARCHY\n");
    printf("=========================\n\n");

    levelOrder(CEO);

    printf("\nTree Height = %d edges\n", height(CEO));
    printf("Number of Levels = %d\n", height(CEO) + 1);

    /* Unsorted data for linear search */
    char departments[7][NAME_LEN] = {
        "HR", "Finance", "IT", "Development",
        "Testing", "Frontend", "Backend"
    };

    /* Sorted data for binary search */
    char sortedDepartments[7][NAME_LEN] = {
        "Backend", "Development", "Finance", "Frontend",
        "HR", "IT", "Testing"
    };

    char searches[4][NAME_LEN] = {
        "HR", "Development", "Finance", "Backend"
    };

    int n = 7;

    printf("\nSEARCH COMPARISON\n");
    printf("=================\n");
    printf("%-15s %-15s %-15s\n",
           "Department", "Linear", "Binary");
    printf("---------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        int linearComparisons;
        int binaryComparisons;

        linearSearch(departments, n, searches[i], &linearComparisons);
        binarySearch(sortedDepartments, n, searches[i], &binaryComparisons);

        printf("%-15s %-15d %-15d\n",
               searches[i], linearComparisons, binaryComparisons);
    }

    freeTree(CEO);

    return 0;
}
