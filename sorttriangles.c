#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n); 

int cmptriangleareas(const void *pt1, const void *pt2)
{
    triangle *t1 = (triangle*) pt1;
    triangle *t2 = (triangle*) pt2;
    
    double p1 = (t1->a+t1->b+t1->c)/2.0;
    double p2 = (t2->a+t2->b+t2->c)/2.0;
    double area1 = sqrt((p1*(p1 - t1->a)*(p1 - t1->b)*(p1 - t1->c)));
    double area2 = sqrt((p2*(p2 - t2->a)*(p2 - t2->b)*(p2 - t2->c)));
    
    if(area1 > area2)
        return 1;
    if(area1 < area2)
        return -1;
    return 0;
}

int main()
{
	int i,n;
	triangle *tr = malloc(n * sizeof(triangle));
    FILE *fp = fopen("testcase.txt","r");
    if(fp == NULL)
    {
        
        return 1;
    }

    fscanf(fp,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d%d%d",&tr[i].a,&tr[i].b,&tr[i].c);
    }

	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    qsort(tr,n,sizeof(triangle),cmptriangleareas);
}
