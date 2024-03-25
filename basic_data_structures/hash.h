#include "linked_list.h"

typedef struct Hash{
   struct List * T;      
}Hash;

int h(int k);

void insertHash( Hash * h, int k);
void removeHash ( Hash * h, Node * n);
Node * searchHash( Hash * h, int k);

void printHash( Hash * h);

void initHash( Hash * h);
