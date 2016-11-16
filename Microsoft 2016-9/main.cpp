//
//  main.cpp
//  ms
//
//  Created by Henry Zhou on 9/23/16.
//  Copyright © 2016 Henry Zhou. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    //take the cipher key
    int size = (int)str.size();
    vector<int> cipher_key;
    for (int i = 0; i < size; i++){
        if (str[i] == '|'){
            i = i + 1;
            while(i < size){
                cipher_key.push_back((int)str[i] - 'A');
                i++;
            }
        }
    }
    //cout << "test" << endl;
    
    
    //loop through the string
    int cipher_ptr = 0;
    vector<char> cipher_text;
    
    for (int i = 0; i < size; i++){
        if (str[i] == '|')
            break;
        
        int temp = (int) str[i];
        
        if (cipher_ptr == 10)
            cipher_ptr = 0;
        
        
        if (temp >= 65 && temp <= 90){//capitalized
            temp = temp - 65;
            int textchar = (temp + cipher_key[cipher_ptr]) % 26;
            cipher_text.push_back(textchar + 'A');
            cipher_ptr++;
        }
        
        else if (temp >= 97 && temp <= 122){
            temp = temp - 97;
            int textchar = (temp + cipher_key[cipher_ptr]) % 26;
            cipher_text.push_back(textchar + 'a');
            cipher_ptr++;
        }
        
        else{
            cipher_text.push_back(str[i]);
        }
        
    }
    
    
    for (int i = 0; i < cipher_text.size(); i++){
        cout << (char)cipher_text[i];
    }
    cout << endl;
    
    return 0;
}
