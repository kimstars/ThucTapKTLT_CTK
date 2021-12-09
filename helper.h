#ifndef _HELPER_H_
#define _HELPER_H_

#include <iostream>


using namespace std;

#define get_func(type, object)   \
type get##object()          \
{                           \
    return this->object;    \
}

#define set_func(type, object)       \
void set##object(type object)   \
{                               \
    this->object = object;      \
}

#endif /* _HELPER_H_ */
