/*
 * Copyright (C) 2016, Jason S. McMullan <jason.mcmullan@gmail.com>
 * All rights reserved.
 *
 * Licensed under the MIT License:
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SAGA_INTERN_H
#define SAGA_INTERN_H

#include <exec/libraries.h>

#include <picasso96/card.h>

#include <saga/video.h>

#include <proto/arossupport.h>

#if DEBUG
#define bug(x,args...)   kprintf(x ,##args)
#define debug(x,args...) bug("%s:%d " x "\n", __func__, __LINE__ ,##args)
#else
#define bug(x,args...)   do { } while (0)
#define debug(x,args...) do { } while (0)
#endif


struct SAGABase {
    struct Library      Lib;
    /* Local copy of CLUT, in SAGA format: -|R8|G8|B8 */
    ULONG               sc_CLUT[256];
    /* Local copy of SAGA_VIDEO_MODE_FORMAT */
    UBYTE               sc_Format;
    /* Local copy of SAGA_VIDEO_MODE_DBLSCN */
    UBYTE               sc_DoubleScan;

    struct Library *    sc_ExecBase;
};

static inline VOID Write32(IPTR addr, ULONG value)
{
    bug("0x%06lx <= 0x%08lx\n", addr, value);
    if (!SIMULATE) {
        *(volatile ULONG *)addr = value;
    }
}

static inline UWORD Read16(IPTR addr)
{
    return *(volatile UWORD *)addr;
}

static inline VOID Write16(IPTR addr, UWORD value)
{
    bug("0x%06lx <= 0x%04lx\n", addr, value);
    if (!SIMULATE) {
        *(volatile UWORD *)addr = value;
    }
}

static inline int format2bpp(RGBFTYPE format)
{
    if ((1UL << format) & RGBMASK_8BIT)
        return 1;
    if ((1UL << format) & (RGBMASK_15BIT | RGBMASK_16BIT))
        return 2;
    if ((1UL << format) & RGBMASK_24BIT)
        return 3;
    if ((1UL << format) & RGBMASK_32BIT)
        return 4;

    return 0;
}

/* Test if width or height requires doublescan
 */
#define IS_DOUBLEX(w)   ((w) <= 320)
#define IS_DOUBLEY(h)   ((h) <= 240)

#endif /* SAGA_INTERN_H */
/* vim: set shiftwidth=4 expandtab:  */
