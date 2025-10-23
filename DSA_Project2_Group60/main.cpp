#include <iomanip>
#include <iostream>
#include <sstream>
#include "maxHeap.h"

//PLEASE CHECK TITLES

//DSA Project 02
//Group 60
//Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
//git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

int main() {

    cout << "Welcome to DSA Project 02\nDepth Versus Breath First Traversal\nCreators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi" << endl;
    cout << "Group 60\n" << endl;

    //thoughts? also, DO NOT REMOVE THE EXTRA SPACES AFTER 'TO', I added it to make it prettier when it prints :D
    cout << "Our car lookup helps users find their dream car as quickly and efficiently as possible. In today's world, speed matters,"
            "and we make finding the right car seamless. This benefits both consumers and businesses by matching the right cars to   "
            "the right buyers and reducing returns due to dissatisfaction." << endl;


    cout << "The data used is Electric Vehicle Population Data in Washington\n\nWhen you are ready to load the data base press enter..." << endl;
    string firstLine;
    getline(cin, firstLine);

    cout << "The loading of the nodes may take a few seconds...\n" << endl;

    maxHeap heap;
    //ADD TIME!!!!!!!!!!!!!!!!!!*******************************************************************************
    chrono::steady_clock::time_point beforeLoad = chrono::steady_clock::now();
    heap.loadHeap("Electric_Vehicle_Population_Data_attempting.csv");
    chrono::steady_clock::time_point afterLoad = chrono::steady_clock::now();
    chrono::duration<double> loadTime = chrono::duration_cast<chrono::duration<double>>(afterLoad - beforeLoad);
    cout << "It took "<< std::setprecision(3) << loadTime.count() << " seconds to load the data\n" << endl;

    //timer.restart();
    //timer.getElapsedTime();
    //std::Clock timer;

    //dd intructions and other rules stuff here like any key to tart press
    string command = "";
    cout << "Please do not add extra spaces at the end of a command but title case does not matter. \nIf you are confused by commands please open the command menu" << endl;
    while (command != "end" && command != "stop" && command != "done" && command != "-1" && command != "0" && command != " ") {
        cout << "\nWhat would you liked to do? (to show commands type c or commands)" << endl;
        getline(cin, command);
        //makes commands all lower case
        for (char &c : command) {
            c = tolower(c);
        }


        if (command == "c"||command=="commands") {
            //print commands
            cout << "\nCommands: " << endl;
            cout << "- print inorder" << endl;
            cout << "- print preorder" << endl;
            cout << "- print postorder" << endl;
            cout << "- traverse inorder" << endl;
            cout << "- traverse preorder" << endl;
            cout << "- traverse postorder" << endl;
            cout << "- ADD EVERYTHING ELSE PLEASE" << endl;
            cout << "- to exit type: done, stop, end, 0, or -1" << endl;
        }
        if (command == "end" || command == "stop" || command == "done" || command == "-1" || command == "0" || command == " ") {
            continue;
        }
        if (command == "print inorder") {
            //gets time before function called
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.printInOrderTraversal();
            //find the tota; time
            heap.findTime(start);
            cout << " print inorder\n" << endl;
        }
        else if (command == "print preorder") {
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.printPreOrderTraversal();
            heap.findTime(start);
            cout << " print preorder\n" << endl;
        }
        else if (command == "print postorder") {
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.printPostOrderTraversal();
            heap.findTime(start);
            cout << " print postorder\n" << endl;

        } else if (command == "traverse inorder") {
            cout << "this might take a few seconds :)" << endl;
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.inOrderTraversal();
            heap.findTime(start);
            cout << " traverse inorder\n" << endl;

        }else if (command == "traverse preorder") {
            cout << "this might take a few seconds :)" << endl;
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.postOrderTraversal();
            heap.findTime(start);
            cout << " traverse preorder\n" << endl;

        } else if (command == "traverse postorder") {
            cout<<"this might take a few seconds :)"<<endl;
            chrono::steady_clock::time_point start = chrono::steady_clock::now();
            heap.preOrderTraversal();
            heap.findTime(start);
            cout << " traverse postorder\n" << endl;
        } else if (command == "ADD OTHER COMMANDS") {
            //TO DO:
            cout << "ADD OTHER COMMANDS" << endl;
            //like search
            // how many categories? what category
        }
        else {
            cout << "not a valid command" << endl;
        }
    }
    return 0;
}