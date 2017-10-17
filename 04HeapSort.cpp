#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class HeapSort {
public:
	int N;
	int rootIndex;
	int fatherIndex;
	int leftKidIndex;
	int rightKidIndex;
	int minKidIndex;
	int* heapArray;

	HeapSort(){
		N = 0;
		rootIndex = 1;
		fatherIndex = 0;
		leftKidIndex = 0;
		rightKidIndex = 0;
		minKidIndex = 0;
		heapArray = new int[N];
	}

	void buildHeap(ifstream &inFile,ofstream &pw01) {
		rootIndex = 1;
		int data = -1;
        while(inFile >> data) {
            insertOneDataItem(data);
            int kidIndex = heapArray[0];
            bubbleUp(kidIndex);
            pw01 << "\n";
            printHeap(pw01);
        }
	}

	void deleteHeap(ofstream &pw2) {
		while(heapArray[0] > 0) {
			int data = heapArray[1];
			pw2 << data << " ";
			deleteRoot();
			fatherIndex = rootIndex;
			bubbleDown(fatherIndex);
		}
	}

	void insertOneDataItem(int data) {
		heapArray[0]++;
		heapArray[heapArray[0]] = data;
	}

	int getRoot() {
		return 0;
	}

	void deleteRoot() {
		heapArray[rootIndex] = heapArray[heapArray[0]];
		heapArray[heapArray[0]] = -1;
		heapArray[0]--;
	}

	void bubbleUp(int kidIndex) {
		if(isRoot(kidIndex)) {
			return;
		}else {
			fatherIndex = kidIndex/2;
			if(heapArray[kidIndex] < heapArray[fatherIndex]) {
				int temp = heapArray[kidIndex];
				heapArray[kidIndex] = heapArray[fatherIndex];
				heapArray[fatherIndex] = temp;
			}
			bubbleUp(fatherIndex);
		}
	}

	void bubbleDown(int fatherIndex) {
		if(isLeaf(fatherIndex)) {
			return;
		}else {
			leftKidIndex = fatherIndex * 2;
			rightKidIndex = fatherIndex * 2 + 1;
			minKidIndex = findMinKidIndex(leftKidIndex, rightKidIndex);

			if(heapArray[minKidIndex] < heapArray[fatherIndex]) {
				int tempMin = heapArray[minKidIndex];
				heapArray[minKidIndex] = heapArray[fatherIndex];
				heapArray[fatherIndex] = tempMin;
				bubbleDown(minKidIndex);
			}

		}

	}

	bool isLeaf(int fa) {

		if(fa*2 >= heapArray[0]) {
			return true;
		}else {
			return false;
		}
	}

	bool isRoot(int kidIndex) {
		if(kidIndex == rootIndex)
			return true;
		else
			return false;
	}

	int findMinKidIndex(int leftKidIndex, int rightKidIndex) {
		if(heapArray[leftKidIndex] > heapArray[rightKidIndex]) {
			return rightKidIndex;
		}else
			return leftKidIndex;
	}

	bool isHeapEmpty() {
		if(heapArray[0] <= 0 )
			return true;
		else
			return false;
	}

	bool isHeapFull(int N) {
		if(heapArray[0] >= N-1) {
			return true;
		}else
			return false;

	}

    void printHeap(ofstream &pw) {
		for(int i = 1; i <= heapArray[0]; i++) {
			pw << heapArray[i]  << " ";
		}
	}

};

int main(int arc, char *argv[])
{
    HeapSort *hs = new HeapSort();


        ifstream inFile01(argv[1]);
        int data;
        while(inFile01 >> data) {
            hs->N++;
        }
        inFile01.close();


    hs->heapArray = new int[hs->N+1];
    hs->heapArray[0] = 0;

        ifstream inFile02(argv[1]);
        ofstream outFile01(argv[2]);
        ofstream outFile02(argv[3]);

        hs->buildHeap(inFile02, outFile01);
        hs->deleteHeap(outFile02);

        inFile02.close();
        outFile01.close();
        outFile02.close();


}
