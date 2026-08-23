struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

#include <stdlib.h>

void depth_first_search(struct Node ***visited, struct Node **new, struct Node *s) {
    if ((*visited)[s->val] != NULL) {
        (*new) = (*visited)[s->val];
        return;
    }

    (*new) = malloc(sizeof(struct Node));
    (*new)->neighbors = malloc(sizeof(struct Node *) * s->numNeighbors);
    (*new)->val = s->val;
    (*new)->numNeighbors = s->numNeighbors;

    (*visited)[s->val] = (*new);

    for (int i = 0; i < s->numNeighbors; i++) {
        depth_first_search(visited, &(*new)->neighbors[i], s->neighbors[i]);
    }
}

struct Node *cloneGraph(struct Node *s) {
    if (s == NULL) {
        return NULL;
    }

	struct Node *new = NULL;
    struct Node **visited = calloc(101, sizeof(struct Node *));

    depth_first_search(&visited, &new, s);

    return new;
}
