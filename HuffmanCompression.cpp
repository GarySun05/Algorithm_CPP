#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class listBinTreeNode{
public:
    string chStr;
    int prob;
    listBinTreeNode *next;
    listBinTreeNode *left;
    listBinTreeNode *right;

    listBinTreeNode(){};
    listBinTreeNode(string cs, int pb){
        chStr = cs;
        prob = pb;
        next = NULL;
        left = NULL;
        right = NULL;
    }

    void printNode(listBinTreeNode *T, ofstream &output){
        if(T->next == NULL && T->left == NULL && T->right == NULL){
            output << T->chStr << "\t\t" << T->prob << "\t\t" << "NULL" << "\t\t" << "NULL" << "\t\t" <<"NULL" << endl;
        }else if(T->next == NULL){
            output << T->chStr << "\t\t" << T->prob << "\t\t" << "NULL" << "\t\t" << T->left->chStr << "\t\t" << T->right->chStr << endl;
        }else if(T->left == NULL && T->right == NULL){
            output << T->chStr << "\t\t" << T->prob << "\t\t" << T->next->chStr << "\t\t" << "NULL" << "\t\t" << "NULL" << endl;
        }
        else{
            output << T->chStr << "\t\t" << T->prob << "\t\t" << T->next->chStr << "\t\t" << T->left->chStr << "\t\t" << T->right->chStr << endl;
        }
    }

};

class HuffmanLinkedList{
public:
    listBinTreeNode *listHead;
    listBinTreeNode *oldListHead;

    HuffmanLinkedList(){};
    HuffmanLinkedList(string str, int prob){
        listHead = new listBinTreeNode(str, prob);
        oldListHead = listHead;
    }

 	void constructHuffmanLList(string chStr, int prob) {

        listBinTreeNode *spot = findSpot(prob);

        //make a new node with chStr and probability
        listBinTreeNode *newNode = new listBinTreeNode(chStr, prob);

        //inserting newNode between spot and spot.next;
        listInsert(spot, newNode);
	}

    listBinTreeNode* findSpot(int prob) {

		listBinTreeNode *temp = listHead;

		if(temp->prob >= prob) {
			return temp;
		}

		while(temp->next != NULL && temp->next->prob < prob) {
			temp = temp->next;
		}

		return temp;
	}

	void listInsert(listBinTreeNode *spot, listBinTreeNode *newNode) {

		if(spot->prob == 0) {
			newNode->next = listHead->next;
			listHead->next = newNode;
		}else if(spot != NULL && spot->prob < newNode->prob) {
			newNode->next = spot->next;
			spot->next = newNode;
		}
	}

	bool isEmpty(){
		if(listHead == NULL)
			return true;
		else
			return false;
	}

	void printList(ofstream &output){

		listBinTreeNode *tempNode = listHead;
		output << "listHead -->" << "(\"" << tempNode->chStr << "\"," << tempNode->prob << ",";

		while (tempNode->next != NULL) {
			tempNode = tempNode->next;
			output << "\""+ tempNode->chStr << "\")-->(\"" << tempNode->chStr << "\"," << tempNode->prob << ",";
		}

		output << "NULL)" << "-->" << "NULL" << endl;
	}
};

class HuffmanBinaryTree{
public:
    listBinTreeNode *root;

	listBinTreeNode* constructHuffmanBinTree(HuffmanLinkedList *hfm,ofstream &output){
		listBinTreeNode *dummy = new listBinTreeNode("dummy",0);
		hfm->oldListHead = dummy;
		hfm->oldListHead->next = hfm->listHead->next;

		root = hfm->listHead->next;

        output << "\n";
		while(root->next != NULL) {
			listBinTreeNode *newNode = new listBinTreeNode("", 0);
			newNode->prob = root->prob + root->next->prob;
			newNode->chStr = root->chStr + root->next->chStr;
			newNode->left = root;
			newNode->right = root->next;

            newNode->printNode(newNode, output);

			listBinTreeNode *spot = hfm->findSpot(newNode->prob);
			hfm->listInsert(spot,newNode);

			hfm->listHead = root->next->next;
			root = hfm->listHead;

			hfm->printList(output);

		}

		return root;

	}

	HuffmanBinaryTree(){}

	void constructCharCode(listBinTreeNode *T, string code, ofstream &output) {

        if(T == NULL) {
        	cout << "This is an empty tree!" << endl;
        	return;
        }else if(isLeaf(T)){
           output << T->chStr << "\t" << code << endl;
        }else {
	        constructCharCode (T->left, code + "0", output);
	        constructCharCode (T->right, code + "1", output);
        }
	}

	void preOrderTraversal(ofstream &output, listBinTreeNode *root) {
		if(root == NULL) {
			return;
		}else{
			root->printNode(root, output);
			preOrderTraversal(output,root->left);
			preOrderTraversal(output,root->right);
		}
	}

	void inOrderTraversal(ofstream &output, listBinTreeNode *root) {
		if(root == NULL) {
			return;
		}else{
			preOrderTraversal(output,root->left);
			root->printNode(root, output);
			preOrderTraversal(output,root->right);
		}
	}

    void postOrderTraversal(ofstream &output, listBinTreeNode *root) {
		if(root == NULL) {
			return;
		}else{
			preOrderTraversal(output,root->left);
			preOrderTraversal(output,root->right);
            root->printNode(root, output);
		}
	}



	bool isLeaf(listBinTreeNode *root) {
		if(root->left == NULL && root->right == NULL) {
			return true;
		}else
			return false;
	}

};

int main(int arc, char *argv[])
{
    ifstream inputEle(argv[1]);
    ofstream output1(argv[2]);
    ofstream output2(argv[3]);
    ofstream output3(argv[4]);
    ofstream output4(argv[5]);
    ofstream output5(argv[6]);

    HuffmanLinkedList *hfmLinkedList = new HuffmanLinkedList("dummy", 0);
    HuffmanBinaryTree *hfmBinaryTree = new HuffmanBinaryTree();

    string chStr;
    int prob;

    while(inputEle >> chStr && inputEle >> prob){
        hfmLinkedList->constructHuffmanLList(chStr, prob);
        hfmLinkedList->printList(output5);
    }

    listBinTreeNode *root = hfmBinaryTree->constructHuffmanBinTree(hfmLinkedList,output5);
    hfmBinaryTree->constructCharCode(root, "", output1);

    output2 << "T->chStr" << "\t" << "T->prob" << "\t\t" << "T->next.chStr" << "\t" << "T->left->chStr" << "\t" << "T->right->chStr" << "\n";
    output2 <<"-------------------------------------------------------------------------------" << "\n";
    hfmBinaryTree->preOrderTraversal(output2, root);

    output3 << "T->chStr" << "\t" << "T->prob" << "\t\t" << "T->next.chStr" << "\t" << "T->left->chStr" << "\t" << "T->right->chStr" << "\n";
    output3 <<"-------------------------------------------------------------------------------" << "\n";
    hfmBinaryTree->inOrderTraversal(output3, root);

    output4 << "T->chStr" << "\t" << "T->prob" << "\t\t" << "T->next.chStr" << "\t" << "T->left->chStr" << "\t" << "T->right->chStr" << "\n";
    output4 <<"-------------------------------------------------------------------------------" << "\n";
    hfmBinaryTree->postOrderTraversal(output4, root);

    inputEle.close();
    output1.close();
    output2.close();
    output3.close();
    output4.close();
    output5.close();

    return 0;
}
