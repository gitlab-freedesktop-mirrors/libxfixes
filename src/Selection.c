/*
 *
 * Copyright © 2002 Keith Packard, member of The XFree86 Project, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "Xfixesint.h"

void
XFixesSelectSelectionInput (Display	    *dpy,
			    Window	    win,
			    Atom	    selection,
			    unsigned long   eventMask)
{
    XFixesExtDisplayInfo	    *info = XFixesFindDisplay (dpy);
    xXFixesSelectSelectionInputReq  *req;

    XFixesSimpleCheckExtension (dpy, info);

    LockDisplay (dpy);
    GetReq (XFixesSelectSelectionInput, req);
    req->reqType = info->codes->major_opcode;
    req->xfixesReqType = X_XFixesSelectSelectionInput;
    req->window = (CARD32) win;
    req->selection = (CARD32) selection;
    req->eventMask = (CARD32) eventMask;
    UnlockDisplay (dpy);
    SyncHandle ();
}
