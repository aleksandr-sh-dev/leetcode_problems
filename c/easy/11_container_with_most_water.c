int get_min_num(int num1, int num2) {
    return (num1 > num2 ? num2 : num1);
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        int curr_len = right - left;
        int area = get_min_num(height[left], height[right]) * curr_len;
        if (area > max_area) {
            max_area = area;
        }

        height[left] > height[right] ? right-- : left++;
    }

    return max_area;
}
