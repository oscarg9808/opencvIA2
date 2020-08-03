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

class Extractor{
    
    private:
        string outDir;
        int hMin, sMin, vMin;
        int hMax, sMax, vMax;
	int operationMode;

        Mat imageThreshold;
        
        // Hu Moments previously extracted for Red, Blue, and Green colors:
        
        double basehumoments[3][7] = {{0.303186,0.0027931,0.00233324,0.000591961,3.53286e-07,-6.80602e-06,-5.99317e-07},
                {0.202415,0.0126813,0.000313626,3.61459e-05,1.39851e-09,6.56449e-07,3.58543e-09},
                {0.201398,0.000601995,0.000203586,9.69691e-05,7.71919e-09,2.35965e-06,-1.12269e-08}};
        
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
        Extractor(string = "fichero.txt");
        vector<double> extractHuMoments(Mat);
        vector<double> extractHuMoments(Mat,int,int,int,int,int,int);
        void capture();
        void setOperationMode(int);
};
