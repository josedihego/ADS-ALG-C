#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Person{
    char * name;
    int age;
}Person;

void updatePerson(Person person){
    person.name = "Bob";
    person.age = 37;
}

void printPerson(Person person){
    printf("Name: %s, Age: %d\n", person.name, person.age);

}

int main(){

    Person p = {"Lia", 45};
    printPerson(p);
    updatePerson(p);
    printPerson(p);
    return EXIT_SUCCESS;
}