#include <stdio.h>

int main() {
    int score = 0;
    char answer;

    printf("Welcome to the quiz game!\n");
    printf("You will be asked 5 questions. Good luck!\n\n");

   
    printf("Question 1: What is the capital of France?\n");
    printf("A) Berlin\n");
    printf("B) Paris\n");
    printf("C) London\n");
    printf("D) Rome\n");
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B) Paris.\n");
    }

    
    printf("\nQuestion 2: What is the largest planet in our solar system?\n");
    printf("A) Earth\n");
    printf("B) Saturn\n");
    printf("C) Jupiter\n");
    printf("D) Uranus\n");
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    if (answer == 'C' || answer == 'c') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is C) Jupiter.\n");
    }

    
    printf("\nQuestion 3: Who is the author of the book 'To Kill a Mockingbird'?\n");
    printf("A) F. Scott Fitzgerald\n");
    printf("B) Harper Lee\n");
    printf("C) Jane Austen\n");
    printf("D) J.K. Rowling\n");
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B) Harper Lee.\n");
    }

    printf("\nQuestion 4: What is the chemical symbol for gold?\n");
    printf("A) Ag\n");
    printf("B) Au\n");
    printf("C) Hg\n");
    printf("D) Pb\n");
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    if (answer == 'B' || answer == 'b') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is B) Au.\n");
    }

    
    printf("\nQuestion 5: Which of the following is not a primary color?\n");
    printf("A) Red\n");
    printf("B) Blue\n");
    printf("C) Yellow\n");
    printf("D) Green\n");
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    if (answer == 'D' || answer == 'd') {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is D) Green.\n");
    }

    printf("\nYour final score is %d out of 5.\n", score);

    return 0;
}