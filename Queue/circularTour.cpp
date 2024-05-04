#include <bits/stdc++.h>
using namespace std;

// The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};

//Function to find starting point where the truck can start to get through
//the complete circle without exhausting its petrol in between.

int circularTour(petrolPump p[],int n){

    int deficit = 0;
    int balance = 0;
    int start = 0;
    
    for(int i=0; i<n; i++) {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0) {
            start = i+1;
            deficit += balance;
            balance = 0;
        }
    }
    
    if(balance + deficit >= 0) 
        return start;
    return -1;
           
}

int main(){

    // inputs:
    // vector<int> Petrol = {4, 6, 7, 4};
    // vector<int> Distance = {6, 5, 3, 5};

    int n;
    cout << "Enter the value of n: " ;
    cin>>n;

    petrolPump p[n];
    for(int i=0;i<n;i++){
        /* This is input format:
         petrol distance
            4       6
            6       5
            7       3
            4       5
        */
        cin >> p[i].petrol >> p[i].distance;
    }

    int indexOfStartingPointOfCircularTour = circularTour(p,n);
    
    cout << "Starting index/point for circular tour is: " << indexOfStartingPointOfCircularTour << endl;
    return 0;
}


