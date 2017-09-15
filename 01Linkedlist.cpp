#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
/*
Insertion Sort. Given a file contains a list of English words,
your task is to construct a linked list (in ascending order) for the words.
Your linked list must have a dummy node that is pointed by the listHead.
For example,
Insert (you):
listHead --> (dummy, you) --> (you,  null)
*/

using namespace std;

class linkedList{
//to create a class node
    class listNode{
    public:
        string data;
        listNode *next;

        listNode(){
            next = NULL;
        }

        listNode(string str){
            data = str;
            next = NULL;
        }

    };

public:
    listNode *listHead;

    linkedList(string ele){
        listHead = new listNode(ele);
    }

    bool isEmpty(){
        if(listHead == NULL){
            return true;
        }
        return false;
    }

    void listInsertOrdered(string data){
//to insert a data according to alphabetical order
        listNode *curr = listHead->next;
        listNode **target = &listHead->next;
        listNode *newNode = new listNode(data);

        if(curr == NULL){
            newNode->next = curr;
            listHead->next = newNode;
        }else{
            while((curr != NULL)&&(curr->data.compare(data)< 0)){
            target = &curr->next;
            curr = curr ->next;
            }
            *target = newNode;
            newNode->next = curr;
        }
        return;
    }

    void listInsert(string data){
//just to insert a data
        listNode *po = listHead;
        listNode *node = new listNode(data);

        if(po->next == NULL){
            node->next = listHead->next;
            listHead->next = node;
        }else{
            while(po->next != NULL){
                po = po->next;
            }
            node->next = po->next;
            po->next = node;
        }
    }

    void listDelete(string data){
        listNode *curr = listHead;
        listNode **prev = &listHead;

        while((curr != NULL)&&(data != curr->data)){
            prev = &curr->next;
            curr = curr->next;
        }

        if(curr != NULL){
            *prev = curr->next;
            delete curr;
        }
        return;
    }

    void printList(string ele, ofstream &output){

		listNode *curr = listHead;
        output << "Insert" << " (" + ele + "):\n";
		output << "listHead-->";

        while(true){
            if(curr->next == NULL){
                output << "(" << curr->data << ", NULL)\n" << endl;
                return;
            }else{
                output << "(" << curr->data << ","<< curr->next->data<<")-->";
            }
            curr = curr->next;
		}
    }

};

int main(int argc, char *argv[]) {
//code::block to set up the arguments: project->set program's argument (argv[1],argv[2])
    ifstream inputEle(argv[1]);
    ofstream outputEle(argv[2]);

    linkedList theList("dummy");

    string ele;
    int icount = 0;

    bool bo = theList.isEmpty();
//to insert 15 nodes.
    while(inputEle >> ele && icount <15){
        theList.listInsertOrdered(ele);
        theList.printList(ele, outputEle);
        icount++;
    }

    return 0;
}
