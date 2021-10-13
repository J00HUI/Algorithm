// 단순 연결 리스트

// Node.h
#include <cstdio>

class Node {
    Node* link;
    int data;
public:
    Node(int val=0) : data(val), link(NULL) {}
    Node* getLink()          { return link; }
    void setLink(Node* next) { link = next; }
    void display()           { printf(" <%2d>", data); }
    bool hasData(int val)    { return data == val; }
  
    void insertNext(Node* n) {
        if(n!=NULL) {
          n->link = link;
          link = n;
        }
    }
  
    Node* removeNext() {
        Node* removed = link;
      
        if (removed != NULL )
            link = removed -> link;
      
        return removed;
    }
};


// LinkedList.h
#include "Node.h"

class LinkedList {
    Node org;
public:
    LinkedList(): org(0) {}
    ~LinkedList() { clear(); }
    void clear()  { while(!isEmpty()) delete remove(0); }
    Node* getHead() { return org.getLink(); }
    bool isEmpty()  { return getHead()==NULL; }
    
    // pos 번째 항목을 반환함)
    Node* getEntry(int pos){
        Node* n = &org;
        for(int i=-1; i<pos; i++, n=n->getLink())
          if( n==NULL ) break;
        return n;
    }
  
  // pos 왼쪽 위치에 삽입
  void insert(int pos, Node* n) {
      Node* prev = getEntry(pos-1);
      if(prev != NULL)
          prev -> insertNext(n);
  }
  
  // pos 위치 항목 삭제
  Node* remove(int pos) {
      Node* prev = getEntry(pos-1);
      return prev->removeNext();
  }
  
  // 탐색 함수
  Node* find(int val) {
      for( Node* p = getHead(); p!= NULL; p=p->getLink() )
          if( p->hasData(val) )  return p;
       return NULL;
  }
  
  void replace(int pos, Node* n) {
      Node* prev = getEntry(pos-1);
      if (prev != NULL ) {
          delete prev->removeNext();
          prev->insertNext(n);
      }
  }
  
  int size() {
      int count = 0;
      for( Node* p = getHead(); p!= NULL; p=p->getLink() )
          count++;
      return count;
  }
  
  void display() {
      printf("[전체 항목 수 = %2d] : ", size());
      for( Node* p = getHead(); p!= NULL; p=p->getLink() )
          p -> display();
      printf("\n");
  }
}



// LinkedList.cpp
#include "LinkedList.h"
void main() {
    LinkedList list;
    list.insert(0, new Node(10));                   // 10
    list.insert(0, new Node(20));                   // 20 10
    list.insert(1, new Node(30));                   // 20 30 10     리스트 1위치에 30 삽입
    list.insert(list.size(), new Node(40));         // 20 30 10 40  리스트 마지막에 40 삽입
    list.insert(2, new Node(50));                   // 20 30 50 10 40 
    list.display();
    list.remove(2);                                 // 20 30 10 40 
    list.remove(list.size()-1);                     // 20 30 10
    list.remove(0);                                 // 30 10 
    list.replace(1, new Node(90));                  // 30 90
    list.display();
    list.clear();
    list.display();
}

// 이중 연결 리스트

// Node2.h
class Node2 {
    Node2* prev;
    Node2* next;
    int   data;
public:
    Node2(int val=0) : data(val), prev(NULL), next(NULL) { }
    Node2* getPrev()    {  return prev;  }
    Node2* getNext()    {  return next;  }
    void setPrev(Node2* p)  {  prev = p;  }
    void setNext(Node2* n)  {  next = n;  }
  void display()          { printf("<%2d>", data);  }
  bool hasData(int val)   { return data == val;  }
  
  void insertNext(Node2* n) {
      if (n!=NULL) {
          n-> prev = this;
          n-> next = next;
          if(next != NULL) next -> prev = n;
          next = n;
      }
  }
  
  Node2* remove() {
      if (prev != NULL) prev->next = next;
      if (next != NULL) next->prev = prev;
      return this;
  }
}

// DbLinkedList.h
#include "Node2.h"
class DbLinkedList {
    Node2   org;
public:
    DbLinkedList(): org(0) {  }
    ~DbLinkedList()  {  while(!isEmpty()) delete remove(0);  }
    Node2* getHead()  { return org.getNext();  }
    bool isEmpty()    { return getHead() == NULL;  }
  
    Node2* getEntry(int pos) {
        Node2* n = &org;
        for(int i=-1; i<pos; i++, n=n->getNext())
            if (n==NULL) break;
      
        return n; 
    }
  
    void insert(int pos, Node2* n) {
          Node2* prev = getEntry(pos-1);
          if( prev != NULL ) 
              prev->insertNext(n);
    }
  
    Node2* remove(int pos) {
          Node2* n = getEntry(pos);
          return n->remove();
    }
  
    Node2* find(int val) {
          for (Node2* p = getHead(); p!=NULL; p=p->getNext()) 
              if (p->hasData(val)) return p;
          return NULL;
    }
  
    void replace(int pos, Node2* n) {
        Node* prev = getEntry(pos-1);
        if(prev != NULL) {
            delete prev->getNext()->remove();
            prev->insertNext(n);
        }
    }
  
    int size() {
          int count = 0;
          for (Node2* p = getHead(); p!=NULL; p=p->getNext())
               count++;
          return count;
    }
  
    void display() {
          printf("[이중 연결 리스트 항목 수 = %2d] : ", size());
          for(Node2* p = getHead(); p!=NULL; p=p->getNext())
              p -> display();
          printf("\n");
    }
};


// DbLinkedList.cpp
#include "DbLinkedList.h"
void main() {
    DbLinkedList list;
    list.insert(0, new Node2(10));
    list.display();
    list.remove(2);
    list.replace(1, new Node2(90));
    list.clear();
    list.display();
}
  
  
  
