#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int StartAge, double initial, retire_info working, retire_info retired)
{
  int i,j;
  for(i=StartAge; i<(StartAge+working.months);i++){
    printf("Age %3d month %2d you have $%.2f \n",i/12,i%12,initial);
    initial = initial+working.contribution+initial*working.rate_of_return;
  }
  for(j=i; j<(StartAge+working.months+retired.months);j++){
    printf("Age %3d month %2d you have $%.2f \n",j/12,j%12,initial);
    initial = initial+retired.contribution+initial*retired.rate_of_return;
  }
}

int main(void)
{
  int age= 327;
  double savings= 21345;
  retire_info working;
  retire_info retired;

  working.months= 489;
  working.contribution= 1000;
  working.rate_of_return= 0.045/12;

  retired.months= 384;
  retired.contribution= -4000;
  retired.rate_of_return= 0.01/12;

  retirement(age,savings,working,retired);

  return EXIT_SUCCESS;
}
