function [fundamentalMatrix]=estimateFundamentalMatrix(matchedPoints1,matchedPoints2,varargin)
// It returns the 3-by-3 fundamental matrix corresponding to the input points
//
// Calling Sequence
//   fundamentalMat=estimateFundamentalMatrix(matchedPoints1,matchedPoints2);
//	 fundamentalMat=estimateFundamentalMatrix(matchedPoints1,matchedPoints2,'method','RANSAC','param1',2,'param2',0.99);
//
// Parameters
// matchedPoints1:  M-by-2 array of first image points. These points can be SURFPoints, MSERRegions, cornerPoints. 
// matchedPoints2:  M-by-2 array of the second image points of the same size and format as matchedPoints1.
// method: method for computing fundamental matrix. Possible methods are 7POINT,8POINT,RANSAC,LMEDS and RANSAC is the default one. 
// param1: It indiacates maximum distance from a point to an epipolar line in pixels
// param2: It specifies a desirable level of confidence
//
// Description
// estimateFundamentalMatrix function calculates a fundamental matrix from the corresponding points in two images.
//
// Examples
// I=imread("lena_left.jpeg");
// cornerPoints1=detectMinEigenFeatures(I);
// I2=imread("lena_right.jpeg");
// cornerPoints2=detectMinEigenFeatures(I2);
// fundamentalMat=(cornerPoints1.Location,cornerPoints2.Location);

    [lhs rhs]=argn(0);
    if rhs>10
        error(msprintf(" Too many input arguments"));
    elseif modulo(rhs,2)==0
       error(msprintf("Either Argument Name or its Value missing"));
    end
    select rhs
        case 2 then
            [fundamentalMatrix]=opencv_estimateFundamentalMatrix(matchedPoints1,matchedPoints2);
        case 4 then
            [fundamentalMatrix]=opencv_estimateFundamentalMatrix(matchedPoints1,matchedPoints2,varargin(1),varargin(2));
        case 6 then
            [fundamentalMatrix]=opencv_estimateFundametanlMatrix(matchedPoints1,matchedPoints2,varargin(1),varargin(2),varargin(3),varargin(4));
        case 8 then
            [fundamentalMatrix]=opencv_estimateFundamentalMatrix(matchedPoints1,matchedPoints2,varargin(1),varargin(2),varargin(3),varargin(4),varargin(5),varargin(6));
    end
endfunction
