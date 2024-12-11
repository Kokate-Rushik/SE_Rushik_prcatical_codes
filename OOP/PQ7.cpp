#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Creating a map where the key is a state name and the value is the population
    map<string, long long> statePopulation;

    // Initializing the map with some example data (Indian states and their populations)
    statePopulation["Uttar Pradesh"] = 199812341;
    statePopulation["Maharashtra"] = 112374333;
    statePopulation["Bihar"] = 104099452;
    statePopulation["West Bengal"] = 91276115;
    statePopulation["Tamil Nadu"] = 72147030;
    statePopulation["Rajasthan"] = 68548437;
    statePopulation["Karnataka"] = 61095297;
    statePopulation["Gujarat"] = 60439692;
    statePopulation["Andhra Pradesh"] = 49386799;
    statePopulation["Madhya Pradesh"] = 72626809;

    // Prompting the user to enter the name of a state
    string state;
    cout << "Enter the name of an state: ";
    getline(cin, state);  // To allow multi-word state names

    // Searching the state in the map and displaying the population
    map<string, long long>::iterator it = statePopulation.find(state);
    if (it != statePopulation.end()) {
        cout << "The population of " << state << " is " << it->second << " people." << endl;
    } else {
        cout << "State not found in the map." << endl;
    }

    return 0;
}

