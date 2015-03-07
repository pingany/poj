//============================================================================
// Name        : hello.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include<math.h>

static  double PI=3.1415926;
double  gr(double S)
{
	return  sqrt(S/PI/4);
}
double  gV(double r, double h)
{
	return  PI*r*r*h/3;
}
double  gh(double S, double R)
{
	return  sqrt( S*S/(PI*PI)/(R*R) -2*S/PI );
}
int main(void) {

	double S;
	double r,h,V;
	while(EOF!=scanf("%lf",&S))
	{
		r=gr(S);
		h=gh(S,r);
		V=gV(r,h);
		printf("%.2f\n%.2f\n%.2f\n",V,h,r);
	}
	return 0;
}
