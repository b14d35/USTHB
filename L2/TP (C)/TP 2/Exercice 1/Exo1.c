#include <math.h>
#include <stdio.h>
typedef struct {
	float x, y;
} point;
typedef struct {
	point a, b;
} segment;
typedef struct {
	char nom[30];
	int pop;
	point pos;
} ville;
float lon(segment z) {
	return sqrt(pow(z.a.x - z.b.x, 2) + pow(z.a.y - z.b.y, 2));
}
point rpos(ville v) { return v.pos; }
float distr(ville v1, ville v2) {
	segment z;
	z.a = rpos(v1);
	z.b = rpos(v2);
	return lon(z) * 1000000;
}
