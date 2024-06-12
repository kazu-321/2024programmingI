#include <stdio.h>

float calculate_triangle_area(float base, float height) {
    float area = (base * height) / 2.0;
    return area;
}

int main(){
    float base, height;
    printf("底辺>>>");
    scanf("%f", &base);
    printf("高さ>>>");
    scanf("%f", &height);
    printf("面積は %.2f\n", calculate_triangle_area(base, height));
    return 0;
}