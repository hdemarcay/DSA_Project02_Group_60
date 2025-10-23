#include <iostream>
#include <sstream>
#include <chrono>
#include "maxHeap.h"

//PLEASE CHECK TITLES

//DSA Project 02
//Group 60
//Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
//git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

int main() {

    cout << "Welcome to DSA Project 02\nDepth Versus Breath First Traversal\nCreators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi" << endl;
    cout << "Group 60\n" << endl;

    cout << "ADD PURPOSE/REAL LIFE GOAL OF PROGRAM WHY HELP PEOPLE\n" << endl;


    cout << "The data used is Electric Vehicle Population Data in Washington\n\nWhen you are ready to load the data base press enter..." << endl;
    string firstLine;
    getline(cin, firstLine);

    cout << "The loading of the nodes may take a few seconds...\n" << endl;

    maxHeap heap;
    //ADD TIME!!!!!!!!!!!!!!!!!!*******************************************************************************
    heap.loadHeap("Electric_Vehicle_Population_Data_attempting.csv");

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
            heap.printInOrderTraversal();
        }
        else if (command == "print preorder") {
            heap.printPreOrderTraversal();
        }
        else if (command == "print postorder") {
            heap.printPostOrderTraversal();
        } else if (command == "traverse inorder") {
            heap.inOrderTraversal();
        }else if (command == "traverse preorder") {
            heap.postOrderTraversal();
        } else if (command == "traverse postorder") {
            heap.preOrderTraversal();
        } else if (command == "ADD OTHER COMMANDS") {
            //TO DO:
            cout<<"ADD OTHER COMMANDS"<<endl;
        }
        else {
            cout <<"not a valid command"<<endl;
        }
    }
    return 0;
}