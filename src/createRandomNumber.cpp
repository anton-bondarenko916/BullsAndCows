#include "functions.h"

int create() {
  string path = "thirdparty/txt/numbers.txt";
  ifstream fin;
  srand(time(NULL));
  int randomIndex = rand() % 39 + 0;
  int createdNumber = 20;
  string number;


  fin.open(path);
  if (!fin.is_open()) {
    cout << "Error open file" << endl;
  } else {
    int i = 0;
    while(getline(fin, number)) {
      if (i == randomIndex) {
        break;
      }
      i++;
    }
  }
  fin.close();
  createdNumber = atoi(number.c_str());
  return createdNumber;
}
