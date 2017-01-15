#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc opencv_imread;
extern Gatefunc opencv_imcrop;
extern Gatefunc opencv_imresize;
extern Gatefunc opencv_imsharpen;
extern Gatefunc opencv_imwrite;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imread,"opencv_imread"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcrop,"opencv_imcrop"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imresize,"opencv_imresize"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imsharpen,"opencv_imsharpen"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imwrite,"opencv_imwrite"},
};
 
int C2F(libskeleton_imageprocessing)()
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
