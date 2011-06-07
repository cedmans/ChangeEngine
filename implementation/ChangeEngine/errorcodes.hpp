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
 * Yeah this means "basically perfect" in all contexts.
 */
#define EENGINE_SUCCESS                0

/***************************
 * ChangeEngine Errors     *
 ***************************/
#define EWINDOW_FAILED                 1           /* Window creation failed */
#define EINITIATE_FAILED               2           /* Multimedia Library Initialization failed */
#define ELEVELCREATE_FAILED            3           /* Creation of a game level has failed */
#define ELEVELCREATE_ALREADY_EXISTS    4           /* Game level creation attempt on preexisting name */
#define EOBJECTCREATE_INVALID_LEVEL    5           /* Object create attempt on level that doesn't exist */
#define EATTACHIMAGE_INVALID_LEVEL     6           /* Attaching image to invalid level */
#define EATTACHIMAGE_INVALID_OBJECT    7           /* Attaching image to invalid object */
#define EOBJECTCREATE_CREATE_FAILED    8           /* Object create attempt failed */
#define EATTACHIMAGE_FAILED            9           /* Attaching of image to object failed */
#define EADDSTATE_INVALID_LEVEL        10          /* Attempted adding state to avatar of invalid level */
#define EADDSTATE_FAILED               11          /* Attempt to add state to avatar failed. */

/***************************
 * GameWindow Errors       *
 ***************************/
#define ESETVIDEOMODE_FAILED           20

/***************************
 * GameObject Errors       *
 ***************************/
#define EOBJECT_ALREADY_EXISTS         40
#define EATTACH_AVATAR_ALREADY_EXISTS  41

/***************************
 * GameLevel Errors       *
 ***************************/
#define EADDSTATE_INVALID_OBJECT       60


#endif /* _ERRORCODES_HPP */
