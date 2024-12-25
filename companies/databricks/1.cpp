/*




*/


#include <iostream>

#include <bits/stdc++.h>
using namespace std;

// Function to check if the word is a constant (all uppercase letters and underscores)
bool is_constant(const string& s) {
    for(char c : s){
        if(!(c == '_' || (c >= 'A' && c <= 'Z'))) return false;
    }
    return true;
}

// Function to convert snake_case to camelCase
string convert_snake_to_camel(const string& s){
    string camel;
    bool capitalize = false;
    for(char c : s){
        if(c == '_'){
            capitalize = true; // Next character should be capitalized
        }
        else{
            if(capitalize){
                camel += toupper(c); // Capitalize the character after '_'
                capitalize = false;
            }
            else{
                camel += c; // Keep the character as is
            }
        }
    }
    return camel;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    // Ignore all characters until the end of the current line to handle multiple test cases correctly
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(T--){
        string line;
        // Read non-empty lines
        while(getline(cin, line)){
            // Trim the line from both ends
            size_t start = line.find_first_not_of(" \t\r\n");
            size_t end = line.find_last_not_of(" \t\r\n");
            if(start != string::npos){
                line = line.substr(start, end - start +1);
                break;
            }
            // If the line is empty or contains only whitespace, continue reading
        }
        // Now 'line' contains a non-empty line
        string output;
        string word;
        bool inside_backtick = false;
        
        for(char c : line){
            if(c == '`'){
                if(inside_backtick){
                    // Closing backtick found, process the word
                    if(is_constant(word)){
                        output += word; // Constants remain unchanged
                    }
                    else{
                        output += convert_snake_to_camel(word); // Convert snake_case to camelCase
                    }
                    word.clear(); // Reset the word buffer
                }
                // Toggle the backtick flag
                inside_backtick = !inside_backtick;
            }
            else{
                if(inside_backtick){
                    word += c; // Accumulate characters inside backticks
                }
                else{
                    output += c; // Accumulate characters outside backticks
                }
            }
        }
        cout << output << '\n'; // Output the transformed docstring
    }
}
