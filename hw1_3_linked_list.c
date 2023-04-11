#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int num;
    struct node * next;
}node;



void insert(node * linked_list, int num){
    if(linked_list->next == NULL){
        node * newnode = malloc(sizeof(node));

        // newnode->next = linked_list->next;
        linked_list->next = newnode;
        newnode->next = NULL;
        newnode->num = num;
    }
    else{

        node *cur = linked_list;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        
        node * newnode = malloc(sizeof(node));

        newnode->next = NULL;
        newnode->num = num;

        cur->next = newnode;
    }
}

void how_long(node * linked_list){
    node * cur = linked_list;
    int length=0;
    while(cur->next != NULL){
        length++;
        cur = cur->next;
    }

    printf("\nhow long is the array: %d\n",length);
}
void delete_third(node * linked_list){
    node * cur = linked_list;

    int length=0;
    while(cur->next != NULL){
        length++;
        cur = cur->next;
    }

    int how_long = length;
    cur = linked_list;

    for(int i = 0; i<how_long - 3; i++){
        cur = cur->next;
    }
    node * temp = cur->next;
    cur -> next = temp->next; 

}

void print_linked_list(node * linked_list){
    node * cur = linked_list;

    int length=0;
    while(cur->next != NULL){
        length++;
        cur = cur->next;
    }
    
    cur = linked_list;

    cur = cur->next;
    printf("1st line: ");
    for(int i = 0; i < length/3;i++){
        printf("%d ", cur->num);
        cur = cur->next;
    }
    printf("\n");

    printf("2st line: ");
    for(int i = 0; i < (length-length/3)/2; i++){
        printf("%d ", cur->num);
        cur = cur->next;
    }
    printf("\n");
    
    printf("3st line: ");
    while(cur!=NULL){
        printf("%d ",cur->num);
        cur=cur->next;
    }
    printf("\n");

    // while(cur!=NULL){
    //     printf("%d ",cur->num);
    //     cur=cur->next;
    // }
}

int * create_random_array(){
    static int A[60];
    srand(time(NULL));
    int arr[1000]={0};

    for(int i = 0; i < 60; i++){
        int temp = rand()%1000;
        if(arr[temp] == 0){
            A[i] = temp;
            arr[temp] = 1;
        }
        else{
            i--;
        }

    }
    return A;
}
int main(){
    node * linked_list = malloc(sizeof(node));
    linked_list -> next = NULL;

    int * arr = malloc(sizeof(int));
    arr = create_random_array();


    for(int i = 0; i < 60; i++){
        insert(linked_list,arr[i]);
    }

    print_linked_list(linked_list);
    // how_long(linked_list);

    printf("\n");
    
    delete_third(linked_list);
    // how_long(linked_list);
    print_linked_list(linked_list);
    // how_long(linked_list);

    printf("\n");

    delete_third(linked_list);
    // how_long(linked_list);
    print_linked_list(linked_list);
    // how_long(linked_list);

    printf("\n");

    delete_third(linked_list);
    // how_long(linked_list);
    print_linked_list(linked_list);
    // how_long(linked_list);


    return 0;
}