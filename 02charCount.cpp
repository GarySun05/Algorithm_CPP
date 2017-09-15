#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <string>

using namespace std;

class charCount{
/*
if we want to new an Array, two ways:
    1.int num[30];
    2.int *num = new int[30];
'int' uses 'sizeof(num)/sizeof(int)', because 'sizeof' computes the byte.
*/
public:
    int charCounts[256] = {0};

    void charIn(char charWord){
        int index = (int)charWord;
        charCounts[index]++;
    }

    printAry(ofstream &print){
//to print all results.
        for(int index = 0; index < sizeof(charCounts)/sizeof(int); index++){
            if(charCounts[index] > 0){
                print << (char)index << "    " << charCounts[index] << "\n";
            }
        }
    }
};

int main(int argc, char *argv[])
{
    charCount cc;
    ifstream inputEle(argv[1]);
    ofstream outputEle(argv[2]);

    string word;
//to read words from a file.
    while(inputEle >> word){
        cout << word << endl;
        for(int i = 0; i < word.length(); i++){
            //to pass a char to 'charIn'.
            char cha = word.at(i);
            cc.charIn(cha);

        }
    }

    cc.printAry(outputEle);
//to close all files.
    inputEle.close();
    outputEle.close();
    return 0;
}
