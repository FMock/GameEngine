#include"KeyInfo.h"

std::string KeyInfo::currentKey = ""; // initialize static member
std::string KeyInfo::prevKey = ""; // initialize static member


/* Definition of static function setCurrentKey
 * sets prevKey to the currentKey
 * sets currentKey to s
 */
void KeyInfo::setCurrentKey(std::string s){
	KeyInfo::prevKey = KeyInfo::currentKey;
	KeyInfo::currentKey = s;
}

std::string KeyInfo::getCurrentKey(){
	return KeyInfo::currentKey;
}

std::string KeyInfo::getPrevKey(){
	return KeyInfo::prevKey;
}