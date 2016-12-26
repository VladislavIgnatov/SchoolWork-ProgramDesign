#include "orderedList.h"

Node *orderedInsert(Node *p, int newval){
  Node *q = NULL;
  Node *tmp;
  tmp = p;
  
  q = malloc (sizeof (Node));
  q->data = newval;
  
  if (p == NULL){
      q->next = p;
      return q;
    }
  if (newval <= p->data){
      q->next = p;
      return q;
    }

  else{
      while (tmp != NULL){
			if (tmp->data <= newval){
			 q->next = tmp->next;
			 tmp->next = q;
			 return p;
			}
		tmp = tmp->next;
		}
      return p;
	}
}

void printList(FILE *outfile, Node *p){
   Node *tmp = p;

  while(tmp != NULL){
      fprintf(outfile,"%d ", tmp->data);
      tmp = tmp->next;
    }
  puts ("");
}

void clearList(Node **p){
  Node *tmp;

  while (*p != NULL){
      tmp = *p;
      *p = (*p)->next;
      free (tmp);
    }
}
