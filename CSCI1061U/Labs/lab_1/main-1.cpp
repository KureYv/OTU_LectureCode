
#include<iostream> //imports here
#include<fstream> 
#include<string>
#include<vector>
using namespace std;


bool isFound(vector<string> c, string word){ //isFound function, checks if the word is found inside of the vector and returns whether it is true or false
  for(string i:c){
    if(i == word){
      return true;
    }
  }
  return false;
}

int returnCount(vector <string> v, string word){//returnCount function, takes in a vector and a string, returns how many times it was found
  int count = 0;
  for(string i:v){
    if(i==word){
      count++;
    }
    
  }
  return count;

}


void printReport(vector<string> words, vector<int> counts){//printReport function, handles the cout stuff
  int count = 0;
  for(int i:counts){
    cout << words[count] + ": "<< counts[count] << endl;
    count++;
  }
}

string lowerCase(string word) {//to_lower function, converts the string to lowercase by changing the value in the memory address directly
    for(char &c : word)
        c = tolower(c);
    return word;
}


int main(){ //main function
  ifstream  file;
  vector<string> wordList;
  vector<string> Report;
  vector<int> Counts;
  int stringCount;
  file.open("data.txt");
  string word;
  string j;
  while(file >> word){ //append to the vector word
    wordList.push_back(word);
  }
  for(string i:wordList){ //count how many words are in the file
    stringCount++;
  }
  for(int i =0;i<stringCount;i++){ //converts all the words to lower case
    wordList[i] = lowerCase(wordList[i]);
  }
  
  for(string i:wordList){ //iterate over the list of words appended from the file
    if(!isFound(Report,i)){ //if it is not found in the Reports
      Counts.push_back(returnCount(wordList,i)); //push into the vector counts
      Report.push_back(i); //push into vector report
    }
  }
  printReport(Report,Counts); //call the printreport function
}