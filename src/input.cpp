#include "input.h"

using namespace std;

Input::Input(char array[]) {
    char copy[100];
    for(int i = 0; i < 100; i++) {
        this->input[i] = array[i];
        copy[i] = array[i];
    }   
    populateVector();
    populateConnectors(copy);
}
void Input::getInput() {
    cout << "$ ";
    cin.getline(this->input, 100);
        char copy[100];
        for(int i = 0; i < 100; i++) {
            copy[i] = input[i];
        }
        populateVector();
        populateConnectors(copy);
    // Execute* execute = new Execute();
    // int startOfCommand = 0;
    // int EndOfCommand = 0;
    // populateExecute(startOfCommand, EndOfCommand, execute);
    // cout << "Populated Execute Object, executing command(s)" << endl;
}
void Input::populateVector() {
    char* point;
    point = strtok(this->input, " ");
    while (point != nullptr) {
        VectorInput.push_back(point);
        point = strtok(nullptr, " ");
    }
    // for(int i = 0; i < this->VectorInput.size(); i++) {
    //     cout << VectorInput.at(i) << endl;
    // }
}
void Input::populateConnectors(char copy[]) {
    char* point;
    point = strtok(copy, " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-1234567890!@$%^*()@_=+[]{}:',<.>/?`~");
    while (point != nullptr) {
        Connectors.push_back(point);
        point = strtok(nullptr, " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-1234567890!@$%^*()_=+[]{}:',<.>/?`~");
    }
    // for(int i = 0; i < this->Connectors.size(); i++) {
    //     cout << Connectors.at(i) << endl;
    // }
}
string Input::at(int num) {
    return this->VectorInput.at(num);
}
string Input::ConAt(int num) {
    return this->Connectors.at(num);
}
int Input::size() {
    return this->VectorInput.size();
} 
int Input::ConSize() {
    return this->Connectors.size();
}
void Input::ConErase(int begin, int end) {
    this->Connectors.erase((Connectors.begin() + begin), (Connectors.begin() + end));
}
