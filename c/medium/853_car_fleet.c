typedef struct {
    int pos;
    int speed;
} Car;

int compareCar(const void *a, const void *b) {
    Car *carA = (Car*)a;
    Car *carB = (Car*)b;
    return carB->pos - carA->pos;
}

double get_time_to_finish(int pos, int speed, int target) {
    return (double)(target - pos) / speed;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if ((target == 0) || (positionSize == 1)) {
        return 1;
    }
    
    Car *cars = malloc(sizeof(Car) * positionSize);

    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }
    
    qsort(cars, positionSize, sizeof(Car), compareCar);

    int fleets_num = 0;
    double max_time_to_finish = -1.0f;

    for (int i = 0; i < positionSize; i++) {
        double cur_time_to_finish = get_time_to_finish(cars[i].pos, cars[i].speed, target);
        if (cur_time_to_finish > max_time_to_finish) {
            fleets_num++;
            max_time_to_finish = cur_time_to_finish;
        }
    }

    free(cars);
    return fleets_num;
}
