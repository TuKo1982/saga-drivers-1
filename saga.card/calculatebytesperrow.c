/*
    Copyright 2016, Jason S. McMullan <jason.mcmullan@gmail.com>
    Licensed under the MIT (Expat) license. ©
*/

#include <aros/libcall.h>

#include "saga_intern.h"

/*****************************************************************************

    NAME */
        AROS_UFH3(ULONG, CalculateBytesPerRow,

/*  SYNOPSIS */
        AROS_UFHA(struct BoardInfo *, bi, A0),
        AROS_UFHA(UWORD, width, D0),
        AROS_UFHA(RGBFTYPE, RGBFormat, D7))

/*  FUNCTION

    INPUTS

    RESULT

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

    HISTORY

*****************************************************************************/
{
    AROS_LIBFUNC_INIT
    
    /* int BPP = 0; */
    
    debug("Width=%ld, RGBFormat=%ld", width, RGBFormat);
    
    // BPP = format2BPP(RGBFormat);
    // Write16(SAGA_VIDEO_BURSTPERROW, ( ( ( width * BPP ) / 8 ) / 32 ) - 1 );
    
    return ( format2bpp(RGBFormat) * width );
    
    AROS_LIBFUNC_EXIT
}
