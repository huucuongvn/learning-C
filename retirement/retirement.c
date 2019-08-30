#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement (int startAge,
  double initial,
  retire_info working,
  retire_info retired) {
  double balance = initial;
  double x;
  for(int a = startAge; a < startAge + working.months + retired.months; a++) {
    int age = a/12;
    int month = a%12;
    printf("Age %3d month %2d you have $%.2lf\n", age, month, balance);
    if(a < startAge + working.months) {
      x = balance * (working.rate_of_return/12);
      balance += x + working.contribution;
    }
    else {
      x = balance * (retired.rate_of_return/12);
      balance += x + retired.contribution;
    }
  }
}

int main(void) {
  int startAge = 327;
  double initial = 21345;

  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;

  retirement(startAge, initial, working, retired);
  return 0;
}
