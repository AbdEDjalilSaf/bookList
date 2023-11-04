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

void addBookEnd(book*head,int key,const char*title,const char*author,int nbcopy){
    book newnode = createNode(key,title,author,nbcopy);

if(*head == NULL){
    *head = newnode;
}
else
{
    book t = *head;
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
book findBookByKey(book*head,int key){
book t =  *head;
// book p = NULL;

if(t->next != NULL && t->key != key){
    // p = t;
    t = t->next; 
}
if(t == NULL){

    return NULL;
    
}
if(t != *head){

     *head = *head->next;

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
book g = findBookByKey(&head,key);

if(g->nbcopy > 1){
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
book m = addBookEnd(&head,key,title,author,nbcopy);
}
}


}




























int main(){
    book head = NULL;
   addBookEnd(&head,1,"aaaaaaa","sssssss",55); 
   addBookEnd(&head,2,"bbbbbbb","ttttttt",51); 
   addBookEnd(&head,3,"ccccccc","uuuuuuu",52); 
   addBookEnd(&head,4,"ddddddd","vvvvvvv",54); 
   addBookEnd(&head,5,"eeeeeee","wwwwwww",53); 
   addBookEnd(&head,6,"fffffff","xxxxxxx",56); 
   addBookEnd(&head,7,"ggggggg","yyyyyyy",57); 
   addBookEnd(&head,8,"hhhhhhh","zzzzzzz",58); 

book f = findBookByKey(&head,7);
    
    printf("%d",f->nbcopy);
    
    return 0;
}





