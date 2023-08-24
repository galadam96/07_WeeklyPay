/*Date: 2023.06.04
Purpose: Program that Calculates the weekly pay*/

#include <stdio.h>
#define PAYRATE 12.00
#define OVERTIME_CAP 40
#define OVERTIME_BONUS 1.5
#define TAXRATE_300 .85
#define TAXRATE_150 .80
#define TAXRATE_REST .75

int main() {
	
	int hours;
	int overtime = 0;
	double wage_gross;
	double wage_net;
	double wage_rest = 0;
	

	printf("Enter the number of hours worked in week: ");
	scanf_s("%i", &hours);

	//overtime

	if (hours > OVERTIME_CAP) {
		overtime = hours - OVERTIME_CAP;
		wage_gross = (OVERTIME_CAP * PAYRATE) + (overtime * PAYRATE * OVERTIME_BONUS);
	}
	else {
		wage_gross = hours * PAYRATE;
	}

	printf("Gross Wage is %.2f $. Overtime: %i hours. \n", wage_gross, overtime);

	// tax
	//15% tax for fist 300$

	if (wage_gross <= 300) {

		wage_net = wage_gross * TAXRATE_300;
	}

	else if (wage_gross > 300 && wage_gross <= 450){ //20% for the next 150$
			
		wage_rest = wage_gross - 300; 
		wage_net = (300 * TAXRATE_300) + (wage_rest * TAXRATE_150);
	}

	else if (wage_gross > 450) { // 25% for the rest

		wage_rest = wage_gross - 300; 
		wage_rest = wage_rest - 150;
		wage_net = (300 * TAXRATE_300) + (150 * TAXRATE_150) + (wage_rest * TAXRATE_REST);
	}

	printf("Net Wage is %.2f $. \n", wage_net);
	return 0;

}