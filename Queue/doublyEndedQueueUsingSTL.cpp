#include <bits/stdc++.h>
using namespace std;




int main(){

    deque<int> d;

    d.push_front(1);
    d.push_front(2);
    d.push_back(11);
    d.push_back(12);

    cout << "Front element is: " << d.front() << endl;
    cout << "Back element is: " << d.back() << endl;

    d.pop_back();

    cout << "Front element after pop from back is: " << d.front() << endl;
    cout << "Back element after pop from back is: " << d.back() << endl;

    d.pop_front();

    cout << "Front element after pop from front is: " << d.front() << endl;
    cout << "Back element after pop from front is: " << d.back() << endl;
    
    if(d.empty()){
        cout << "Double ended queue is empty." << endl;
    }
    else{
        cout << "Double ended queue is not empty." << endl;
    }
    
    return 0;
}