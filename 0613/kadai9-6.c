#include <stdio.h>

double calculateSalary(int age) {
    double initialSalary = 200000.0;
    double annualIncrease = 0.035;
    double salary = initialSalary;
    for (int i = 22; i < age; i++) salary += salary * annualIncrease;
    return salary;
}

int main() {
    int age = 22;
    double monthlySalary;
    while (1) {
        monthlySalary = calculateSalary(age);
        printf("%d歳: %f万円\n", age, monthlySalary/10000.0);
        if (monthlySalary > 500000.0) break;
        age++;
    }
    printf("%d歳で月収が50万円を超えます\n", age);
    return 0;
}