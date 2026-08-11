int find_maximum(int *arr, int size) {
    int max_val = arr[0]; 
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return max_val;
}

int time_to_eat_bananas(int *piles, int pilesSize, int speed, int h) {
    long long time = 0;

    for (int i = 0; i < pilesSize; i++) {
        time += (piles[i] + speed - 1) / speed;
    }

    return time;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = find_maximum(piles, pilesSize);
    int middle = 0;
    int min_speed = 1;

    while (low < high) {
        middle = (high + low) / 2;
        int time_to_eat = time_to_eat_bananas(piles, pilesSize, middle, h);

        if (time_to_eat > h) {
            low = middle + 1;
        } else {
            high = middle;
        }
    }

    return low;
}
