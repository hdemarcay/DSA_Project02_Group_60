//DSA Project 02
//Group 60
//Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
//git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

#include "maxHeap.h"
#include <fstream>

//TODO:
// - add comments better
// - add group names and titles stuff
// - add function to start reading from terminal like how many commands
// - pick what a terminal commands are
// - figure out clock time
// - figure out new search functions
// - in-order traversals
// - idea maybe a find 12th node kinda thing????
// - add other stuff we need to do
// - menu screen
// - figure out functions
// - make sure not case sensitive for commands



//In Order Traversal
void maxHeap::inOrderTraversalHelper(Node *node) {
  if (node!=nullptr) {
    inOrderTraversalHelper(node->left);
    printNode(node);
    inOrderTraversalHelper(node->right);
  }
}

//Post Order Traversal and prints all the data
void maxHeap::postOrderTraversalHelper(Node *node) {
  if (node!=nullptr) {
    postOrderTraversalHelper(node->left);
    postOrderTraversalHelper(node->right);
    printNode(node);
    cout<<endl;
  }
}

//Pre Order Traversal
void maxHeap::preOrderTraversalHelper(Node *node) {
  if (node!=nullptr) {
    printNode(node);
    preOrderTraversalHelper(node->left);
    preOrderTraversalHelper(node->right);
  }
}

//will swap all varbiles in each node
void maxHeap::swapValues(Node *current, Node *parent) {
  //stores parents values in temp variables
  string vinTemp = parent->vin;
  string countyTemp = parent->county;
  string cityTemp = parent->city;
  string postalTemp = parent->postalCode;
  string yearTemp = parent->year;
  string makeTemp = parent->make;
  string modelTemp = parent->model;
  string rangeTemp = parent->range;
  string idTemp = parent->id;
  string tractTemp = parent->tract;

  //sets parent values to current values
  parent->vin = current->vin;
  parent->county= current->county;
  parent->city =current->city;
  parent->postalCode = current->postalCode;
  parent->year = current->year;
  parent->make = current->make;
  parent->model = current->model;
  parent->range = current->range;
  parent->id = current->id;
  parent->tract = current->tract;

  //sets current to temp values
  current->vin =vinTemp;
  current->county =countyTemp;
  current->city= cityTemp;
  current->postalCode = postalTemp;
  current->year = yearTemp;
  current->make= makeTemp;
  current->model= modelTemp;
  current->range= rangeTemp;
  current->id= idTemp;
  current->tract= tractTemp;
}

//will pritn every value of the node
void maxHeap::printNode(Node *node) {
  cout<<"Vin: "<<(node->vin);
  cout<<"\tCounty: "<<(node->county);
  cout<<"\t\tCity: "<<(node->city);
  cout<<"\t\tPostal Code: "<<(node->postalCode);
  cout<<"\tYear: "<<(node->year);
  cout<<"\n\t\tMake: "<<(node->make);
  cout<<"\t\tModel: "<<(node->model);
  cout<<"\tRange: "<<(node->range);
  cout<<"\tID: "<<(node->id);
  cout<<"\tTract: "<<(node->tract);

}

//calls helper function to use root
void maxHeap::postOrderTraversal() {
  cout<<"Post Order Traversal of all elements (printing each element)"<<endl;
  postOrderTraversalHelper(root);
}

void maxHeap::preOrderTraversal() {
  cout<<"Pre Order Traversal of all elements (printing each element)"<<endl;
  preOrderTraversalHelper(root);
}

void maxHeap::inOrderTraversal() {
  cout<<"In Order Traversal of all elements (printing each element)"<<endl;
  inOrderTraversalHelper(root);
}

//Loads the Heap values into the max heap from the file
void maxHeap::loadHeap(string csvFileName) {
  int count=0;

  try {
    ifstream file(csvFileName);
    string read;
    if (!file) {
      throw runtime_error("File failed to open.");
    }

    while (getline(file, read,',') ) {

      string vin = read;
      getline(file, read, ',');
      string county = read;
      getline(file, read, ',');
      string city = read;
      getline(file, read, ',');
      string state = read;
      getline(file, read, ',');
      string postalCode = read;
      getline(file, read, ',');
      string year = read;
      getline(file, read, ',');
      string make = read;
      getline(file, read, ',');
      string model = read;
      getline(file, read, ',');
      string EV = read;
      getline(file, read, ',');
      string CAFV = read;
      getline(file, read, ',');
      string range = read;
      getline(file, read, ',');
      string MSRP = read;
      getline(file, read, ',');
      string ld = read;
      getline(file, read, ',');
      string id = read;
      getline(file, read, ',');
      string location = read;
      getline(file, read, ',');
      string EU = read;
      getline(file, read);
      string tract= read;

      /*
      cout<<"Vin: "<<vin<<endl;
      cout<<"County: "<<county<<endl;
      cout<<"City: "<<city<<endl;
      cout<<"State: "<<state<<endl;
      cout<<"PostalCode: "<<postalCode<<endl;
      cout<<"Maker: "<<make<<endl;
      cout<<"Model: "<<model<<endl;
      cout<<"Year: "<<year<<endl;
      cout<<"EV: "<<EV<<endl;
      cout<<"Range: "<<range<<endl;
      cout<<"ID: "<<id<<endl;
      cout<<"Location: "<<location<<endl;
      cout<<"Tract: "<<tract<<endl;
      */
      count++;

      //MAKE NODES AND UPDATE NODE COUNTER :) :D
      insertNode(vin, county, city, postalCode, year, make, model, range, id, tract);

    }
    file.close();
  }

  catch (std::exception& e) {
    std::cerr << "issue here"<<e.what() << std::endl;
    //std::cout<<"ISEEEUEEUEU************"<<std::endl;
  }
  cout<<"All the data has been loaded into the Max Heap.\nThere is a total of "<<count<<" nodes in the heap.\n"<<endl;

}

//adds node kinda
void maxHeap::insertNode(string vin, string county, string city, string postalCode, string year, string make,
  string model, string range, string id, string tract) {
  //make first node
  if (heapSize==0){
    root = new Node(vin, county, city, postalCode, year, make, model, range, id, tract);
    heapSize++;
    return;
  }

  //if not first element make stack to find path of adding then follow path to add element
  stack<int> path;
  int parentElement = (heapSize-1)/2;
  //print statments for de-bugging
  //cout<<heapSize<<"==>";
  //cout<<parentElement<<"\n";
  // 0 = left   and 1 = right
  while(parentElement!=0){
    if (parentElement%2==0){
      path.push(1);
    }else{
      path.push(0);
    }
    parentElement =(parentElement-1)/2;
  }


  //follows path
  Node* parent = root;
  vector<Node*> parentsInPath;
  parentsInPath.push_back(parent);
  while (!path.empty()){
    int direction = path.top();
    if (direction==0){
      parent = parent->left;
    }else{
      parent = parent->right;
    }
    parentsInPath.push_back(parent);
    path.pop();
  }
          //adds last oen
  if (heapSize%2==0){
    parent->right = new Node(vin, county, city, postalCode, year, make, model, range, id, tract);
    parentsInPath.push_back(parent->right);
  }else{
    parent->left = new Node(vin, county, city, postalCode, year, make, model, range, id, tract);
    parentsInPath.push_back(parent->left);
  }

  //now some switches time
  //then do the heapify up thing!!!!
  //like go up that path again but flip stuff :)

  //****currently sorted by vin ******
  Node* current= parentsInPath[parentsInPath.size()-1];
  for(int i = parentsInPath.size()-2; i>=0;i--){
    Node* parent = parentsInPath[i];
    //no need to swap
    if (parent->vin>current->vin){
              break;
            }
    //swap time !!!!! swaps values like in deletion of BST with 2 children
    swapValues(current, parent);

  }
  heapSize++;
}


