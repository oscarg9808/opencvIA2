

all:
	g++ Principal.cpp Extractor.cpp -I /usr/local/include/opencv4 -L /usr/local/lib  -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs -lopencv_video -lopencv_videoio -o huM.bin
	
run:
	./huM.bin
