#include "Mouse.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{

    //Blank image for moving the mouse over
    cv::Mat imgBlank(700, 900, CV_8UC3, cv::Scalar::all(0));           

    std::vector<cv::Point> mousePositions;

    cv::Point predictedMousePosition;
    cv::String windowName ="Blank";
    cv::namedWindow(windowName);                               
    cv::setMouseCallback(windowName, za::mouseMoveCallback); 
    // Check is esc is pressed       
    char ch;
    // uncomment to save screen
    //int i = 0;
    while (true) 
    {
        // uncomment to save screen
        //i++;
        // get the current position
        mousePositions.push_back(za::mousePosition);            

        // predict the next position
        predictedMousePosition = za::predictNextPosition(mousePositions);        

        std::cout << "current position        = (" << mousePositions.back().x << ", " << mousePositions.back().y << ")\n";
        std::cout << "next predicted position = (" << predictedMousePosition.x << ", " << predictedMousePosition.y << ")\n";
        std::cout << "--------------------------------------------------\n";

        za::drawCross(imgBlank, mousePositions.back(), za::SCALAR_WHITE);
    
        // Draw a cross at the most recent predicted, actual, and corrected positions
        za::drawCross(imgBlank, predictedMousePosition, za::SCALAR_RED);  

        // Show the image
        cv::imshow(windowName, imgBlank);    
        // Uncommment to save screen   
        /*
        if( i > 200 && mousePositions.back().x != predictedMousePosition.x && mousePositions.back().y != predictedMousePosition.y)
        {
            
            cv::imwrite("Screen.png", imgBlank);
            break;
        }
        */
        // Pause for a moment to get operating system to redraw the imgBlank       
        ch = cv::waitKey(10);                 

        if (ch == 27) {
            break;
        }   
        // Blank the imgBlank for next time around
        imgBlank = cv::Scalar::all(0);         
    }

    return 0;
}



