#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>


using namespace std;

//Define the structs Workshops and Available_Workshops.

struct Workshop {
    int start, end, duration;
    Workshop (int s, int d):start(s),duration(d),end(s+d){}
    void print(){
        cout << start << " - " << end << " (" << duration << ")";
    }
};

struct Available_Workshops {
    int n;
    vector<Workshop> workshops;
    Available_Workshops(int nn):n(nn){
        workshops.reserve(n);
    }
    void print(){
        for (int i = 0; i < n; ++i){
            cout << i << ") ";
            workshops[i].print();
            cout << endl;
        }
        cout << endl;
    }
};

Available_Workshops* initialize (int start_time[], int duration[], int n) {
    Available_Workshops *available = new Available_Workshops(n);
    for (int i = 0 ; i < n; ++i) {
        available->workshops.emplace_back(start_time[i], duration[i]);
    }
    return available;
}

bool sortWorkshops(const Workshop &a, const Workshop &b) {
    // if (a.duration == b.duration)
    //     return a.start < b.start;
    // return a.duration < b.duration;
    return a.end < b.end;
}

bool doesOverlaps(const Workshop &workshop, unordered_set<int> &busyTimes){
    for (int j = workshop.start; j < workshop.end; ++j){
        if (busyTimes.find(j) != busyTimes.end())
            return true;
    }
    return false;
}

void addWorkshop(const Workshop &workshop, unordered_set<int> &busyTimes){
    for (int j = workshop.start; j < workshop.end; ++j){
        busyTimes.insert(j);
    }
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    ptr->print();
    sort(ptr->workshops.begin(), ptr->workshops.end(), sortWorkshops);
    ptr->print();

    unordered_set<int> busyTimes;
    vector<const Workshop*> attended;

    for (int i = 0; i < ptr->n; ++i){
        const auto &workshop = ptr->workshops[i];
        bool overlaps = doesOverlaps(workshop, busyTimes);
        if (overlaps)
            continue;

        addWorkshop(workshop, busyTimes);
        attended.push_back(&workshop);
    }


    return attended.size();
}
//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
