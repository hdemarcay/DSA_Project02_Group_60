// DSA Project 02
// Group 60
// Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
// Remote Git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

#include <iomanip>
#include <iostream>
#include <sstream>
#include "maxHeap.h"
using namespace std;

// Display startup information, including our team/project information, the
// introduction and purpose of our project, as well as data credits.
void displayStartup() {

    // Project and team information
    cout << "____________________________________________________________" << endl;
    cout << "Welcome to DSA Project 02" << endl;
    cout << "Depth Versus Breadth First Traversal" << endl;
    cout << "Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi" << endl;
    cout << "COP3530: Group 60" << endl;
    cout << "____________________________________________________________" << endl;

    // Welcome screen and purpose
    cout << "Welcome to the Washington Vehicle Lookup!" << endl << endl;
    cout << "In order to properly differentiate, different objects are assigned certain identifiers.\n"
         << "We have barcodes for retail products, IP addresses for devices, and student IDs in schools,\n"
         << "to name a few. Having these makes the process of finding, traversing, and identifying much\n"
         << "faster.)" << endl << endl;
    cout << "Vehicles are identified through their VIN (Vehicle Identification Number). The purposes of\n"
         << "this program is to help users find registered car information as quickly and efficiently\n"
         << "as possible. This could include law enforcement, government administrative companies (such\n"
         << "as the DMV), or consumers." << endl << endl;
    cout << "Users can simply find VINs, or return a number of VINs based off provided information.\n"
         << "This program will allow you to search and traverse for a VIN, search and traverse based\n"
         << "off requirements, and do it depending on how the user specifies: depth or breadth. This\n"
         << "way, the user can understand and use the most efficient method possible with our clock.\n" << endl;

    // Data credits
    cout << "The data used is Electric Vehicle Population Data in Washington collected by the Washington\n"
         << "State Department of Licensing, last updated in 2025." << endl;
}

// Display instructions related to the project, including what commands users can
// use and how they should input it.
void displayInstructions() {
    cout << "____________________________________________________________" << endl;
    cout << "Possible Commands: (You can use \"-c\" to see all the commands. " << endl;
    cout << "Note: 1.) Please do not add extra spaces after commands, 2.) Commands aren't case sensitive.\n" << endl;

    cout << "1.) Print Commands - traverse and print the entire dataset and\n"
        << "return the entire time it takes." << endl;
    cout << "\tPrint Inorder (\"print inorder\")" << endl;
    cout << "\tPrint Preorder (\"print preorder\")" << endl;
    cout << "\tPrint Postorder (\"print postorder\")" << endl;
    cout << "\tPrint Level Order (\"print levelorder\")" << endl << endl;

    cout << "2.) Traversing Commands - traverse through the entire dataset and\n"
         << "return the entire time it takes." << endl;
    cout << "\tTraverse Inorder (\"traverse inorder\")" << endl;
    cout << "\tTraverse Preorder (\"traverse preorder\")" << endl;
    cout << "\tTraverse Postorder (\"traverse postorder\")" << endl;
    cout << "\tTraverse Level Order (\"traverse levelorder\")" << endl << endl;

    cout << "3.) Search Commands - can provide a VIN and be returned information\n"
         << "registered under that specific vehicle OR provide a parameter (county,\n"
         << "city, postalCode, year, make, or model) and be returned VINs that\n"
         << "fall under that parameter. Will perform both types of searches and\n"
         << "return the time for each for comparison purposes.\n" << endl;
    cout << "\tSearch vin {VIN} (i.e. \"search vin WA1E2AFY8R\")" << endl;
    cout << "\tSearch {parameter} {value} (i.e. \"search city Olympia\")" << endl << endl;

    cout << "To exit, you can type: done, stop, end, 0, or -1" << endl << endl;
}

// Used to check if command is part of vector; used specifically
// for checking end commands.
bool contains(vector<string> &commands, const string &givenCommand) {
    for (string &command : commands) {
        if (command == givenCommand) {
            return true;
        }
    }
    return false;
}

int main() {
    displayStartup();
    displayInstructions();

    cout << "When you are ready to load the data base press enter..." << endl;
    string firstLine;
    getline(cin, firstLine);
    cout << "The loading of the nodes may take a few seconds...\n" << endl;

    // Loads the heap and measures the time before and after loading the heap.
    maxHeap heap;
    Clock::time_point beforeLoad = Clock::now();
    heap.loadHeap("Electric_Vehicle_Population_Data_attempting.csv");

    Clock::time_point afterLoad = Clock::now();
    Duration loadTime = chrono::duration_cast<Duration>(afterLoad - beforeLoad);
    cout << "It took "<< setprecision(3) << loadTime.count() << " seconds to load the data." << endl;

    string command = "";
    vector<string> exitCommands = {"end", "stop", "done", "-1", "0", " "};
    while (!contains(exitCommands, command)) {

        cout << "\nWhat would you like to do? (to show commands type -c or commands)" << endl;

        string line;
        getline(cin, line);
        istringstream in(line);

        string command;
        getline(in, command, ' ');

        // Make command lower case
        for (char &c : command) {
            c = tolower(c);
        }

        // Display the instructions/commands again
        if (command == "-c" || command == "commands") {
            displayInstructions();
        }

        // If an exit command is provided, continue to exit the loop
        if (contains(exitCommands, command)) {
            break;
        }

        // -------------- Printing Commands --------------
        if (command == "print") {

            string type;
            getline(in, type);
            for (char &c : type) {
                c = tolower(c);
            }
            string printTime = "";

            if (type == "inorder") {
                // Gets time before function called
                Clock::time_point start = Clock::now();
                heap.printInOrderTraversal();
                // Find the total time
                heap.findTime(start,printTime);
                cout << printTime << "print inorder!" << endl;
            }

            else if (type == "preorder") {
                Clock::time_point start = Clock::now();
                heap.printPreOrderTraversal();
                heap.findTime(start,printTime);
                cout << printTime << "print preorder!" << endl;
            }

            else if (type == "postorder") {
                Clock::time_point start = Clock::now();
                heap.printPostOrderTraversal();
                heap.findTime(start,printTime);
                cout << printTime << "print postorder!" << endl;
            }
        }

        // -------------- Traversing Commands --------------
        if (command == "traverse") {

            string type;
            getline(in, type);
            for (char &c : type) {
                c = tolower(c);
            }
            string printTraverse;

            cout << "This might take a few seconds...\n" << endl;
            if (type == "inorder") {
                Clock::time_point start = Clock::now();
                heap.inOrderTraversal();
                heap.findTime(start,printTraverse);
                cout << printTraverse << "traverse inorder!" << endl;
            }

            else if (type == "preorder") {
                Clock::time_point start = Clock::now();
                heap.preOrderTraversal();
                heap.findTime(start,printTraverse);
                cout <<printTraverse<< "traverse preorder!" << endl;
            }

            else if (type == "postorder") {
                Clock::time_point start = Clock::now();
                heap.postOrderTraversal();
                heap.findTime(start,printTraverse);
                cout <<printTraverse<< "traverse postorder!" << endl;
            }

            else if (type == "levelorder") {
                Clock::time_point start = Clock::now();
                heap.levelOrderTraversal();
                heap.findTime(start,printTraverse);
                cout <<printTraverse<< "traverse levelorder!" << endl;
            }
        }

        // -------------- Search Commands --------------
        // Possible parameter searches are county, city, postal code, year, make, and model
        else if (command == "search") {

            string parameter;
            getline(in, parameter, ' ');
            for (char &c : parameter) {
                c = tolower(c);
            }

            string value;
            getline(in, value, ' ');
            for (char &c : value) {
                c = tolower(c);
            }

            Duration depthTime;
            Duration breadthTime;
            string depthTimeString="";
            string breadthTimeString="";
            bool validParameter = true;
            cout << "This might take a few seconds...\n" << endl;
            if (parameter == "vin") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchVinDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchVinBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "That VIN does not exist." << endl;
                }
                else {
                    Node* node = matchesDFS[0];
                    cout << "Vin: " << node->vin << endl;
                    cout << "County: " << node->county << endl;
                    cout << "City: " << node->city << endl;
                    cout << "Postal Code: " << node->postalCode << endl;
                    cout << "Year: " << node->year << endl;
                    cout << "Make: " << node->make << endl;
                    cout << "Model: " << node->model << endl;
                }
            }

            else if (parameter == "county") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchCountyDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchCountyBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs within that county." << endl;
                }
                else {
                    cout << "VINs within that county:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else if (parameter == "city") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchCityDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchCityBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs within that city." << endl;
                }
                else {
                    cout << "VINs within that city:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else if (parameter == "postalcode") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchPostalCodeDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchPostalCodeBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs within that postal code." << endl;
                }
                else {
                    cout << "VINs within that postal code:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else if (parameter == "year") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchYearDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchYearBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs whose model is from that year." << endl;
                }
                else {
                    cout << "VINs whose model is from that year:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else if (parameter == "make") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchMakeDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchMakeBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs of that make." << endl;
                }
                else {
                    cout << "VINs of that make:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else if (parameter == "model") {
                // Depth first search
                Clock::time_point start = Clock::now();
                vector<Node*> matchesDFS = heap.searchModelDFS(value);
                depthTime = heap.findTime(start,depthTimeString);
                cout << "depth first search!" << endl;

                // Breadth first search
                start = Clock::now();
                vector<Node*> matchesBFS = heap.searchModelBFS(value);
                breadthTime = heap.findTime(start,breadthTimeString);
                cout << "breadth first search!" << endl;

                if (matchesDFS.size() == 0) {
                    cout << "No VINs of that model." << endl;
                }
                else {
                    cout << "VINs of that model:" << endl;
                    for (int i = 0; i < matchesDFS.size()-1; i++) {
                        cout << matchesDFS[i]->vin + ", ";
                    }
                    cout << matchesDFS[matchesDFS.size()-1]->vin;
                    cout << endl;
                    cout << endl;
                    cout << "Number of matches: " << matchesDFS.size() << endl;
                }
            }

            else {
                validParameter = false;
                cout << "Not a valid parameter. Possible parameter options are\n"
                     << "vin, county, city, postalcode, year, make, and model." << endl;
            }

            if (validParameter == true) {
                // Final comparison
                cout << "\n"<<depthTimeString << "search DSF!" << endl;
                cout << breadthTimeString << "search BSF!" << endl;

                if (breadthTime > depthTime) {
                    cout << "Breadth took " << breadthTime.count() - depthTime.count() << " longer than depth!" << endl;
                }
                else if (breadthTime < depthTime) {
                    cout << "Depth took " << depthTime.count() - breadthTime.count() << " longer than breadth!" << endl;
                }
                else {
                    cout << "Depth and breadth took the same amount!" << endl;
                }
            }
        }

        else {
            cout << "Not a valid command. Type \"-c\" to see all valid commands." << endl;
        }
    }
    return 0;
}