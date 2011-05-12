#include "mitlicense.hpp"

/**
 * @file type.hpp
 * Error code declarations.
 *
 * @date May 9, 2011
 * @author Cedric Wienold
 */

#ifndef _ERRORCODES_HPP
#define _ERRORCODES_HPP

/**
 * Yeah this means "basically perfect"
 */
#define EENGINE_SUCCESS                0

/***************************
 * ChangeEngine Errors     *
 ***************************/
#define EWINDOW_FAILED                 1           /* Window creation failed */
#define EINITIATE_FAILED               2           /* Multimedia Library Initialization failed */

/***************************
 * GameWindow Errors       *
 ***************************/
#define ESETVIDEOMODE_FAILED           20

#endif /* _ERRORCODES_HPP */
