#include <iostream>
#include <fstream>
#include <iomanip>
#include "MaxHeap.h"
#include "Packet.h"

using namespace std;

//void readFile(MaxHeap<Packet> packetHeap);
//void buildHeap (MaxHeap<Packet> packetHeap);
//void dequeue(MaxHeap<Packet> packetHeap);


int main()
{
    MaxHeap<Packet> packetHeap;
    double transferTime;
    int transferSpeed = 90;
    double megaBitsValue = 8.0;
    int heapSize = 3;

    int sevenCounter = 0;
    int sixCounter = 0;
    int fiveCounter = 0;
    int fourCounter = 0;
    int threeCounter = 0;
    int twoCounter = 0;
    int oneCounter = 0;
    int zeroCounter = 0;

    double sevenAverage, sevenTotalSum = 0;
    double sixAverage, sixTotalSum = 0;
    double fiveAverage, fiveTotalSum = 0;
    double fourAverage, fourTotalSum = 0;
    double threeAverage, threeTotalSum = 0;
    double twoAverage, twoTotalSum = 0;
    double oneAverage, oneTotalSum = 0;
    double zeroAverage, zeroTotalSum = 0;

    ifstream infile;
    string line;


    infile.open("packets1.txt");
    if(!infile.is_open()) {
        cout << "No file found..." << endl;
        exit(0);
    }

    //readFile(packetHeap);
    //buildHeap(packetHeap);
    //dequeue(packetHeap);


    //1.**Enqueues packets into max heap**
    while (getline(infile, line))
    packetHeap.add(line);


    int size = packetHeap.getNumberOfNodes();
    for (int i = 0; i < 35; i++) {
        cout << packetHeap.peek() << endl;
        packetHeap.remove();
    }

    //cout << packetHeap.peek();
    //packetHeap.displayHeap();








    /*
    //2.**Dequeues the packets and determines transfer time of each**
    Packet node = packetHeap.peek();
    while (!packetHeap.isEmpty()) {
        node = packetHeap.peek();
        packetHeap.remove();
        cout << "Removing packet: " << node;
        transferTime = (node.getFileSize() megaBitsValue) / transferSpeed;
        cout << "Time to transfer packet: "  << fixed << setprecision(3) << transferTime << " seconds" << endl;
        cout << "-------------------------------------------------" << endl;
    }
    */


    /*
    3.**Displays the number of packets at each priority level**
    Packet node = packetHeap.peek();
    while(!packetHeap.isEmpty()) {

        if (node.getPriorityNumber() == 7) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            sevenCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 6) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            sixCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 5) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            fiveCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 4) {
            packetHeap.remove();
            //cout << "Found packet with 4: " << node << endl;
            fourCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 3) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            threeCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 2) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            twoCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 1) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            oneCounter++;
            //cout << "------------------------------------------------" << endl;
        }
        else if (node.getPriorityNumber() == 0) {
            packetHeap.remove();
            //cout << "Found packet with 7: " << node << endl;
            zeroCounter++;
            //cout << "------------------------------------------------" << endl;
        }

        node = packetHeap.peek();
    }


    cout << "There are " << sevenCounter << " packets at priority level 7" << endl;
    cout << "There are " << sixCounter << " packets at priority level 6" << endl;
    cout << "There are " << fiveCounter << " packets at priority level 5" << endl;
    cout << "There are " << fourCounter << " packets at priority level 4" << endl;
    cout << "There are " << threeCounter << " packets at priority level 3" << endl;
    cout << "There are " << twoCounter << " packets at priority level 2" << endl;
    cout << "There are " << oneCounter << " packets at priority level 1" << endl;
    cout << "There are " << zeroCounter << " packets at priority level 0" << endl;

    /*
    cout << sevenCounter << endl;
    cout << sixCounter << endl;
    cout << fiveCounter << endl;
    cout << fourCounter << endl;
    cout << threeCounter << endl;
    cout << twoCounter << endl;
    cout << oneCounter << endl;
    cout << zeroCounter << endl;
    */


    //**4. Displays the amount of time each priority level takes (average?)**
    /*
    Packet node = packetHeap.peek();


    while(!packetHeap.isEmpty()) {

        if (node.getPriorityNumber() == 7) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            sevenTotalSum += transferTime;
            sevenCounter++;
        }
        else if(node.getPriorityNumber() == 6) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            sixTotalSum += transferTime;
            sixCounter++;
        }
        else if(node.getPriorityNumber() == 5) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            fiveTotalSum += transferTime;
            fiveCounter++;
        }
        else if(node.getPriorityNumber() == 4) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            fourTotalSum += transferTime;
            fourCounter++;
        }
        else if(node.getPriorityNumber() == 3) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            threeTotalSum += transferTime;
            threeCounter++;
        }
        else if(node.getPriorityNumber() == 2) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            twoTotalSum += transferTime;
            twoCounter++;
        }
        else if(node.getPriorityNumber() == 1) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            oneTotalSum += transferTime;
            oneCounter++;
        }
        else if(node.getPriorityNumber() == 0) {
            packetHeap.remove();
            transferTime = (node.getFileSize() * megaBitsValue) / transferSpeed;
            zeroTotalSum += transferTime;
            zeroCounter++;
        }
        node = packetHeap.peek();
    }

    sevenAverage = sevenTotalSum / sevenCounter;
    sixAverage = sixTotalSum / sixCounter;
    fiveAverage = fiveTotalSum / fiveCounter;
    fourAverage = fourTotalSum / fourCounter;
    threeAverage = threeTotalSum / threeCounter;
    twoAverage = twoTotalSum / twoCounter;
    oneAverage = oneTotalSum / oneCounter;
    zeroAverage = zeroTotalSum / zeroCounter;

    cout << "Amount of time it takes priority level 7 takes to transfer packets is: " << fixed << setprecision(3) << sevenAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 6 takes to transfer packets is: " << fixed << setprecision(3) << sixAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 5 takes to transfer packets is: " << fixed << setprecision(3) << fiveAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 4 takes to transfer packets is: " << fixed << setprecision(3) << fourAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 3 takes to transfer packets is: " << fixed << setprecision(3) << threeAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 2 takes to transfer packets is: " << fixed << setprecision(3) << twoAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 1 takes to transfer packets is: " << fixed << setprecision(3) << oneAverage << " seconds" << endl;
    cout << "Amount of time it takes priority level 0 takes to transfer packets is: " << fixed << setprecision(3) << zeroAverage << " seconds" << endl;



    //**5. display total amount of time to transfer all packets***
    double totalTime = sevenTotalSum + sixTotalSum + fiveTotalSum + fourTotalSum +
                       threeTotalSum + twoTotalSum + oneTotalSum + zeroTotalSum;

    cout << "The amount of time to transfer all packets: " << totalTime << " seconds" << endl;
    */

    return 0;
}

/*
void dequeue(MaxHeap<Packet> packetHeap) {

}
/


/
void buildHeap(MaxHeap<Packet> packetHeap) {
}
/



/
void readFile(MaxHeap<Packet> packetHeap) {
    ifstream infile;
    string line;


    //infile.open("packets.csv");


    if(!infile.is_open()) {
        cout << "No file found..." << endl;
        exit(0);
    }



    while(getline(infile, line)) {
        packetHeap.add(line);
    }

}
*/
