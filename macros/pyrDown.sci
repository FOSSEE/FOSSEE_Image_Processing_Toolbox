function [out]=pyrDown(input_image, dstsize_width, distsize_height, border)
         input_image1=mattolist(input_image);
         a=opencv_pyrDown(input_image1, dstsize_width, distsize_height, border);
         dimension=size(a)
         for i = 1:dimension
              out(:,:,i)=a(i);
         end
     
endfunction;
