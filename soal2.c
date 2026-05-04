/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 – Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Nicholas L. M. Simarmata (13224060)
 *   Nama File           : soal2.c
 *   Deskripsi           : Program untuk merge 2 linked list berurut
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* initial(int data){
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    return new;
}

node* new(node* head, int data){
    if(head == NULL){
        head = initial(data);
    } else {
        node* proses = head;
        while(proses->next != NULL){
            proses = proses->next;
        }
        proses->next = initial(data);
    }

    return head;
}

void display(node* head){
    node* proses = head;
    if(proses == NULL){
        printf("MERGED EMPTY ");
        return;
    } else printf("MERGED ");

    while(proses != NULL){
        printf("%d ", proses->data);
        proses = proses->next;
        // if(proses->next != NULL) printf(" ");
    }
}

node* algo(node* head, node* head1, node* head2){
    node* proses1 = head1;
    node* proses2 = head2;
    node* merged = head;

    while(proses1 != NULL && proses2 != NULL){
        if(proses1->data < proses2->data){
            merged = new(merged, proses1->data);
            merged = new(merged, proses2->data);
        } else if (proses1->data >= proses2->data){
            merged = new(merged, proses2->data);
            merged = new(merged, proses1->data);
        }
        proses1 = proses1->next;
        proses2 = proses2->next;
    }

    while(proses1 != NULL){
        merged = new(merged, proses1->data);
        proses1 = proses1->next;
    }
    while(proses2 != NULL){
        merged = new(merged, proses2->data);
        proses2 = proses2->next;
    }

    display(merged);

    return head;
}



node* interface(node* head){
    int N1; node* head1 = NULL;
    int N2; node* head2 = NULL;

    node* proses = head;

    // scanf("%d", &N1);
    // int tempArr[N1];
    // for(int i = 0; i < N1; i++){
    //     // int temp1;
    //     scanf("%d", &tempArr[i]);
    //     printf("%d\n", tempArr[i]);
    // }
    // for(int i = 0; i < N1; i++){
    //     printf("%d\n", tempArr[i]);
    //     head1 = new(head1, tempArr[i]);
    // }

    scanf("%d", &N1);
    for(int i = 0; i < N1; i++){
        int temp1;
        scanf("%d", &temp1);
        head1 = new(head1, temp1);
    }

    scanf("%d", &N2);
    for(int i = 0; i < N2; i++){
        int temp2;
        scanf("%d", &temp2);
        head2 = new(head2, temp2);
    }

    // display(head1);printf("\n");
    // display(head2);

    // printf("1:%d\n",head1->data);
    proses = algo(proses, head1, head2);

    // display(proses);

    return head;

}

int main(){
    node* head = NULL;
    head = interface(head);

    return 0;
}
