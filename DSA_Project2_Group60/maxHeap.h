//DSA Project 02
//Group 60
//Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
//git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <sstream>

#include <stack>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string vin; //unique vehicle number
    string county; //county car is in
    string city; //city car is in
    string postalCode; //postal code registered in
    string year; //year of model
    string make; //car make
    string model; //car model
    string range; //Electric Range
    string id; //Vehicle ID
    string tract; // 2020 Census Tract

    string EV; //Electric Vehicle Type
    string CAFV; //Clean Alternative Fuel Vehicle (CAFV) Eligibility
    string MSRP; // Base MSRP
    string ld; //Legislative District
    string location; //x and y location
    string EU; //Electric Utility

    //Skipped data for State since all the same, Also skipped Vehicle EV type, CAFV, BASe MSRP,
    //Legislative District, location, and Eletric Utility

    Node* left;
    Node* right;

    //constructor
    Node(string vin,string county,string city,string postalCode,string year,string make,string model,string range,string id,string tract,string EV, string CAFV, string MSRP, string ld, string location,string EU) {
        this->left = nullptr;
        this->right = nullptr;

        this->vin = vin;
        this->county=county;
        this->city=city;
        this->postalCode=postalCode;
        this->year=year;
        this->make=make;
        this->model= model;
        this->range=range;
        this->id=id;
        this->tract=tract;
        this->EV= EV;
        this->CAFV=CAFV;
        this->MSRP=MSRP;
        this->ld=ld;
        this->location=location;
        this->EU=EU;
    }
};

class maxHeap {
    int heapSize = 0;
    Node* root = nullptr;

    void inOrderTraversalHelper(Node *node);
    void postOrderTraversalHelper(Node *node);
    void preOrderTraversalHelper(Node *node);
    void swapValues(Node *current, Node *parent);
    void printNode(Node *node);

    public:
        maxHeap(){ }
        void loadHeap(string csvFileName);
        void insertNode(string vin,string county,string city,string postalCode,string year,string make,string model,string range,string id,string tract,string EV, string CAFV, string MSRP, string ld, string location,string EU);

        void inOrderTraversal();
        void postOrderTraversal();
        void preOrderTraversal();

};



#endif //MAXHEAP_H
