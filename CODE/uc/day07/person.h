#ifndef _PERSON_H_
#define _PERSON_H_
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

typedef struct{
    int id; 
    char name[20];
    double salary;
}person;

#endif //
