#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

#include <dirent.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/videoio/videoio.hpp>

#include <math.h>

using namespace std;
using namespace cv;

class HuMomentsExtractor{
    
    private:
        string outDir;
        int hMin, sMin, vMin;
        int hMax, sMax, vMax;
	int operationMode;

        Mat imageThreshold;
        
        // Hu Moments previously extracted for Red, Blue, and Green colors:
        
        double basehumoments[3][7] = {{0.269826,0.000812627,0.00186835,0.000519597,1.97508e-07,-6.97519e-06,-4.72318e-07},
                {0.192662,0.00482353,0.00140656,0.000142982,6.38524e-08,9.80799e-06,-5.86207e-09},
                {0.346388,0.0147489,0.00477836,0.00188822,-5.44637e-06,-0.000190728,-1.58308e-06}};
        
        // Red: hsv-min (0,53,162)    hsv-max (12,192,244)
        // Blue: hsv-min (83,125,183)   hsv-max (137,186,232)
        // Green: hsv-min (36,85,134) hsv-max (53,196,201)
        
        

        
        static void huFunc(int,void*);
        void printHSV();

        
        int euclideanDistance(vector<double>,int);
        
        void refreshImg();
        /*
        static void hMax(int,void*);
        static void sMax(int,void*);
        static void vMax(int,void*);
        static void hMin(int,void*);
        static void sMin(int,void*);
        static void vMin(int,void*);
        */

    public:
        HuMomentsExtractor(string = "fichero.txt");
        vector<double> extractHuMoments(Mat);
        vector<double> extractHuMoments(Mat,int,int,int,int,int,int);
        void capture();
        void setOperationMode(int);
};
