#include <iostream>
#include <string>
#include <fstream>

#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {

  if(argc != 2){
    cout << "\n\nInput Error\n";
    cout << "Usage: " << argv[0] << "<data directory location>" << endl;
    cout << "Example: " << argv[0] << "../data" << endl;
    cout << "============================================\n\n";
    return 0;
  }
  
  cout << endl << "Data format converter for FANN" << endl <<
    "========================================" << endl << endl;

  string images = string(argv[1]) + "/train-images-idx3-ubyte";
  string labels = string(argv[1]) + "/train-labels-idx1-ubyte";
  string destination = "training.data";
  
  int to_read = 150;
  int from = 0;
  cout << "Number of examples to read: ";
  cin >> to_read;
  cout << "What row to start: ";
  cin >> from;
  
  
  ofstream outfile;
  outfile.open(destination.c_str());

  FILE* img_file;
  FILE* lbl_file;
  
  img_file = fopen(images.c_str(), "rb");
  if(img_file == NULL){
    cout << "Unable to open the files of the images!" << endl;
    return 0;
  }

  lbl_file = fopen(labels.c_str(), "rb");
  if(lbl_file == NULL){
    cout << "Unable to open the files of the values!" << endl;
    return 0;
  }
  
  fseek(img_file, 16, SEEK_SET);
  fseek(lbl_file, 8, SEEK_SET);
  
  if (from > 0) {
    fseek(img_file, 28*28*from, SEEK_CUR);
    fseek(lbl_file, from, SEEK_CUR);
  }
  
  unsigned char* img = new unsigned char[28*28];
  unsigned char* lbl = new unsigned char[to_read];
  fread(lbl, 1, to_read, lbl_file);
  
  outfile << to_read << " " << 28*28 << " " << 10 << endl;
  
  for(int i=0; i<to_read; i++) {
    int pixel;
    int value;
    value = lbl[i];
    
    fread(img, 1, 28*28, img_file);
    
    for(int j=0; j<28*28; j++) {
      pixel = img[j];
      outfile << pixel;
      if (j+1<28*28)
	outfile << " ";
    }
    outfile << endl;
    for(int j=0; j<10; j++) {
      if(j==value) {
	outfile << "0.9";
      }else{
	outfile << "0.1";
      }
      if(j<9) {
	outfile << " ";
      }
    }
    if (i+1<to_read)
      outfile << endl;
  }
  
  cout << "File Examples ("<< destination <<") generated!" << endl;
  
  delete[] img;
  delete[] lbl;
  
  fclose(img_file);
  fclose(lbl_file);
  outfile.close();
  
  return 0;
}
