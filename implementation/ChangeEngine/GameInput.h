/*
 * GameInput.h
 *
 *  Created on: Feb 27, 2011
 *      Author: cedric
 */

#ifndef GAMEINPUT_H_
#define GAMEINPUT_H_

enum CE_INPUT_TYPE {
	CE_INPUT_KEYBOARD = 0,
	CE_INPUT_MOUSE = 1,
	CE_INPUT_OTHER = 2
};

class GameInput {
public:
	GameInput();
	virtual ~GameInput();
};

#endif /* GAMEINPUT_H_ */
