#include "input.h"

using namespace std;

Input::Input(char array[]) {
    populateVector();
}
void Input::getInput() {
    cout << "$ ";
    cin.getline(this->input, 100);
    populateVector();
}
void Input::populateVector() {
    char* point;
    point = strtok(this->input, " ");
    while (point != nullptr) {
        VectorInput.push_back(point);
        point = strtok(nullptr, " ");
    }
    // check for hashtag
    for(int j = 0; j < this->VectorInput.size(); j++) {
        size_t findHashtag = VectorInput.at(j).find("#");
        if (findHashtag != string::npos) {
            bool quotesAroundHashtag = false;
            for (int k = j + 1; k < VectorInput.size(); k++) {
                size_t quotesAfterHash = VectorInput.at(k).find("\"");
                if (quotesAfterHash != string::npos) {
                    for (int m = k + 1; m < VectorInput.size(); m++) {
                        size_t quotePair = VectorInput.at(m).find("\"");
                        if (quotePair == string::npos) {
                            quotesAroundHashtag = true;
                            break;
                        }
                        else {
                            VectorInput.erase((VectorInput.begin()+j), (VectorInput.end()));    
                        }
                    }
                }
                else {
                    VectorInput.erase((VectorInput.begin()+j), (VectorInput.end()));
                }
            }
        }
    }
    // testing
    // for(int i = 0; i < this->VectorInput.size(); i++) {
    //     //cout << VectorInput.at(i) << endl;
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