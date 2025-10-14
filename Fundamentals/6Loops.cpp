#include <iostream>
using namespace std;

int main() {
  
    cout << "Do while loop" << endl;
  	// Initialization
  	int i = 1;
  
  	// while loop that starts with i = 1 and ends
  	// when i is greater than 5.
     do {
        cout << i << " ";
      
      	// Updation
      	i++;
    }while (i <= 5);
    cout << endl;

    cout << "While loop" << endl;
    // Initialization
  	int j = 1;
  
  	// while loop that starts with i = 1 and ends
  	// when i is greater than 5.
    while (j <= 5) {
        cout << j << " ";
      
      	// Updation
      	j++;
    }
    cout << endl;

    cout << "For loop" << endl;
    // For loop that starts with i = 1 and ends
  	// when i is greater than 5.
      for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> arr = {1, 2, 3, 4, 5};
    
    // By value: works on a copy, modifications won't affect the original
    cout << "Iterating by value" << endl;
    for(auto it : arr){
        cout << it <<" ";
    }
    cout<< endl;
    
    // By reference: you can modify elements directly
    cout << "Iterating with reference" << endl;
    for(auto &it : arr){
        cout << it << " ";
    }
    cout<<endl;

    return 0;
}

// Quiz

// Default case is not mandatory in a switch statement. True

// Can we use string inside switch statement?
// No — you can’t switch on std::string (or std::string_view).
// switch requires an integral or enum expression (e.g., int, char, or an enum). std::string is a class type with no integral conversion.