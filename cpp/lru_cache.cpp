#include <stdio.h>
#include <map>

using namespace std;

#define _set(l, k, v) do{\
  printf("set(%d, %d)\n", k, v);\
  l.set(k, v);\
  l.print_list();\
} while(0)

#define _get(l, k) do{\
  printf("get(%d) \033[01;32m[%d]\033[0m\n", k, l.get(k));\
  l.print_list();\
} while(0)


struct Node{
  int key, value;
  Node *next, *prev;

  Node(int i, int j):key(i), value(j), next(NULL), prev(NULL){}
};


class LRUCache{
 private:
  int capacity;
  int size;
  map<int, Node*> dict;
  Node *head, *tail;

  void unlink(Node *p){
    if (this->head==p){
      this->head=p->next;
    }
    if (this->tail==p){
      this->tail=p->prev;
    }
    if (p->prev){
      p->prev->next=p->next;
    }
    if (p->next){
      p->next->prev=p->prev;
    }

    p->prev=NULL;
    p->next=NULL;

    --this->size;
  }

  void add_to_head(Node *p){
    if (this->head){
      this->head->prev=p;
    }
    if (!this->tail){
      this->tail=p;
    }
    p->next=this->head;
    this->head=p;
    ++this->size;
  }

  Node *remove_tail(){
    Node *p=this->tail;
    this->tail=this->tail->prev;

    if (this->size==1){
      this->head=NULL;
    } else{
      this->tail->next=NULL;
    }

    --this->size;

    return p;
  }

 public:
  LRUCache(int capacity){
    this->capacity=capacity;
    this->size=0;
    this->head=NULL;
    this->tail=NULL;
  }

  ~LRUCache(){
    while(this->head){
      Node *p=this->head;
      this->head=this->head->next;
      delete p;
    }
  }

  int get(int key){
    if (this->dict.find(key)!=this->dict.end()){
      Node *p=this->dict[key];
      unlink(p);
      add_to_head(p);

      return p->value;
    }
    return -1;
  }

  void set(int key, int value){
    Node *p;
    if (this->dict.find(key)!=this->dict.end()){
      p=this->dict[key];
      p->value=value;
      unlink(p);
    } else{
      p=new Node(key, value);
      this->dict[key]=p;

      if (this->size==this->capacity){
        Node *last=remove_tail();
        this->dict.erase(last->key);
        delete last;
      }
    }
    add_to_head(p);
  }

  void print_list(){
    Node *p=this->head;
    printf(">>> ");
    while (p){
      printf("%d ", p->value);
      p=p->next;
    }
    printf("\n");
  }
};


int main(){
  LRUCache l(2);
  _set(l, 2, 1);
  _set(l, 2, 2);
  _get(l, 2);
  _set(l, 1, 1);
  _set(l, 4, 1);
  _get(l, 2);

  return 0;
}
