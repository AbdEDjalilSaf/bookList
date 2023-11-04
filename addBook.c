#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct dataStruct
{
int key;
const char*title;  
const char*author;  
int nbcopy;
struct dataStruct* next;
}*book;

book head = NULL;
/* ------------------------------ add in the End  ----------------------------*/
book createNode(int key,const char*title,const char*author,int nbcopy){
book newNode = malloc(sizeof(struct dataStruct));
newNode->key = key;
newNode->title = title;
newNode->author = author;                                                                                                                                                       
newNode->nbcopy = nbcopy;
newNode->next = NULL;

return newNode;
}

/*-----------------------------------  AddBookEnd    --------------------------------------*/

void addBookEnd(book head,int key,const char*title,const char*author,int nbcopy){
    book newnode = createNode(key,title,author,nbcopy);

if(head == NULL){
    head = newnode;
}
else
{
    book t = head;
    while (t->next != NULL)
    {
            t = t->next;
            t->next = newnode; 

    }  
}
}

/*-----------------------------------      DeleteBookByKey    ----------------------------------*/

void deleteBookByKey(book head,int key){
book t = head;
book p = NULL;

if(t->next != NULL && t->key != key){
    p = t;
    t = t->next; 
}
if(t == NULL){
    return;
}
if(t == head){
    head = head->next;
}else{
    p->next = t->next;
    free(t);
}
}
/*-----------------------------------      FindBookByKey    -----------------------------*/
book findBookByKey(book head,int key){
book t = head;
// book p = NULL;

if(t->next != NULL && t->key != key){
    // p = t;
    t = t->next; 
}
if(t == NULL){

    return NULL;
    
}
if(t == head){

    head = head -> next;

}else{

    // p->next = t->next;
    return t;
}


}
/*-----------------------------------      ExportBookByKey    -----------------------------*/
void exportBookByKey(book head,int key){

if(head == NULL){
    return;
}
else
{
book g = findBookByKey(head,key);

if(nbcopy > 1){
    g->nbcopy = g->nbcopy - 1;
}else{
deleteBookByKey(head,key);

}
}
}
/*-----------------------------------      ReturntBookByKey    -----------------------------*/
void returnBookByKey(book head,int key,const char*title,const char*author,int nbcopy){

book newnode = createNode(key,title,author,nbcopy);

if(head == NULL){
    head = newnode;
}               
else
{
book g = findBookByKey(head,key);

if(nbcopy > 1){
    g->nbcopy = g->nbcopy + 1;
}else{
book m = addBookEnd(book head,key,title,author,nbcopy);
}
}


}




























int main(){
    
    
    
    
    return 0;
}





