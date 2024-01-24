#pragma once
#include <stdio.h>
#include <math.h>

double factorial(int quantity) {
	double factorial = 1;
	for (int i = 1; i <= quantity; i += 1) {
		factorial *= i;
	}
	return factorial;
}


double delta(double a, double b) {
	if (a - b >= 0) {
		return a - b;
	}
	else {
		return -(a - b);
	}
}

double sinus(double x, int quantity) {
	double result = 0.0;
	for (int i = 0; i <= quantity; i++) {
		result += pow(-1, i) * pow(x, 2*i+1) / factorial(2*i+1);
	}
	return result;
}

double sinus_sum(double x, int quantity) {
	double sum = 0.0;
	double temp = x;
	for (int i = 1; i < quantity; i += 1) {
		sum += temp;
		temp *= (-1) * (pow(x, 2) / (2 * i * (2 * i + 1)));
	}
	return sum;
}

double cosinus(double x, int quantity) {
	double result = 0.0;
	for (int i = 0; i < quantity; i += 1) {
		result += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
	}
	return result;
}

double cosinus_sum(double x, int quantity) {
	double sum = 0.0;
	double temp = 1.0;
	for (int i = 1; i < quantity; i += 1) {
		sum += temp;
		temp *= (-1) * (pow(x, 2) / (2 * i *(2 * i - 1)));
	}
	return sum;
}

double exponent(double x, int quantity) {
	double result = 0.0;
	for (int i = 0; i <= quantity; i++) {
		result += pow(x, i) / factorial(i);
	}
	return result;
}

double exponent_sum(double x, int quantity) {
	double sum = 0.0;
	double temp = 1.0;
	for (int i = 1; i < quantity; i += 1) {
		sum += temp;
		temp *= x / i;
	}
	return sum;
}

void cap() {
	printf("┌──────┬────────────┬────────────┬────────────┐\n");
	printf("│  xᵢ  │   F(xᵢ)=   │   F(xᵢ)≈   │    Δ(xᵢ)   │\n");
	printf("├──────┼────────────┼────────────┼────────────┤\n");
}

void filling(double a, double b, double c, double d) {
	printf("│ %.1lf  │ %.6lf   │ %.6lf   │ %.7lf  │\n", a, b, c, d); 
	printf("├──────┼────────────┼────────────┼────────────┤\n"); 
}

void boots(double a, double b, double c, double d) {
	printf("│ %.1lf  │ %.6lf   │ %.6lf   │ %.7lf  │\n", a, b, c, d); 
	printf("└──────┴────────────┴────────────┴────────────┘\n"); 
}

void print_sinus(int quantity, double top, double step, double x) {
	printf("                    ☾sinus☽\n");
    cap();
    for (x = 0; x <= top - step; x += step) {
        filling(x, sinus(x, quantity), sinus_sum(x, quantity), delta(sinus(x, quantity), sinus_sum(x, quantity)));
    }
    boots(x, sinus(x, quantity), sinus_sum(x, quantity), delta(sinus(x, quantity), sinus_sum(x, quantity)));
	printf("\n");
}

void print_cosinus(int quantity, double top, double step, double x) {
	printf("                   ☾cosinus☽\n");
    cap();
    for (x = 0; x <= top - step; x += step) {
        filling(x, cosinus(x, quantity), cosinus_sum(x, quantity), delta(cosinus(x, quantity), cosinus_sum(x, quantity)));
    }
    boots(x, cosinus(x, quantity), cosinus_sum(x, quantity), delta(cosinus(x, quantity), cosinus_sum(x, quantity)));
	printf("\n");
}

void print_exponent(int quantity, double top, double step, double x) {
	printf("                  ☾exponent☽\n");
    cap();
    for (x = 0; x <= top - step; x += step) {
        filling(x, exponent(x, quantity), exponent_sum(x, quantity), delta(exponent(x, quantity), exponent_sum(x, quantity)));
    }
    boots(x, exponent(x, quantity), exponent_sum(x, quantity), delta(exponent(x, quantity), exponent_sum(x, quantity)));
	printf("\n");
}

void HUD(int quantity, double step, int choice) {
    double top = quantity * step;
    double x = top;

	switch (choice) {
		case 1:
			print_sinus(quantity, top, step, x);
			break;
		case 2:
			print_cosinus(quantity, top, step, x);
			break;
		case 3:
			print_exponent(quantity, top, step, x);
			break;
		case 4:
			print_sinus(quantity, top, step, x);
			print_cosinus(quantity, top, step, x);
			print_exponent(quantity, top, step, x);
			break;
		default:
			break;
	}
}