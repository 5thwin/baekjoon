#include<cstdio>
#define PI 3.14159265358979323846
using namespace std;


double circle(int R){
	return R * R * PI;
}
double taxi(int R)
{
	return R * R * 2;
}
int main() {
	int R;
	scanf("%d", &R);
	printf("%f\n%f", circle(R), taxi(R));
}