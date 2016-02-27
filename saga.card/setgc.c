/*
    Copyright 2016, Jason S. McMullan <jason.mcmullan@gmail.com>
    Licensed under the MIT (Expat) license. �
*/

#include <aros/libcall.h>

#include "saga_intern.h"

/*****************************************************************************

    NAME */
        AROS_LH3(BOOL, SetGC,

/*  SYNOPSIS */
        AROS_LHA(struct BoardInfo *, bi, A0),
        AROS_LHA(struct ModeInfo *, mi, A1),
        AROS_LHA(BOOL, border, D0),

/*  LOCATION */
        struct Library *, SAGABase, 28, Saga)

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

    debug("");

    Write16(SAGA_VIDEO_WIDTH, mi->Width);
    Write16(SAGA_VIDEO_HEIGHT, mi->Height);

    return TRUE;

    AROS_LIBFUNC_EXIT
}

