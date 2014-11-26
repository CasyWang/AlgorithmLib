#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node {
    node* next;
    int value;
}tsNode;

void ReverseList(tsNode* head);
void CreateList(tsNode* head);
void PrintList(tsNode* head);

int main()
{
    cout << "Hello world!" << endl;
    tsNode* Head = new tsNode;
    CreateList(Head);
    ReverseList(Head);
    PrintList(Head);
    return 0;
}

//传入链表头head
void CreateList(tsNode* head) {
    tsNode* tail = head;    //表尾表头
    cout << "Please input the elements, end with #:" << endl;
    string strInput = "";
    while(true) {
        getline(cin, strInput);
        if(strInput.compare("#") == 0) {
            break;
        }

        int value = atoi(strInput.c_str());
        tsNode* node = new tsNode;  //Instance
        node->value = value;
        node->next = NULL;

        tail->next = node;
        tail = node;
    }
    cout << "End input." << endl;
}

void ReverseList(tsNode* head) {
    if(head == NULL) return;

    tsNode* p = head->next;
    tsNode* q = p->next;
    tsNode* r = q->next;
    p->next = NULL;    //Tail
    //head->next = NULL;    //Bug
    while(r != NULL) {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    head->next = q;
}

void PrintList(tsNode* head) {
    if(head == NULL)  return;

    tsNode* p = head->next;
    while(p != NULL) {
        cout << p->value << endl;
        p = p->next;
    }
}
