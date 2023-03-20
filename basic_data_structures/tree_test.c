#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
  Tree * t = createTree();
  //arvore slide 18
  treeInsert(t, createNode(15));
  treeInsert(t, createNode(6));
  treeInsert(t, createNode(18));
  treeInsert(t, createNode(3));
  treeInsert(t, createNode(7));
  treeInsert(t, createNode(17));
  treeInsert(t, createNode(20));
  treeInsert(t, createNode(2));
  treeInsert(t, createNode(4));
  treeInsert(t, createNode(13));
  treeInsert(t, createNode(9));
  
  printf("%s", "\n----------------walks------------\n");
  inOrderTreeWalk(t->root); printf("%s","\n");
  preOrderTreeWalk(t->root); printf("%s","\n");
  postOrderTreeWalk(t->root); printf("%s","\n");

  printf("%s", "\n----------------successor------------\n");
  printf("Successor 15 : %d \n", treeSuccessor(treeSearch(t->root,15))->key);
  printf("Successor 13 : %d \n", treeSuccessor(treeSearch(t->root,13))->key);
  printf("Successor 7 : %d \n", treeSuccessor(treeSearch(t->root,7))->key);
  printf("Successor 20? : %s \n", treeSuccessor(treeSearch(t->root,20))== NULL ? "NO": "YES");
  
  printf("%s", "\n----------------predecessor------------\n");
  printf("Predecessor 15 : %d \n", treePredecessor(treeSearch(t->root,15))->key);
  printf("Predecessor 13 : %d \n", treePredecessor(treeSearch(t->root,13))->key);
  printf("Predecessor 7 : %d \n", treePredecessor(treeSearch(t->root,7))->key);
  printf("Predecessor 2? : %s \n", treePredecessor(treeSearch(t->root,2))== NULL ? "NO": "YES");
  
  printf("%s", "\n----------------maximum e minumum------------\n");
  printf("Maximum : %d \n",  treeMaximum(t->root)->key);
  printf("Minimum : %d \n", treeMinimum(t->root)->key);
  
  printf("%s", "\n----------------delete------------\n");
  treeDelete(t,iterativeTreeSearch(t->root,6));
  inOrderTreeWalk(t->root); printf("%s","\n");
  treeDelete(t,iterativeTreeSearch(t->root,13));
  inOrderTreeWalk(t->root); printf("%s","\n");
  treeDelete(t,iterativeTreeSearch(t->root,20));
  inOrderTreeWalk(t->root); printf("%s","\n");
 
  printf("%s", "\n----------------end------------\n");
 
 

  
  
  system("PAUSE");	
  return 0;
}
