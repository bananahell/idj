#include <iostream>
#include <string>
#include <fstream>

int main() {

  std::ifstream fileContent("tileMap.txt", std::ifstream::in);
  if (!fileContent.is_open()) {
    // TODO deu ruim
  }

  std::string lineString;

  int indexValue = 0;
  getline(fileContent, lineString);
  for (unsigned int i = 0; i < lineString.size(); i++) {
    if (lineString.at(i) == ',') {
      std::cout << indexValue << " ";
      indexValue = 0;
    } else {
      indexValue *= 10;
      indexValue += lineString.at(i) - '0';
    }
  }
std::cout << std::endl;
  int tileValue = 0;
  while (getline(fileContent, lineString)) {
    for (unsigned int i = 0; i < lineString.size(); i++) {
      if (lineString.at(i) >= '0' && lineString.at(i) <= '9') {
        tileValue *= 10;
        tileValue += lineString.at(i) - '0';
        std::cout << lineString.at(i);
      } else {
        std::cout << " - ";
        std::cout << tileValue << std::endl;
        tileValue = 0;
      }
    }
    std::cout << std::endl;
  }

  fileContent.close();
    
    return 0;

}
