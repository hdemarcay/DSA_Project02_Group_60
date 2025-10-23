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
    string vin; // unique vehicle number
    string county; // county the car is in
    string city; // city the car is in
    string postalCode; // postal code the car is registered in
    string year; // year of model
    string make; // car make
    string model; // car model
    string range; // electric range
    string id; // vehicle ID
    string tract; // 2020 Census Tract

    string EV; // Electric Vehicle Type
    string CAFV; // Clean Alternative Fuel Vehicle (CAFV) Eligibility
    string MSRP; // Base MSRP
    string ld; // Legislative District
    string location; // x and y location
    string EU; // Electric Utility

    // Skipped data for State since all the same

    Node* left;
    Node* right;

    // node constructor
    Node(string vin, string county, string city, string postalCode, string year, string make, string model, string range, string id, string tract, string EV, string CAFV, string MSRP, string ld, string location, string EU) {
        this->left = nullptr;
        this->right = nullptr;

        this->vin = vin;
        this->county = county;
        this->city = city;
        this->postalCode = postalCode;
        this->year = year;
        this->make = make;
        this->model = model;
        this->range = range;
        this->id = id;
        this->tract = tract;
        this->EV = EV;
        this->CAFV = CAFV;
        this->MSRP = MSRP;
        this->ld = ld;
        this->location = location;
        this->EU = EU;
    }

    // overloaded == operator
    bool operator==(const Node& other) const {
        // once we decide which we want to use, we can just delete them from here so that it isn't considered when
        // looking for exact matches (unless that's not how it works..)
        bool vinB = this->vin == other.vin;
        bool countyB = this->county == other.county;
        bool cityB = this->city == other.city;
        bool postalCodeB = this->postalCode == other.postalCode;
        bool yearB = this->year == other.year;
        bool makeB = this->make == other.make;
        bool modelB = this->model == other.model;
        bool rangeB = this->range == other.range;
        bool idB = this->id == other.id;
        bool tractB = this->tract == other.tract;
        bool EVB = this->EV == other.EV;
        bool CAFVB = this->CAFV == other.CAFV;
        bool MSRPB = this->MSRP == other.MSRP;
        bool ldB = this->ld == other.ld;
        bool locationB = this->location == other.location;
        bool EUB = this->EU == other.EU;

        // if all the attributes are identical, then the nodes are identical :D
        return vinB && countyB && cityB && postalCodeB && yearB && makeB && modelB && rangeB && idB && tractB && EVB && CAFVB && MSRPB && ldB && locationB && EUB;
    }
};

class maxHeap {
    int heapSize = 0;
    Node* root = nullptr;

    void inOrderTraversalHelper(Node* node, bool print);
    void postOrderTraversalHelper(Node* node, bool print);
    void preOrderTraversalHelper(Node* node, bool print);

    void swapValues(Node* current, Node* parent);
    void printNode(Node* node);

    //search functions
    //Q: how specific do we want to go?
    //should I just make them for each characteristic of the noade and write a function that takes the intersection?
    //because writing all the different combinations may suck
    //**they will all return vectors :D

    //ADD STD::CLOCK

    void searchCountyHelper(Node* node, string county, vector<Node*>& matches);
    void searchCityHelper(Node* node, string city, vector<Node*>& matches);
    void searchYearHelper(Node* node, string year, vector<Node*>& matches);
    void searchMakeHelper(Node* node, string make, vector<Node*>& matches);
    void searchModelHelper(Node* node, string model, vector<Node*>& matches);

    //sus search functions
    //questionable if we keep them or not
    void searchVinHelper(Node* node, string vin, vector<Node*>& matches);
    void searchPostalCodeHelper(Node* node, string postalCode, vector<Node*>& matches);
    void searchIDHelper(Node* node, string ID, vector<Node*>& matches);
    void searchTractHelper(Node* node, string tract, vector<Node*>& matches);

    //definitive 'not doing' (I think)
    //state, EV type, CAFV eligibility, electric range, MSRP, legislative district, location?, electric utility

    vector<Node*> intersection(vector<Node*>& one, vector<Node*>& two);

    public:
		maxHeap(){ }
		void loadHeap(string csvFileName);
		void insertNode(string vin, string county, string city, string postalCode, string year, string make, string model, string range, string id, string tract, string EV, string CAFV, string MSRP, string ld, string location, string EU);

		void printInOrderTraversal();
		void printPostOrderTraversal();
		void printPreOrderTraversal();
		void inOrderTraversal();
		void postOrderTraversal();
		void preOrderTraversal();

    	//search functions that the user will "interact" with
    	vector<Node*> searchCounty(string county);
    	vector<Node*> searchCity(string city);
    	vector<Node*> searchYear(string year);
    	vector<Node*> searchMake(string make);
    	vector<Node*> searchModel(string model);

    	//maybe include, not sure yet
    	vector<Node*> searchPostalCodeHelper(string postalCode);
    	vector<Node*> searchIDHelper(string id);
    	vector<Node*> searchTractHelper(string tract);
};

#endif //MAXHEAP_H