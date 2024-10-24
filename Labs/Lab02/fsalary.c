/**
 * CSCI 306
 * lab 02 - fsalary.c
 * compile with: make salary
 * notes: none
 */
#include <stdio.h>

int main(void) 
{
   float hourly_wage;
   int num_weeks;
   float annual_salary;
 
   printf("Enter hourly wage (float): ");
   scanf("%f", &hourly_wage);
   while (getchar() != '\n');

   printf("Enter number of weeks (integer): ");
   scanf("%d", &num_weeks);

   annual_salary = hourly_wage * 40 * num_weeks;

   printf("Annual salary is: ");
   printf("$%.2f", annual_salary);
   printf("\n");

   return 0;
}
