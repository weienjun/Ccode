//#include<stdio.h>
typedef struct job
{
	int id;
	char name[20];
	char desc[20];
}JobNode, *Job;
typedef struct hero
{
	int id;
	char name[20];
	char cex;
	Job job;
}HeroNode, *Hero;
