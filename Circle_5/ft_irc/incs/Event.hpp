#pragma once

#include <iostream>
#include <map>
#include <utility>
#include <sys/_types/_uintptr_t.h>

typedef std::map<uintptr_t, std::string> events; 
typedef std::pair<uintptr_t, std::string> event;
typedef std::map<uintptr_t, std::string>::iterator events_iter;