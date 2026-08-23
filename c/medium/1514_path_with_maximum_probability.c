#include <stdbool.h>

double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start_node, int end_node) {
    double *max_probabilities = calloc(n, sizeof(double));

    max_probabilities[start_node] = 1.0f;

    bool new_max_probability = false;

    for (int i = 0; i < (n - 1); i++) {
        new_max_probability = false;

        for (int j = 0; j < edgesSize; j++) {
            int u = edges[j][0];
            int v = edges[j][1];

            double cur_prob = succProb[j];

            if ((max_probabilities[u] * cur_prob) > max_probabilities[v]) {
                max_probabilities[v] = max_probabilities[u] * cur_prob;
                new_max_probability = true;
            }

            if ((max_probabilities[v] * cur_prob) > max_probabilities[u]) {
                max_probabilities[u] = max_probabilities[v] * cur_prob;
                new_max_probability = true;
            }
        }

        if (new_max_probability == false) {
            break;
        }
    }

    double res = max_probabilities[end_node];
    free(max_probabilities);

    return res;
}
