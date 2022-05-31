#include <stdio.h>
#include <stdlib.h>

struct treeNode{
  int data;
  treeNode* left;
  treeNode* right;
  treeNode* parent;
};


treeNode* insert(treeNode* r, int data) {
  if (r == NULL) {
    treeNode* r = (treeNode*)malloc(sizeof (treeNode));
    r-> data = data;
    r->left = r->right = r->parent = NULL;
  } else {
    if (data < r-> data) {
      r->left = insert (r->left, data);
      r->left->parent = r;
    }else {
      
    }
  }
}


int main (){


  return 0;
}