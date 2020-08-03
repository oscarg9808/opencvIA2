
#include "Extractor.hpp"


int main(int argc, char *argv[]){
    
    int mode = 2;
    if (argc>1){
    	stringstream ss;
	ss << argv[1];
	ss >> mode;
	mode = (mode!=1 && mode!=2)?1:mode;
    }
    Extractor *huM = new Extractor();
    huM->setOperationMode(mode);
    huM->capture();
    

    delete huM;
    return 0;
}
