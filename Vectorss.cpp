#include<iostream>
#include<vector>
#include<algorithm> // Add this for copy function
#include<iterator> // Add this for ostream_iterator
using namespace std;

int main() {
    int size = 5; // Set a size for vector v

    vector<int> vector_name;  // Declare an empty vector
    vector<int> v(size); // Declare a vector v with a specified size

// Capacity of vector_name
    cout << "Capacity of vector_name: " << vector_name.capacity() << endl;

// Size of vector_name
    cout << "Size of vector_name: " << vector_name.size() << endl;

// Resize vector_name
    vector_name.resize(8);
    cout << "New size of vector_name: " << vector_name.size() << endl;

// Capacity after resizing
    cout << "Capacity of vector_name after resizing: " << vector_name.capacity() << endl;

// Add elements to vector_name
    vector_name.push_back(2);
    vector_name.push_back(3);
    vector_name.push_back(4);
    vector_name.push_back(5);
// vector<string> vec = {2,3, 4, 5};
//vector_name.insert(position,element);
    vector_name.insert(vector_name.begin()+4,5);
/*
emplace() - It constructs the element in-place at the end of the vector.
emplace_back() - It constructs the element in-place before the specified position in the vector
*/



// Capacity after adding elements (on the basis of power of 2)
    cout << "Capacity of vector_name after adding elements: " << vector_name.capacity() << endl;

// Print vector_name using index
    cout << "Elements of vector_name (using index): ";
    for (int i = 0; i < vector_name.size(); i++) {
        cout << vector_name[i] << " ";
    }
    cout << endl;

// Print vector_name using copy() and ostream_iterator
    cout << "Elements of vector_name (using copy and ostream_iterator): ";
    copy(vector_name.begin(), vector_name.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
//using for each loop
cout<<"using for each loop:"<<endl;
     for (int ele:vector_name)
     {
        cout<<ele<<" ";
     }
     cout<<endl;
     

//to delete the element from the vector
    vector_name.pop_back();
// v.erase(position);
    vector_name.erase(vector_name.begin()+4);
/*
There are different methods to delete elements from a vector in C++. Some of them are:
- `pop_back()` - It removes the last element from the vector and reduces its size by one.
- `erase()` - It removes a single element or a range of elements from the vector by taking an iterator or a pair of iterators as an argument¹³.
- `clear()` - It removes all the elements from the vector and makes its size zero.
- `remove()` - It removes all the elements that are equal to a given value from the vector and returns a new end iterator.
- `remove_if()` - It removes all the elements that satisfy a given predicate from the vector and returns a new end iterator.
*/


    cout << "Elements of vector_name (using index) after deletion: ";
    for (int i = 0; i < vector_name.size(); i++) {
        cout << vector_name[i] << " ";
    }
    cout << endl;




// Capacity of vector v
    cout << "Capacity of vector v: " << v.capacity() << endl;

    return 0;
}
