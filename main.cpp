#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
using namespace std;


int main() {
  
  float line; //Variables
  list<float> cashTips;
  list<float> cardTips;
  list<float>::iterator it;
  list<float> cash;
  float tip;  
  float csh;
  float average, cashTotal;
  float owed;
  float cardTipTotal, cashTipTotal;
  int mod;
  
  ifstream  //Input files
  cashInp ("cashorders.txt"),
  cashTipInp ("cashtips.txt"),
  cardTipInp ("cardtips.txt");

  if (cashInp.is_open()){  //Moving data from input files to list variables
    while (cashInp >> line){
      if (line == 0){
  
      }else{
      cash.push_back(line);
      }
    }
  }

  if (cashTipInp.is_open()){
    while (cashTipInp >> line){
      cashTips.push_back(line);
    }
  }

  if (cardTipInp.is_open()){
    while (cardTipInp >> line){
      cardTips.push_back(line);
    }
  }


  // Calculating total card tips
  if (cardTips.size() != 0) {
    for (it = cardTips.begin(); it != cardTips.end(); it++) {
      cardTipTotal += *it;
    }
  } else {
    cardTipTotal = 0;
  }

  // Calculating total cash tips
  if (cashTips.size() != 0) {
    for (it = cashTips.begin(); it != cashTips.end(); it++) {
      if (*it == 0 ){
        
      }else{
      cashTipTotal += *it;
      }
    }
  } else {
    cashTipTotal = 0;
  }

  // Calculating total cash
  if (cash.size() != 0) {
    for (it = cash.begin(); it != cash.end(); it++) {
      cashTotal += *it;
    }
  } else {
    cashTotal = 0;
  }

  int totalLength = cardTips.size() + cash.size() + (cashTips.size() - cash.size());
  float totalTips = cardTipTotal + cashTipTotal;

  owed = (cashTotal - (cardTipTotal + totalLength));

  average = totalTips / totalLength;

  cout << setprecision(2) << fixed;

  cout << "\nAverage today (tips only): $" << average;
  cout << "\n\nCard tips:\n";
  if (cardTips.size() == 0) {
    cout << "NONE";
  } else {
    for (it = cardTips.begin(); it != cardTips.end(); ++it)
      cout << "$" << *it << "\n";
  }
  cout << "\n\nCash tips:\n";
  if (cashTips.size() == 0) {
    cout << "NONE\n";
  } else {
    for (it = cashTips.begin(); it != cashTips.end(); ++it)
      cout << "$" << *it << "\n";
  }

  cout << "\nDeliveries taken: ";
  cout << "\nCash: " << cash.size();
  cout << "\nCard: " << cardTips.size() + (cashTips.size() - cash.size());
  cout << "\nTotal: " << totalLength;

  cout << "\n\nTotal made today: $" << totalTips + totalLength;

  if (owed < 0){
    cout << "\nYou are owed: $" << abs(owed);
  }else{
  cout << "\nYou owe the register: $" << owed;
  }

  return 0;
}
