function[cropImg] = imcrop(srcImg, xcoor, ycoor, width, height)
	srcMat = mattolist(srcImg)
//	disp(srcMat)
	cropImg = opencv_imcrop(srcMat, xcoor, ycoor, width, height)
endfunction
