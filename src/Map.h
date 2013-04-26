/*
 * map.h
 *
 *  Created on: 23 Apr 2013
 *      Author: Jo�o
 */

#ifndef MAP_H_
#define MAP_H_

#include "Zone.h"

/**
*@brief Represents map. Inherits Graph class. 
*/
class Map : public Graph<int>{
public:
	Map();
	bool addVertex(const int &in, string name, bool hasStore);
	void setDefault();
	int chooseStore(int d);
};



#endif /* MAP_H_ */
