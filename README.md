# DSA Project 02
COP 3530: Group 60 <br>
Creators: Holly DeMarcay, Tiana Dumitrescu, Kayla Foroughi <br>
Remote Git: https://github.com/hdemarcay/DSA_Project02_Group_60.git

## Depth Versus Breadth First Traversal
The data used is Electric Vehicle Population Data in Washington collected by the Washington State Department of Licensing, last updated in 2025.


## Welcome to the Washington Vehicle Lookup!
In order to properly differentiate, different objects are assigned certain identifiers.  We have barcodes for retail products, IP addresses for devices,
and student IDs in schools, to name a few. Having these makes the process of finding, traversing, and identifying much faster.<br><br>

Vehicles are identified through their VIN (Vehicle Identification Number). The purposes of this program is to help users find registered car information
as quickly and efficiently as possible. This could include law enforcement, government administrative companies (such as the DMV), or consumers.<br><br>

Users can simply find VINs, or return a number of VINs based off provided information. This program will allow you to search and traverse for a VIN,
search and traverse based off requirements, and do it depending on how the user specifies: depth or breadth. This way, the user can understand and use 
the most efficient method possible with our clock.<br>



## Possible Commands:
#### Note: <br>1.) Please do not add extra spaces after commands, <br>2.) Commands aren't case sensitive.

###### 1.) Print Commands - traverse and print the entire dataset  return the entire time it takes.
    Print Inorder (\"print inorder\")
    Print Preorder (\"print preorder\")
    Print Postorder (\"print postorder\")
    Print Level Order (\"print levelorder\")

###### 2.) Traversing Commands - traverse through the entire dataset and return the entire time it takes.
    Traverse Inorder (\"traverse inorder\")
    Traverse Preorder (\"traverse preorder\")
    Traverse Postorder (\"traverse postorder\")
    Traverse Level Order (\"traverse levelorder\")

###### 3.) Search Commands - can provide a VIN and be returned information registered under that specific vehicle OR provide a parameter (county, city,  postalCode, year, make, or model) and be returned VINS that fall under that parameter. Will perform both types of searches and return the time  for each for comparison purposes.
    Search vin {VIN} (i.e. \"search vin WA1E2AFY8R\")
    Search {parameter} {value} (i.e. \"search city Olympia\")

###### 4.) Intersection - can provide two parameters and will return VINs that fall under both categories.
    Intersection {parameter1} {value1} {parameter2} {value2} (i.e. \"intersection make model audi a3\")

###### To exit, you can type: done, stop, end, 0, or -1

