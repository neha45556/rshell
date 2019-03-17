#include "input.h"
#include <exception>

using namespace std;

Input::Input(char array[]) {
    int leftParen = 0;
    int rightParen = 0;
    for(int i = 0; i < 100; i++) {
        this->input[i] = array[i];
        if (array[i] == '(') {
            ++leftParen;
        } 
        if (array[i] == ')') {
            ++rightParen;
        }
    }
    if (leftParen != rightParen) {
        cout << "**ERROR** Unbalanced or unexepected parenthesis. Please enter valid input" << endl;
        abort();
    }
    populateVector();
}
void Input::getInput() {
    bool unevenParen = false;
    while (!unevenParen) {
        cout << "$ ";
        char copy[100] = {0};
        int leftParen = 0;
        int rightParen = 0;
        cin.getline(copy, 100);
        for (int i = 0; i < 100; i++) {
            if (copy[i] == '(') {
                ++leftParen;
            }
            if (copy[i] == ')') {
                ++rightParen;
            }
            if (copy[i] == '#' && (leftParen != rightParen)) {
                break;
            }
        }
        if (leftParen == rightParen) {
            for (int i = 0; i < 100; i++) {
                this->input[i] = copy[i];    
            }
            unevenParen = true;
        }
        else {
            cout << "**ERROR** Unbalanced or unexepected parenthesis. Please enter valid input" << endl;
        }
    }
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
        //cout << "searching for hashtag" << endl;
        size_t findHashtag = VectorInput.at(j).find("#");
        if (findHashtag != string::npos) {
            bool quotesAroundHashtag = false;
            if (j == VectorInput.size() - 1) {
                cout << "hello" << endl;
                VectorInput.pop_back();
                break;
            }
            for (int k = j + 1; k < VectorInput.size(); k++) {
                //cout << "Searching for quotes" << endl;
                size_t quotesAfterHash = VectorInput.at(k).find("\"");
                if (quotesAfterHash != string::npos) {
                    //cout << "found quotes" << endl;
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
                    //cout << "No quotes" << endl;
                    VectorInput.erase((VectorInput.begin()+j), (VectorInput.end()));
                    //cout << "Erased" << endl;
                }
            }
        }
    }
    // int lhs = 0;
    // int rhs = 0;
    // for (int k = 0; k < this->VectorInput.size(); ++k) {
    //     size_t foundLeftP = VectorInput.at(k).find("(");
    //     size_t foundRightP = VectorInput.at(k).find(")");
    //     if (foundLeftP != string::npos) {
    //         lhs++;
    //     }
    //     if (foundRightP != string::npos) {
    //         rhs++;
    //     }
    // }
    // if (lhs != rhs) {
    //     cout << "**ERROR** Unbalanced or unexepected parenthesis. Please enter valid input" << endl;
    //     this->flag = true;
    // }
    // testing
    // for(int i = 0; i < this->VectorInput.size(); i++) {
    //     //cout << VectorInput.at(i) << endl;
    // }
}
// bool Input::checkFlag() {
//     if (this->flag) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }
// void Input::setFlagFalse() {
//     this->flag = false;
// }
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