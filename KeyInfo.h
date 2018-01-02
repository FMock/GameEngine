#pragma once

#ifndef KEYINFO_H
#define KEYINFO_H

/* A class to allow objects access to games key press information.
 * main will update the static variables noted in this class
 */

#include<string>

class KeyInfo{
private:
	static std::string currentKey; // declaration of static member
	static std::string prevKey; // declaration of static member
public:
	static void setCurrentKey(std::string);
	static std::string getCurrentKey();
	static std::string getPrevKey();
};

#endif