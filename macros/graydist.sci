function[dstImg] = graydist(srcImg, mask)
	
	srcMat = mattolist(srcImg)

	out = opencv_graydist(srcMat, mask)
	
	channels = size(out)
	
	for i = 1:channels
		dstImg(:,:,i) = out(i)
	end
	
endfunction
