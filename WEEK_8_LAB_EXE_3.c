#include <stdio.h>

int main(){
    float height, weight, bmi;
    // Asking user to enter weight
    printf("Enter your weight in kilograms: ");
    //Checking for weight is int
    scanf("%f", &weight);
    // Asking user to enter height
    printf("Enter your height in metres: ");
    //Checking for height is float
    scanf("%f", &height);

    // Defining BMI formula
    bmi = weight /  (height * height);

    // Using if-else statements to check the BMI range and display the value
    if (bmi < 18.5) {
        printf("Your BMI is %.2f. You are underweight.\n", bmi);
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Your BMI is %.2f. You have a normal weight.\n", bmi);
    } else if (bmi >= 25.0 && bmi < 29.9) {
        printf("Your BMI is %.2f. You are overweight.\n", bmi);
    } else {
        printf("Your BMI is %.2f. You are obese.\n", bmi);
    }

    return 0;
}
