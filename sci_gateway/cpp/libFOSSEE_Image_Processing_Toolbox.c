#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc opencv_blur;
extern Gatefunc opencv_circle;
extern Gatefunc opencv_dilate;
extern Gatefunc opencv_erode;
extern Gatefunc opencv_imcrop;
extern Gatefunc opencv_impixel;
extern Gatefunc opencv_imread;
extern Gatefunc opencv_imresize;
extern Gatefunc opencv_imsharpen;
extern Gatefunc opencv_imwrite;
extern Gatefunc opencv_imrotate;
extern Gatefunc opencv_rgb2gray;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway,opencv_blur,"raw_blur"},
  {(Myinterfun)sci_gateway,opencv_circle,"raw_circle"},
  {(Myinterfun)sci_gateway,opencv_dilate,"raw_dilate"},
  {(Myinterfun)sci_gateway,opencv_erode,"raw_erode"},
  {(Myinterfun)sci_gateway,opencv_imcrop,"raw_imcrop"},
  {(Myinterfun)sci_gateway,opencv_impixel,"raw_impixel"},
  {(Myinterfun)sci_gateway,opencv_imread,"raw_imread"},
  {(Myinterfun)sci_gateway,opencv_imresize,"raw_imresize"},
  {(Myinterfun)sci_gateway,opencv_imsharpen,"raw_imsharpen"},
  {(Myinterfun)sci_gateway,opencv_imwrite,"raw_imwrite"},
  {(Myinterfun)sci_gateway,opencv_imrotate,"raw_imrotate"},
  {(Myinterfun)sci_gateway,opencv_rgb2gray,"raw_rgb2gray"},
};
 
int C2F(libFOSSEE_Image_Processing_Toolbox)()
{
  Rhs = Max(0, Rhs);
  if (*(Tab[Fin-1].f) != NULL) 
  {
     if(pvApiCtx == NULL)
     {
       pvApiCtx = (StrCtx*)MALLOC(sizeof(StrCtx));
     }
     pvApiCtx->pstName = (char*)Tab[Fin-1].name;
    (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  }
  return 0;
}
#ifdef __cplusplus
}
#endif
