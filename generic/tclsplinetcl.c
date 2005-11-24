/*
 * tclspline_Init and tclspline_SafeInit
 *
 * Copyright (C) 2005 Karl Lehenbauer
 *
 * $Id: tclsplinetcl.c,v 1.3 2005-11-24 03:56:03 karl Exp $
 */

#include <tcl.h>
#include "tclspline.h"

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT


/*
 *----------------------------------------------------------------------
 *
 * tclspline_Init --
 *
 *	Initialize the tclspline extension.  The string "tclspline" 
 *      in the function name must match the PACKAGE declaration at the top of
 *	configure.in.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	One new command "spline" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Tclspline_Init(Tcl_Interp *interp)
{
    /*
     * This may work with 8.0, but we are using strictly stubs here,
     * which requires 8.1.
     */
    if (Tcl_InitStubs(interp, "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgRequire(interp, "Tcl", "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgProvide(interp, "tclspline", PACKAGE_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }

    /* Create the spline command  */
    Tcl_CreateObjCommand(interp, "spline", (Tcl_ObjCmdProc *) tclspline_splineObjCmd, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}


/*
 *----------------------------------------------------------------------
 *
 * tclspline_SafeInit --
 *
 *	Initialize the tclspline in a safe interpreter.
 *
 *      This should be totally safe.
 *
 * Results:
 *	A standard Tcl result
 *
 * Side effects:
 *	One new command "spline" is added to the Tcl interpreter.
 *
 *----------------------------------------------------------------------
 */

EXTERN int
Tclspline_SafeInit(Tcl_Interp *interp)
{
    /*
     * This may work with 8.0, but we are using strictly stubs here,
     * which requires 8.1.
     */
    if (Tcl_InitStubs(interp, "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgRequire(interp, "Tcl", "8.1", 0) == NULL) {
	return TCL_ERROR;
    }

    if (Tcl_PkgProvide(interp, "tclspline", PACKAGE_VERSION) != TCL_OK) {
	return TCL_ERROR;
    }

    /* Create the spline command  */
    Tcl_CreateObjCommand(interp, "spline", (Tcl_ObjCmdProc *) tclspline_splineObjCmd, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);

    return TCL_OK;
}

