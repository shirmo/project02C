#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define INPUT_LENGTH 4
#define WRONG_INPUT_LENGTH_MSG "Usage: TreeAnalayzer <Graph File Path> <First Vertex> <Second Vertex>\\n"
#define EXIT_FAILURE 1
#define INVALID_INPUT "Invalid input\\n"
#define VERTEX_1_PLACE 2
#define VERTEX_2_PLACE 3
#define END_OF_LINE "%[^\\n]"



int vertexValidityCheck(const char *ver);
int amountOfVerticesValidation(const char *ver);
int const *Vnum;  //Number of E = Vnum - 1

typedef struct
{
    int isLeaf;
    int isRoot;
    char children[1024];
    int amountOfChildren;
    int father;

    // If is root - amount of Children == v.degree else, amount of Children +1 == v.degree
    int degree;
} Vertices;



int main(int argc, char* argv[])
{
    if(argc !=INPUT_LENGTH)
    {
        fprintf(stderr, WRONG_INPUT_LENGTH_MSG);
        return EXIT_FAILURE;
    }

    char parse[1024];

    // OPEN THE FILE AND CHECK IF IT'S NOT EMPTY
    FILE *ptr;
    ptr = fopen(argv[1],"r");
    if (ptr == NULL)
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    //FIRST_LINE - NUM OF VERTEX (check if is digit)
    fscanf(ptr, END_OF_LINE, parse);
    //SET A CONST OF Vnum and Enum=(Vnu-1);
    if (amountOfVerticesValidation(parse))
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    else
    {
        int a = atoi(parse);
        Vnum = &a; // number of vertices.

    }
    //vertex validity check
    if(vertexValidityCheck(argv[VERTEX_1_PLACE]) || vertexValidityCheck(argv[VERTEX_2_PLACE]))
    {
        fprintf(stderr, INVALID_INPUT);
        return EXIT_FAILURE;
    }
    // while loop
    // create a vertex
    // pull it's children straight into v.children
    // check if they are valid
    // count how many there are and insert into v.amount_of_children
    //





    fclose(ptr);
    return 0;
}



int vertexValidityCheck(const char *ver)
{
    for (int i = 0; i < (int) strlen(ver); ++i)
    {
        if (!isdigit(ver[i]))
        {
            return 1;
        }
    }
    int vertex = atoi(ver);
    if (vertex >= Vnum || vertex <0)
    {
        return 1;
    }
    return 0;
}

int amountOfVerticesValidation(const char *ver)
{
    for (int i = 0; i < (int) strlen(ver); ++i)
    {
        if (!isdigit(ver[i]))
        {
            return 1;
        }
    }
    int vertex = atoi(ver);
    if (vertex <0)
    {
        return 1;
    }
    return 0;
}


void degreeCalc(Vertices *v)
{
    int length = *Vnum;
    for(int i=0; i < length; i++)
    {
        if(v[i].isLeaf)
        {
            v[i].degree = 1;
        }
        if(v[i].isRoot)
        {
            v[i].degree = v[i].amountOfChildren;
        }
        else
        {
            v[i].degree = v[i].amountOfChildren+1; // adding the father as another degree.
        }
    }
}

void isLeaf(Vertices *v)
{
    int length = *Vnum;
    for(int i=0; i < length; i++)
    {
        if(v[i].amountOfChildren == 0)
        {
            v[i].isLeaf = 1;
        }
        else
        {
            v[i].isLeaf = 0; // adding the father as another degree.
        }
    }
}

void childrenAmountCalc(Vertices *v)
{
    int length = *Vnum;
    for(int i=0; i < length; i++)
    {
        v[i].amountOfChildren = (int) strlen(v[i].children);
    }
}


