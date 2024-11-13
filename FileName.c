#define _CRT_SECURE_NO_WARNINGS     
#include <stdio.h>     
#include <locale.h>     
#define _USE_MATH_DEFINES     
#include <math.h>
#define N 100

double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = (double)(rand() % 1000) / 10;
    }
    return ptr_array;
}
int put_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] = ptr_array[i] * ptr_array[i];
    }
    return ptr_array;
}
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0.0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;

    printf("¬ведите размер массива (max %d) > ", N);
    scanf("%d", &size);

    if (size <= 0 || size > N) {
        printf("Ќеправильный размер массива!\n");
        return 1; 
    }

    full_elements(array, size); 
    printf("—генерированные элементы массива:\n");
    put_elements(array, size); 

    calc_elements(array, size); 
    printf("ќбработанные элементы массива (возведенные в квадрат):\n");
    put_elements(array, size); 

    double sum = sum_elements(array, 2, 5);
    printf("—умма элементов от индекса 2 до 5: %f\n", sum);

    double element_to_find;
    printf("¬ведите элемент дл€ поиска: ");
    scanf("%lf", &element_to_find);
    int index = find_element(array, size, element_to_find);
    if (index != -1) {
        printf("Ёлемент %f найден на индексе %d.\n", element_to_find, index);
    }
    else {
        printf("Ёлемент %f не найден.\n", element_to_find);
    }

    return 0; 
}
