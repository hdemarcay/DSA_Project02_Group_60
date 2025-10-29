// DSA Project 02
// Group 60
// Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
// git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>

using Clock = std::chrono::steady_clock;
using Duration = std::chrono::duration<double>;
using namespace std;

struct Node {
	Node* left;
	Node* right;

    string vin; // Unique vehicle number
    string county; // County car is in
    string city; // City car is in
    string postalCode; // Postal code car is registered in
    string year; // Year of model
    string make; // Car make
    string model; // Car model
    string range; // Electric range
    string id; // Vehicle ID
    string tract; // 2020 Census Tract
    string EV; // Electric Vehicle Type
    string CAFV; // Clean Alternative Fuel Vehicle (CAFV) Eligibility
    string MSRP; // Base MSRP
    string ld; // Legislative District
    string location; // X and Y location
    string EU; // Electric Utility

    // Constructor
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

    // Overloaded == operator; Defines the equality operator for our Node class.
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

        // If all the attributes are identical, then the nodes are identical :D
        return vinB && countyB && cityB && postalCodeB && yearB && makeB && modelB && rangeB && idB && tractB && EVB && CAFVB && MSRPB && ldB && locationB && EUB;
    }
};

class maxHeap {
    int heapSize = 0;
    Node* root = nullptr;

	 void swapValues(Node* current, Node* parent);
	 void printNode(Node* node);
	 void printNode(Node* node,int Num);

    void inOrderTraversalHelper(Node* node, bool print);
    void postOrderTraversalHelper(Node* node, bool print);
    void preOrderTraversalHelper(Node* node, bool print);
	 void levelOrderTraversalHelper(Node* node, bool print);

    //search functions
    //Q: how specific do we want to go?
    //should I just make them for each characteristic of the noade and write a function that takes the intersection?
    //because writing all the different combinations may suck
    //**they will all return vectors :D

    //ADD STD::CLOCK

	 void searchVinHelperDFS(Node* node, string& vin, vector<Node*>& matches);
    void searchCountyHelperDFS(Node* node, string& county, vector<Node*>& matches);
    void searchCityHelperDFS(Node* node, string& city, vector<Node*>& matches);
	 void searchPostalCodeHelperDFS(Node* node, string& postalCode, vector<Node*>& matches);
    void searchYearHelperDFS(Node* node, string& year, vector<Node*>& matches);
    void searchMakeHelperDFS(Node* node, string& make, vector<Node*>& matches);
    void searchModelHelperDFS(Node* node, string& model, vector<Node*>& matches);

	void searchVinHelperBFS(Node* node, string& vin, vector<Node*>& matches);
	void searchCountyHelperBFS(Node* node, string& county, vector<Node*>& matches);
	void searchCityHelperBFS(Node* node, string& city, vector<Node*>& matches);
	void searchPostalCodeHelperBFS(Node* node, string& postalCode, vector<Node*>& matches);
	void searchYearHelperBFS(Node* node, string& year, vector<Node*>& matches);
	void searchMakeHelperBFS(Node* node, string& make, vector<Node*>& matches);
	void searchModelHelperBFS(Node* node, string& model, vector<Node*>& matches);

    //sus search functions
    //questionable if we keep them or not
    void searchIDHelperDFS(Node* node, string& ID, vector<Node*>& matches);
    void searchTractHelperDFS(Node* node, string& tract, vector<Node*>& matches);

    //definitive 'not doing' (I think)
    //state, EV type, CAFV eligibility, electric range, MSRP, legislative district, location?, electric utility

    vector<Node*> intersection(vector<Node*>& one, vector<Node*>& two);

    public:
		maxHeap(){}
		void loadHeap(string csvFileName);
		void insertNode(string vin, string county, string city, string postalCode, string year, string make, string model, string range, string id, string tract, string EV, string CAFV, string MSRP, string ld, string location, string EU);

		// Accessible printing functions
		void printInOrderTraversal();
      void printLevelOrderTraversal();
      void printPostOrderTraversal();
		void printPreOrderTraversal();

		// Accessible traversal functions
		void inOrderTraversal();
		void postOrderTraversal();
		void preOrderTraversal();

    void levelOrderTraversal();

    // Accessible search functions (DFS)
		vector<Node*> searchVinDFS(string vin);
    	vector<Node*> searchCountyDFS(string county);
    	vector<Node*> searchCityDFS(string city);
		vector<Node*> searchPostalCodeDFS(string postalCode);
    	vector<Node*> searchYearDFS(string year);
    	vector<Node*> searchMakeDFS(string make);
    	vector<Node*> searchModelDFS(string model);
		vector<Node*> searchIdDFS(string id);
    	vector<Node*> searchTractDFS(string tract);

		// Accessible search functions (BFS)
		vector<Node*> searchVinBFS(string vin);
		vector<Node*> searchCountyBFS(string county);
		vector<Node*> searchCityBFS(string city);
		vector<Node*> searchPostalCodeBFS(string postalCode);
		vector<Node*> searchYearBFS(string year);
		vector<Node*> searchMakeBFS(string make);
		vector<Node*> searchModelBFS(string model);
		vector<Node*> searchTractBFS(string tract);

		// ADD THIS
		void findTime(Clock::time_point before);
};

#endif //MAXHEAP_H