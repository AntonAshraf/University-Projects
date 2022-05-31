#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 255

struct treeNode{
  int freq;
  char letter;
  treeNode* left;
  treeNode* right;
  treeNode* parent;
  treeNode* next;
};



// priority queue
treeNode* pqPush(treeNode* node, treeNode* h, int freq,char c) {
  // if tree Node pushed
  if (node != NULL){
    if (h == NULL){
      h = node;
      node -> next = NULL;
    }
    else if (node->freq < h->freq){
      node -> next = h;
      h = node;
    }else if (h->next != node){
      treeNode* it = h;
      while (it ->next != NULL && it->next->freq < node -> freq)
        it = it -> next;
      node -> next = it-> next;
      it -> next = node;
    }
  }
  // If create new node to be pushed
  else{
    // Initial
    if(h == NULL) {
      h = (treeNode*)malloc (sizeof(treeNode));
      h -> freq = freq;
      h -> letter = c;
      h -> next = NULL;
      h -> right = NULL;
      h -> left = NULL;
    } // Insert First
    else if (freq < h->freq){
      treeNode* tmp = (treeNode*)malloc (sizeof(treeNode));
      tmp -> freq = freq;
      tmp -> letter = c;
      tmp -> next = h;
      tmp -> right = NULL;
      tmp -> left = NULL;
      h = tmp;
    } else { // In the Middle
      treeNode* it = h;
      while (it ->next != NULL && it->next->freq < freq)
        it = it -> next;

      treeNode* tmp = (treeNode*)malloc (sizeof(treeNode));
      tmp -> freq = freq;
      tmp -> next = it -> next;
      it -> next = tmp;
      tmp -> letter = c;
      tmp -> left = NULL;
      tmp -> right = NULL;
    }
  }
  return h;
}

bool pqPop(treeNode** h, treeNode** node){
  if ((*h) == NULL){
    node = NULL;
    return false;
  }

  (*node) = (*h);
  (*h) = (*h)->next;
  return true;
}

treeNode* load_tree(treeNode* r){
  treeNode* node1, *node2, *parent;
  node1 = node2 = parent = NULL;

  while ((pqPop(&r,&node1)) && pqPop(&r, &node2)){
    treeNode* tmp = (treeNode*)malloc(sizeof(treeNode));
    tmp -> freq = node1->freq + node2 ->freq;
    tmp -> letter = '\0';
    tmp -> left = node2;
    tmp -> right = node1;
    parent = tmp;
    r = pqPush(parent, r, 0, '\0');
  }
  return parent;
}

bool leaf (treeNode* node){
  if (node -> left && node -> right)
    return false;
  
  return true;
}


char *string_cat(char *s1, const char *s2){
	
  int s3_len = strlen(s1)+strlen(s2)+1;

	char *ret = (char *)malloc(sizeof(char)*s3_len);
	ret[0] = '\0';
	int i;

	for(i=0; i<strlen(s1); i++)
		ret[i] = s1[i];
	
	for(int j=0;j<strlen(s2); j++, ++i)
		ret[i] = s2[j];
	
  ret[i] = '\0';

	return ret;
}


void generate_codes(treeNode *node, char code[], char *table[]){
	
  if(node == NULL)
		return; 

	if(leaf(node))
		table[(int)node->letter] = code;

	generate_codes(node->left, string_cat(code, "0"), table);
	generate_codes(node->right, string_cat(code, "1"), table);
}

void print_table(char *code_table){
  
  for (int i = 0; i < 255; i++)
    if (code_table[i] != NULL) 
      printf("%c - %s\n",i,code_table[i]);

}
// get 1K char and save its 
int main (){
  /* 
a	10
e	15
i	12
o	3
u	4
s	13
t	1
   */
  char freq[TABLESIZE] = {};
  char str[60] = "aaaaabbbbc";
  
  // Count charcters
  for (int i = 0; str[i] != '\0' ; i++)
    for(int j = 0; j < TABLESIZE;j++)
      if((char)j == str[i])
        freq[j]++;

  // Initilize Priority Queue
  treeNode* pq = NULL;

  // Push in priority queue all occurred Charcters with its frequency  
  for(int i = 0; i < TABLESIZE; i++)
    if (freq[i] != 0){
      pq = pqPush(NULL, pq, freq[i], (char)i);
    }

  treeNode* Huff_root = load_tree(pq);

  // Generate Codes in Hash Table
  char* hash_table[255];

  for (int i = 0; i < 255; i++)
    hash_table[i] = NULL;
  
  char tmp[50] = "";
  
  generate_codes(Huff_root,tmp, hash_table);

  // print hash table
  // print_table(hash_table);
  
  


  // for (int i = 0; i < strlen(str); i++)
  // {
  //   printf("%s ",hash_table[(int)str[i]]);
  // }
  


  // for (int i = 0; i < 255; i++)
  //   table[i] = 0;


// Get_codes (Huff_root, table);
  // for (int i = 0; i < 255; i++)
  // {
  //   if (table[i] != 0){
  //     printf("%c %d",i,table[i]);
  //   }
  // }

  return 0;
}