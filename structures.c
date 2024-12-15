#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct Node{
int sum_key;
int key[3];
int content[7];
} node;

void printNode(node anode);
void printNodes(node nodes[20]);
void swap(node *a, node *b);
void downswap(node nodes[20], int size, int i);
void heapSort(node nodes[20], int size);


int main(int argc, char* argv[]){ 
    int n = 20;
    int array[20][10];
    int i,j;
    node nodes[20];
    FILE* file = fopen("f.dat", "r");
    if(file == NULL){ 
        return 1;
    } 
   for(i=0; i<20; i++) {
        for(j=0; j<10; j++) {
            if(j == 19){ 
                fscanf(file,"%d",&array[i][j]);
            }else{
                fscanf(file,"%d ",&array[i][j]);
            }
        }
    }
    
    for(i=0;i<20;i++){
        int content_length = 0; 
        for(j=0;j<3;j++){ 
            nodes[i].key[j] = array[i][j]; 
            
        }
        for(j=3;j<10;j++){
            nodes[i].content[content_length] = array[i][j]; 
            content_length++;
        }  
        nodes[i].sum_key = nodes[i].key[0] + nodes[i].key[1] + nodes[i].key[2];      
    }


    /*printNodes(nodes);*/
    
    
    heapSort(nodes,n);
    /*printf("after heap sort\n");*/
    /*printNodes(nodes);*/
    for(i=0;i<20;i++){
        for(j=0;j<3;j++){  
            printf("%d ", nodes[i].key[j]);
            
        }
        for(j=0;j<7;j++){ 
            printf("%d ", nodes[i].content[j]);
    
        } 
        printf("\n");
    }        
return 1;
}

void printNode(node anode){ 
    int j;
    printf("sum Key = %d ", anode.sum_key);
    for(j=0;j<3;j++){  
        printf("%d ", anode.key[j]);
        
    }
    for(j=0;j<7;j++){ 
        printf("%d ", anode.content[j]);
 
    }         
}

void printNodes(node nodes[20]){ 
    int i;
    for(i=0;i<20;i++){ 
        printNode(nodes[i]);
        printf("\n");
    }
}

void swap(node *a, node *b) {
    node temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void downswap(node nodes[], int size, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && nodes[left].sum_key > nodes[largest].sum_key)
      largest = left;
  
    if (right < size && nodes[right].sum_key > nodes[largest].sum_key)
      largest = right;
  
    
    if (largest != i) {
      swap(&nodes[i], &nodes[largest]);
      downswap(nodes, size, largest);
    }
  }

  
  void heapSort(node nodes[], int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--)
      downswap(nodes, size, i);
  
    
    for (i = size - 1; i >= 0; i--) {
      swap(&nodes[0], &nodes[i]);
  
      
      downswap(nodes, i, 0);
    }
  }
  




