// DSA Project 02
// Group 60
// Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi
// git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

#include "maxHeap.h"
#include <iomanip>
#include <queue>

void toLower(string &value) {
    for (char &c : value) {
        c = tolower(c);
    }
}

// -------------- Node/Heap Related --------------

// Performs a swap between all variables in two nodes
void maxHeap::swapValues(Node* current, Node* parent) {
    // Stores parents values in temp variables
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
    string EVtemp = parent->EV;
    string CAFVtemp = parent->CAFV;
    string MSRPtemp = parent->MSRP;
    string ldTemp = parent->ld;
    string locationTemp = parent->location;
    string EUtemp = parent->EU;

    // Sets parent values to current values
    parent->vin = current->vin;
    parent->county = current->county;
    parent->city = current->city;
    parent->postalCode = current->postalCode;
    parent->year = current->year;
    parent->make = current->make;
    parent->model = current->model;
    parent->range = current->range;
    parent->id = current->id;
    parent->tract = current->tract;
    parent->EV = current->EV;
    parent->CAFV = current->CAFV;
    parent->MSRP = current->MSRP;
    parent->ld = current->ld;
    parent->location = current->location;
    parent->EU = current->EU;


    // Sets current to temp values
    current->vin = vinTemp;
    current->county = countyTemp;
    current->city = cityTemp;
    current->postalCode = postalTemp;
    current->year = yearTemp;
    current->make = makeTemp;
    current->model = modelTemp;
    current->range = rangeTemp;
    current->id = idTemp;
    current->tract = tractTemp;
    current->EV = EVtemp;
    current->CAFV = CAFVtemp;
    current->MSRP = MSRPtemp;
    current->ld = ldTemp;
    current->location = locationTemp;
    current->EU = EUtemp;
}

// Will print every value of the node
void maxHeap::printNode(Node *node) {
    cout << "\nVin: " << node->vin;
    cout << "\tCounty: " << node->county;
    cout << "\t\tCity: " << node->city;
    cout << "\t\tPostal Code: " << node->postalCode;
    cout << "\tYear: " << node->year;
    cout << "\n\t\tMake: " << node->make;
    cout << "\t\tModel: " << node->model;
    cout << "\tRange: " << node->range;
    cout << "\tID: " << node->id;
    cout << "\tTract: " << node->tract;
}


// Loads the Heap values into the max heap from the file
void maxHeap::loadHeap(string csvFileName) {
    int count = 0;

    try {
        ifstream file(csvFileName);
        string read;
        if (!file) {
        throw runtime_error("File failed to open.");
        }

        while (getline(file, read,',') ) {

            string vin = read;
            toLower(vin);

            getline(file, read, ',');
            string county = read;
            toLower(county);

            getline(file, read, ',');
            string city = read;
            toLower(city);

            getline(file, read, ',');
            string state = read;
            toLower(state);

            getline(file, read, ',');
            string postalCode = read;
            toLower(postalCode);

            getline(file, read, ',');
            string year = read;
            toLower(year);

            getline(file, read, ',');
            string make = read;
            toLower(make);

            getline(file, read, ',');
            string model = read;
            getline(file, read, ',');
            toLower(model);

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

            string tract = read;

            // Update node counter and make nodes
            count++;
            insertNode(vin, county, city, postalCode, year, make, model, range, id, tract,EV,CAFV,MSRP,ld,location,EU);
        }
        file.close();
    }

  catch (std::exception& e) {
    std::cerr << "issue here"<<e.what() << std::endl;
  }
  cout << "All the data has been loaded into the Max Heap.\nThere is a total of " << count << " nodes in the heap." << endl;

}

// Will be used when filtering by 2 or more conditions
// It will take the vectors from the search functions and take the intersection of them
vector<Node*> maxHeap::intersection(vector<Node*>& one, vector<Node*>& two) {
    vector<Node*> result;
    for (int i = 0; i < one.size(); i++) {
        for (int j = 0; j < two.size(); j++) {
            if (one[i] == two[j]) {
                result.push_back(one[i]);
                break;
            }
        }
    }
    return result;
}

// Adds node kinda
void maxHeap::insertNode(string vin, string county, string city, string postalCode, string year, string make, string model, string range, string id, string tract,string EV, string CAFV, string MSRP, string ld, string location, string EU) {
  // Make first node
  if (heapSize == 0){
    root = new Node(vin, county, city, postalCode, year, make, model, range, id, tract, EV, CAFV, MSRP, ld, location, EU);
    heapSize++;
    return;
  }

  //If not first element make stack to find path of adding then follow path to add element
  stack<int> path;
  int parentElement = (heapSize - 1) / 2;
  while(parentElement != 0){
    if (parentElement % 2 == 0){
      path.push(1);
    }else{
      path.push(0);
    }
    parentElement =(parentElement - 1) / 2;
  }


  //follows path
  Node* parent = root;
  vector<Node*> parentsInPath;
  parentsInPath.push_back(parent);
  while (!path.empty()) {
    int direction = path.top();
    if (direction == 0) {
      parent = parent->left;
    } else {
      parent = parent->right;
    }
    parentsInPath.push_back(parent);
    path.pop();
  }
  //adds last oen
  if (heapSize % 2 == 0) {
    parent->right = new Node(vin, county, city, postalCode, year, make, model, range, id, tract, EV, CAFV, MSRP, ld, location, EU);
    parentsInPath.push_back(parent->right);
  } else{
    parent->left = new Node(vin, county, city, postalCode, year, make, model, range, id, tract, EV, CAFV, MSRP, ld, location, EU);
    parentsInPath.push_back(parent->left);
  }

  // Currently sorted by vin
  Node* current = parentsInPath[parentsInPath.size()-1];
  for(int i = parentsInPath.size() - 2; i >= 0; i--) {
    Node* parent = parentsInPath[i];
    // No need to swap
    if (parent->vin > current->vin){
    break;
    }
    //  Swap time! Swaps values like in deletion of BST with 2 children
    swapValues(current, parent);
  }
  heapSize++;
}

// Will print only the characteristics you want based on input number.
void maxHeap::printNode(Node* node, int num) {
    cout<<endl;
    // Will have number in the 10th spot if you want vin
    if (num / 1000000000 != 0) {
        cout << "Vin: " << node->vin;
    }
    num = num % 1000000000;
    // Will have number in the 9th spot if you want county
    if (num / 100000000 != 0) {
        cout << "\tCounty: " << node->county;
    }
    num = num % 100000000;
    // Will have number in the 8th spot if you want city
    if (num / 10000000 != 0) {
        cout << "\t\tCity: " << node->city;
    }
    num = num % 10000000;
    // Will have number in the 7th spot if u want postalCode
    if (num / 1000000 != 0) {
        cout << "\t\tPostal Code: " << node->postalCode;
    }
    num = num % 1000000;
    // Will have number in the 6th spot if u want year
    if (num / 100000 != 0) {
        cout << "\tYear: " << node->year;
    }
    // Will have number in the 5th spot if u want make
    num = num % 100000;
    if (num / 10000 != 0) {
        cout << "\n\t\tMake: " << node->make;
    }
    num = num % 10000;
    // Will have number in the 4th spot if u want model
    if (num / 1000 != 0) {
        cout << "\t\tModel: " << node->model;
    }
    num = num % 1000;
    // Will have number in the 3rd spot if u want range
    if (num / 100 != 0) {
        cout << "\tRange: " << node->range;
    }
    num = num % 100;
    // Will have number in the 2nd spot if u want id
    if (num / 10 != 0) {
        cout << "\tID: " << node->id;
    }
    num = num % 10;
    // Will have number in the 1rst spot if u want tract
    if (num != 0) {
        cout << "\tTract: " << node->tract;
    }

}

// Time
Duration maxHeap::findTime(Clock::time_point before,string &timeString) {
    Clock::time_point after = Clock::now();
    Duration funcTime = chrono::duration_cast<Duration>(after - before);
    stringstream time;
    time << setprecision(3) << funcTime.count();
    timeString = "It took " + time.str() + " seconds to ";
    return funcTime;

}

// -------------- Traversal Helpers --------------

// In-Order Traversal Helper (prints if specified)
void maxHeap::inOrderTraversalHelper(Node* node, bool print) {
    if (node != nullptr) {
        inOrderTraversalHelper(node -> left, print);
        // Will print only the VIN
        if (print) {
            printNode(node);
        }
        inOrderTraversalHelper(node -> right, print);
    }
}

// Post-Order Traversal Helper (prints if specified)
void maxHeap::postOrderTraversalHelper(Node* node, bool print) {
    if (node != nullptr) {
        postOrderTraversalHelper(node->left, print);
        postOrderTraversalHelper(node->right, print);
        if (print) {
            printNode(node);
        }
    }
}

// Pre-Order Traversal Helper (prints if specified)
void maxHeap::preOrderTraversalHelper(Node* node, bool print) {
  if (node != nullptr) {
      if (print) {
          printNode(node);
      }
      preOrderTraversalHelper(node->left,print);
      preOrderTraversalHelper(node->right,print);
  }
}

// Level-Order Traversal Helper (prints if specified)
void maxHeap::levelOrderTraversalHelper(Node* node, bool print) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    while (!q.empty()) {
        Node* curr = q.front();
        if (print) {
            printNode(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

// -------------- Accessible Traversals --------------

// Calls helper function to use root
void maxHeap::inOrderTraversal() {
    cout << "In Order Traversal of all elements (no printing)" << endl;
    inOrderTraversalHelper(root, false);
}

// Calls helper function to use root
void maxHeap::postOrderTraversal() {
    cout << "Post Order Traversal of all elements (no printing)" << endl;
    postOrderTraversalHelper(root, false);
}

// Calls helper function to use root
void maxHeap::preOrderTraversal() {
    cout << "Pre Order Traversal of all elements (no printing)" << endl;
    preOrderTraversalHelper(root, false);
}

// Calls helper function to use root
void maxHeap::levelOrderTraversal() {
    cout << "Level Order Traversal of all elements (no printing)" << endl;
    levelOrderTraversalHelper(root, false);
}

// -------------- Accessible Prints --------------

// Calls helper function to use root
void maxHeap::printPostOrderTraversal() {
    cout << "Post Order Traversal of all elements (printing each element!)" << endl;
    postOrderTraversalHelper(root, true);
}

// Calls helper function to use root
void maxHeap::printPreOrderTraversal() {
    cout << "Pre Order Traversal of all elements (printing each element!)" << endl;
    preOrderTraversalHelper(root, true);
}

// Calls helper function to use root
void maxHeap::printInOrderTraversal() {
    cout << "In Order Traversal of all elements (printing each element!)" << endl;
    inOrderTraversalHelper(root, true);
}

// Calls helper function to use root
void maxHeap::printLevelOrderTraversal() {
    cout << "Level Order Traversal of all elements (printing each element!)" << endl;
    levelOrderTraversalHelper(root, true);
}

// -------------- DFS Search Helpers --------------

// Searches for nodes with matching vin number
void maxHeap::searchVinHelperDFS(Node* node, string& vin, vector<Node*>& matches) {
    if (!node) {
        return;
    }
    if (node->vin == vin) {
        matches.push_back(node);
    }
    searchVinHelperDFS(node->left, vin, matches);
    searchVinHelperDFS(node->right, vin, matches);
}

// Searches for nodes with matching county
void maxHeap::searchCountyHelperDFS(Node* node, string& county, vector<Node*>& matches) {
    if (!node) {
      return;
   }
   if (node->county == county) {
      matches.push_back(node);
   }
   searchCountyHelperDFS(node->left, county, matches);
   searchCountyHelperDFS(node->right, county, matches);
}

// Searches for nodes with matching city
void maxHeap::searchCityHelperDFS(Node* node, string& city, vector<Node*>& matches) {
   if (!node) {
      return;
   }
   if (node->city == city) {
      matches.push_back(node);
   }
   searchCityHelperDFS(node->left, city, matches);
   searchCityHelperDFS(node->right, city, matches);
}

// Searches for nodes with matching postal code
void maxHeap::searchPostalCodeHelperDFS(Node* node, string& postalCode, vector<Node*>& matches) {
    if (!node) {
        return;
    }
    if (node->postalCode == postalCode) {
        matches.push_back(node);
    }
    searchPostalCodeHelperDFS(node->left, postalCode, matches);
    searchPostalCodeHelperDFS(node->right, postalCode, matches);
}

// Searches for nodes with matching year
void maxHeap::searchYearHelperDFS(Node* node, string& year, vector<Node*>& matches) {
   if (!node) {
      return;
   }
   if (node->year == year) {
      matches.push_back(node);
   }
   searchYearHelperDFS(node->left, year, matches);
   searchYearHelperDFS(node->right, year, matches);
}

// Searches for nodes with matching make
void maxHeap::searchMakeHelperDFS(Node* node, string& make, vector<Node*>& matches) {
   if (!node) {
      return;
   }
   if (node->make == make) {
      matches.push_back(node);
   }
   searchMakeHelperDFS(node->left, make, matches);
   searchMakeHelperDFS(node->right, make, matches);
}

// Searches for nodes with matching model
void maxHeap::searchModelHelperDFS(Node* node, string& model, vector<Node*>& matches) {
   if (!node) {
      return;
   }
   if (node->model == model) {
      matches.push_back(node);
   }
   searchModelHelperDFS(node->left, model, matches);
   searchModelHelperDFS(node->right, model, matches);
}

// -------------- Accessible DFS Searches --------------
// Search functions the user "works" with

vector<Node*> maxHeap::searchVinDFS(string vin) {
    vector<Node*> result;
    searchVinHelperDFS(root, vin, result);
    return result;
}

vector<Node*> maxHeap::searchCountyDFS(string county) {
    vector<Node*> result;
    searchCountyHelperDFS(root, county, result);
    return result;
}

vector<Node*> maxHeap::searchCityDFS(string city) {
    vector<Node*> result;
    searchCityHelperDFS(root, city, result);
    return result;
}

vector<Node*> maxHeap::searchPostalCodeDFS(string postalCode) {
    vector<Node*> result;
    searchPostalCodeHelperDFS(root, postalCode, result);
    return result;
}

vector<Node*> maxHeap::searchYearDFS(string year) {
    vector<Node*> result;
    searchYearHelperDFS(root, year, result);
    return result;
}

vector<Node*> maxHeap::searchMakeDFS(string make) {
    vector<Node*> result;
    searchMakeHelperDFS(root, make, result);
    return result;
}

vector<Node*> maxHeap::searchModelDFS(string model) {
    vector<Node*> result;
    searchModelHelperDFS(root, model, result);
    return result;
}

// -------------- BFS Search Helpers --------------

void maxHeap::searchVinHelperBFS(Node* node, string& vin, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->vin == vin) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchCountyHelperBFS(Node* node, string& county, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->county == county) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchCityHelperBFS(Node* node, string& city, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->city == city) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchPostalCodeHelperBFS(Node* node, string& postalCode, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->postalCode == postalCode) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchYearHelperBFS(Node* node, string& city, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->city == city) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchMakeHelperBFS(Node* node, string& make, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->make == make) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

void maxHeap::searchModelHelperBFS(Node* node, string& model, vector<Node*>& matches) {
    // If reached end of heap, return
    if (node == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
        Node* curr = q.front();
        if (curr->model == model) {
            matches.push_back(curr);
        }
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        q.pop();
    }
}

// -------------- Accessible BFS Searches --------------
// Search functions the user "works" with

vector<Node *> maxHeap::searchVinBFS(string vin) {
    vector<Node*> result;
    searchVinHelperBFS(root, vin, result);
    return result;
}

vector<Node*> maxHeap::searchCountyBFS(string county) {
    vector<Node*> result;
    searchCountyHelperBFS(root, county, result);
    return result;
}

vector<Node*> maxHeap::searchCityBFS(string city) {
    vector<Node*> result;
    searchCityHelperBFS(root, city, result);
    return result;
}

vector<Node*> maxHeap::searchPostalCodeBFS(string postalCode) {
    vector<Node*> result;
    searchPostalCodeHelperBFS(root, postalCode, result);
    return result;
}

vector<Node*> maxHeap::searchYearBFS(string year) {
    vector<Node*> result;
    searchYearHelperBFS(root, year, result);
    return result;
}

vector<Node*> maxHeap::searchMakeBFS(string make) {
    vector<Node*> result;
    searchMakeHelperBFS(root, make, result);
    return result;
}

vector<Node*> maxHeap::searchModelBFS(string model) {
    vector<Node*> result;
    searchModelHelperBFS(root, model, result);
    return result;
}