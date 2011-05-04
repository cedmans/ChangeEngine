/*
 * GameNetwork.h
 *
 *  Created on: Feb 27, 2011
 *      Author: cedric
 */

#ifndef GAMENETWORK_H_
#define GAMENETWORK_H_

enum CE_NETWORK_TYPE {
	CE_NETWORK_SERVER = 0,
	CE_NETWORK_CLIENT = 1,
	CE_NETWORK_P2P = 2
};

class GameNetwork {

	public:
		GameNetwork(CE_NETWORK_TYPE);
		virtual ~GameNetwork();
};

#endif /* GAMENETWORK_H_ */
