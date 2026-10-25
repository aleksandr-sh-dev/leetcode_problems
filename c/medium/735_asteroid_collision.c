/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int res_idx = 0;
    int *res = malloc(sizeof(int) * asteroidsSize);
    bool alive = true;

    for (int i = 0; i < asteroidsSize; i++) {
        alive = true;
        if (i > 0 && asteroids[i] < 0) {
            if (res_idx > 0 && res[res_idx - 1] < 0) {
                res[res_idx++] = asteroids[i];
                continue;
            }

            while (res_idx > 0 && res[res_idx - 1] > 0) {
                if (asteroids[i] + res[res_idx - 1] == 0) {
                    // both collide
                    res_idx--;
                    alive = false;
                    break;
                } else if (asteroids[i] + res[res_idx - 1] < 0) {
                    res_idx--;
                    continue;
                } else if (asteroids[i] + res[res_idx - 1] > 0) {
                    alive = false;
                    break;
                }
            }

            if (alive) {
                res[res_idx++] = asteroids[i];
            }
        } else {
            res[res_idx++] = asteroids[i];
        }
    }

    *returnSize = res_idx;

    return res;
}