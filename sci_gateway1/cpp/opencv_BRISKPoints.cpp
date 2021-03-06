/***************************************************
Author : Shashank Shekhar
***************************************************/

#include <numeric>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
extern "C"
{
    #include "api_scilab.h"
    #include "Scierror.h"
    #include "BOOL.h"
    #include <localization.h>
    #include "sciprint.h"
    #include "../common.h"

    int opencv_BRISKPoints(char *fname, unsigned long fname_len)
	{
		SciErr sciErr;
		int *piAddr = NULL;
		int *piChild = NULL;
		int iType = 0;
		int iRows, iCols = 0;
		double *matData = NULL;
	
		double *OrientationData = NULL;
	    double *MetricData = NULL; 	
		double *ScaleData = NULL;
	
	    CheckInputArgument(pvApiCtx, 1,1);	
        CheckOutputArgument(pvApiCtx,1,5);

       	sciErr = getVarAddressFromPosition(pvApiCtx, 1, &piAddr);
		if(sciErr.iErr)
		{
			printError(&sciErr, 0);
			return 0;
		}      	
		
		sciErr = getVarType(pvApiCtx, piAddr, &iType);
		if(sciErr.iErr || iType != sci_matrix || isVarComplex(pvApiCtx, piAddr))
		{
			printError(&sciErr, 0);
			return 0;
		}

		sciErr = getMatrixOfDouble(pvApiCtx, piAddr, &iRows, &iCols, &matData);
		if(sciErr.iErr)
		{
			printError(&sciErr, 0);
			return 0;
		}	

		if (iCols!=2)
        {
            Scierror(999,"Invalid Argument\n");
            return 0;
        }

	    OrientationData = (double *)malloc(sizeof(double)*iRows);
	    MetricData = (double *)malloc(sizeof(double)*iRows);
	    ScaleData = (double *)malloc(sizeof(double)*iRows);

		for(int i = 0 ; i<iRows; i++)
		{			
		    OrientationData[i] = 0;
		    MetricData[i] = 0;
		    ScaleData[i] = 12;
		}

	    sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1, iRows,2, matData);
	    if(sciErr.iErr)
	    {
	        printError(&sciErr, 0);
	        return 0;
	    }

	    sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 2, iRows,1, OrientationData);
	    if(sciErr.iErr)
	    {
	        printError(&sciErr, 0);
	        return 0;
	    }
	        
	    sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 3, iRows,1, MetricData);
	    if(sciErr.iErr)
	    {
	        printError(&sciErr, 0);
	        return 0;
	    }

	    sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 4, iRows,1, ScaleData);
	    if(sciErr.iErr)
	    {
	        printError(&sciErr, 0);
	        return 0;
	    }

	    createScalarInteger32(pvApiCtx,nbInputArgument(pvApiCtx) + 5, iRows);

	    for(int i=1;i<=5;i++)
	    {
	 		AssignOutputVariable(pvApiCtx, i) = nbInputArgument(pvApiCtx) + i;   	
	    }

		ReturnArguments(pvApiCtx);
		return 0;
	}
}