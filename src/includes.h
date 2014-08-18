/*
 *        FILE: includes.h
 *  Created on: June, 2014
 *      Author: Gilberto Monroy Aguilar
 *       email: convexbytes@gmail.com
 */

#include <cassert>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cerrno>

#include <algorithm>
#include <deque>
#include <list>
#include <string>
#include <vector>
#include <limits>
#include <iostream>

#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "parser/client_lexer.h"
#include "parser/client_parser_driver.h"
#include "parser/client_parser_types.h"
#include "sensor.h"
#include "actuator.h"
#include "psbridge.h"
#include "agent.h"
#include "client.h"
#include "log.h"
#include "udpsocket.h"
#include "udpsocket.h"
#include "dummyagent.h"
