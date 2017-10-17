#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct xyCoord{
    int xCor = 0;
    int yCor = 0;
    int label = 0;
};

class Point{
public:
    int X = 0;
    int Y = 0;
    int label = 0;
    double distance = 0;

    void printPoint(Point p){}
};

class KMean{
public:
    //given in the input file
    int K;
    xyCoord *kCentroid;
    int numPts;

    Point *pointSet;
    int numRow;
    int numColum;
    int **imageArray;
    int changeLabel;

    KMean(int k, int nps, int nr, int nc){
        K = k;
        //90 points
        numPts = nps;
        numRow = nr;
        numColum = nc;
        kCentroid = new xyCoord[K];
        pointSet = new Point[numPts];

        //dynamically declare 2-D array
        imageArray = new int*[numRow];
        for(int i = 0; i < numRow; i++){
            imageArray[i] = new int[numColum];
        }
        changeLabel = 0;
    }


    void loadPointSet(ifstream &inFile){
        int x, y;
        int index = 0;
        while(inFile >> x && inFile >> y){
                pointSet[index].X = x;
                pointSet[index].Y = y;
                index++;
        }
    }

    void assignLable(){
        int n = 1;
        for(int i = 1; i <= numPts; i++){
            if(i % 4 != 0 ){
                pointSet[i-1].label = n;
                n++;
            }else{
                pointSet[i-1].label = n;
                n = 1;
            }
        }
    }

    void mapPoint2Image(){
        for(int i = 0; i < numRow; i++){
            for(int j = 0; j < numColum; j++){
                imageArray[i][j] = 0;
            }
        }

        for(int i = 0; i < numPts; i++){
            imageArray[pointSet[i].X][pointSet[i].Y] = pointSet[i].label;
        }
    }

    void kMeanClustering(){
/*step 5
Go through the entire pointSet struct array to compute the centroids of each of the K clusters.
Store the computed centroids in each Kcentroids[i], i from 1 to K.
(** You should be able to compute the K centroids just go through the array only once.)
*/

        changeLabel = 0;

        int totalLabX1 = 0;
        int totalNum1 = 0;
        int totalLabY1 = 0;

        int totalLabX2 = 0;
        int totalNum2 = 0;
        int totalLabY2 = 0;

        int totalLabX3 = 0;
        int totalNum3 = 0;
        int totalLabY3 = 0;

        int totalLabX4 = 0;
        int totalNum4 = 0;
        int totalLabY4 = 0;

        //the total number of x or y in pointSet[i] according to label 1 or 2 or 3 or 4.
        for(int i = 0; i < numPts; i++){
            if(pointSet[i].label == 1){
                //label 1
                totalLabX1 += pointSet[i].X;
                totalLabY1 += pointSet[i].Y;
                totalNum1++;
            }else if(pointSet[i].label == 2){
            //label 2
                totalLabX2 += pointSet[i].X;
                totalLabY2 += pointSet[i].Y;
                totalNum2++;
            }else if(pointSet[i].label == 3){
            //label 3
                totalLabX3 += pointSet[i].X;
                totalLabY3 += pointSet[i].Y;
                totalNum3++;
            }else if(pointSet[i].label == 4){
            //label 4
                totalLabX4 += pointSet[i].X;
                totalLabY4 += pointSet[i].Y;
                totalNum4++;
            }
        }

        for(int i = 0; i < K; i++){
            //there are 4 K in kCentroid[4], and to assign label into kCentroid[k].
            if(i == 0 && totalNum1 != 0){
                //the sum of x or y / the number of x or y.
                kCentroid[i].xCor = totalLabX1/totalNum1;
                kCentroid[i].yCor = totalLabY1/totalNum1;
                kCentroid[i].label = i + 1;
            }else if(i == 1 && totalNum2 != 0){
                kCentroid[i].xCor = totalLabX2/totalNum2;
                kCentroid[i].yCor = totalLabY2/totalNum2;
                kCentroid[i].label = i + 1;
            }else if(i == 2 && totalNum3 != 0){
                kCentroid[i].xCor = totalLabX3/totalNum3;
                kCentroid[i].yCor = totalLabY3/totalNum3;
                kCentroid[i].label = i + 1;
            }else if(i == 3 && totalNum4 != 0){
                kCentroid[i].xCor = totalLabX4/totalNum4;
                kCentroid[i].yCor = totalLabY4/totalNum4;
                kCentroid[i].label = i + 1;
            }
        }
    }

    void dis(){
        double dsX = 0;
        double dsY = 0;
        double ds1 = 0;
        double ds2 = 0;
        double ds3 = 0;
        double ds4 = 0;
        Point *min = new Point();

        for(int j = 0; j < numPts; j++){
            for(int i = 0; i < K; i++){
                if(i == 0){
                    dsX = pow(kCentroid[i].xCor - pointSet[j].X, 2);
                    dsY = pow(kCentroid[i].yCor - pointSet[j].Y, 2);
                    ds1 = sqrt( dsX + dsY);
                    min->distance = ds1;
                    min->label = kCentroid[i].label;
                }else if(i == 1){
                    dsX = pow(kCentroid[i].xCor - pointSet[j].X, 2);
                    dsY = pow(kCentroid[i].yCor - pointSet[j].Y, 2);
                    ds2 = sqrt( dsX + dsY);
                    if(ds2 <= min->distance){
                        min->distance = ds2;
                        min->label = kCentroid[i].label;
                    }
                }else if(i == 2){
                    dsX = pow(kCentroid[i].xCor - pointSet[j].X, 2);
                    dsY = pow(kCentroid[i].yCor - pointSet[j].Y, 2);
                    ds3 = sqrt( dsX + dsY);
                    if(ds3 <= min->distance){
                        min->distance = ds3;
                        min->label = kCentroid[i].label;
                    }
                }else if(i == 3){
                    dsX = pow(kCentroid[i].xCor - pointSet[j].X, 2);
                    dsY = pow(kCentroid[i].yCor - pointSet[j].Y, 2);
                    ds4 = sqrt( dsX + dsY);
                    if(ds4 <= min->distance){
                        min->distance = ds4;
                        min->label = kCentroid[i].label;
                    }
                }

            }

            if(min->label != pointSet[j].label){
                pointSet[j].label = min->label;
                changeLabel++;
            }

        }
    }

    void printPointSet(ofstream &outFile1, int k, int numPs, int nr, int nc){
        outFile1 << k << "\n";
        outFile1 << numPs << "\n";
        outFile1 << nr << " " << nc << "\n";
        for(int i = 0; i < numPs; i++){
            outFile1 << pointSet[i].X << " " << pointSet[i].Y << " " << pointSet[i].label << "\n";
        }
    }

    void prettyPrint(ofstream &outFile2){
        for(int i = 0; i < numRow; i++){
            for(int j = 0; j < numColum; j++){
                if(imageArray[i][j]>0){
                    outFile2 << imageArray[i][j];
                }else{
                    outFile2 << " ";
                }
            }
            outFile2 << "\n";
        }
    }

};


int main(int arc, char *argv[])
{
    ifstream inFile(argv[1]);
    ofstream outFile1(argv[2]);
    ofstream outFile2(argv[3]);

    int intData[4];
    int data;
    int num = 0;

    while(num <4 && inFile >> data){
        intData[num] = data;
        num++;
    }

    KMean *km = new KMean(intData[0], intData[1], intData[2], intData[3]);

    //step 1
    km->loadPointSet(inFile);
    //step 2
    km->assignLable();

do{
    //step 3
    km->mapPoint2Image();

    //step 4
    km->prettyPrint(outFile2);

    //step 5
    km->kMeanClustering();

    cout << endl;
    //step 6
    km->dis();

    outFile2 << "*****************************************************************************************" << "\n";
}while(km->changeLabel > 0);

    km->printPointSet(outFile1, intData[0],intData[1],intData[2],intData[3]);

    inFile.close();
    outFile1.close();
    outFile2.close();
    return 0;
}
