#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>

typedef struct dataStruct
{
int key;
const char*title;  
const char*author;  
int nbcopy;
struct dataStruct* next;
}*book;

book head = NULL;
/* ------------------------------ create newNode  ----------------------------*/
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

void deleteBookByKey(book*head,int key){
book t = *head;
book p = NULL;

if(t->next != NULL && t->key != key){
    p = t;
    t = t->next; 
}
if(t == NULL){
    return;
}
while(t != NULL){
if(t->key == key){
    p->next = t->next;
    free(t);
}
}
}
/*-----------------------------------      FindBookByKey    -----------------------------*/
book findBookByKey(book head,int key){
book t =  head;

if(t->next != NULL && t->key != key){

    t = t->next; 
}
if(t == NULL){

    return NULL;
    
}
while(t != NULL){
if(t->key == key){

    return t;

}
}
}
/*-----------------------------------      ExportBookByKey    -----------------------------*/
void exportBookByKey(book*head,int key){

if(*head == NULL){
    return;
}
else
{
book g = findBookByKey(*head,key);
while(g != NULL){
if(g->key == key){
if(g->nbcopy > 1){
    g->nbcopy--;
}else{
deleteBookByKey(*head,key);
}
}
g = g->next;
}
}
}
/*-----------------------------------      ReturntBookByKey    -----------------------------*/
void returnBookByKey(book*head,int key){

if(*head == NULL){
    printf("NULL");
}               
else
{
book g = findBookByKey(*head,key);
while(g != NULL){
if(g->key == key){
    g->nbcopy++;

}
g = g->next;
}
addBookEnd(*head,key,"title","author",1);
}


}















/*-----------------------------------      DisplayBook   -----------------------------*/
void displayLibrary(book head){

if(head == NULL){

printf("your Library is NULL");

}else{

book  a = head;
printf("data is %d\n",a->key);
printf("nuber copy is %d\n",a->nbcopy);
 head = head->next;
}

}


/*-----------------------------------      FreeMemorie    -----------------------------*/
void fraaMemorie(book head){

book d;
while (head != NULL)
{
    d = head;
    head = head->next;
    free(d);
}

}













int main(){
    book head = NULL;
   addBookEnd(head,1,"aaaaaaa","sssssss",55); 
   addBookEnd(head,2,"bbbbbbb","ttttttt",51); 
   addBookEnd(head,3,"ccccccc","uuuuuuu",52); 
   addBookEnd(head,4,"ddddddd","vvvvvvv",54); 
   addBookEnd(head,5,"eeeeeee","wwwwwww",53); 
   addBookEnd(head,6,"fffffff","xxxxxxx",56); 
   addBookEnd(head,7,"ggggggg","yyyyyyy",57); 
   addBookEnd(head,8,"hhhhhhh","zzzzzzz",58); 

book f = createNode(87,"Mars","Musk",1000);
    
    printf("%d\n",f->nbcopy);
    



deleteBookByKey(&head,4);
displayLibrary(head);
printf("After deleting  ");
findBookByKey(&head,7);
displayLibrary(head);
printf("After finding  ");



displayLibrary(head);
fraaMemorie(head);
displayLibrary(head);
printf("After Free Library");
    return 0;
}





