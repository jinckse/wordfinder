/**
 * @author      : jinckse (jinckse@imogen)
 * @file        : wordfinder
 * @created     : Sunday Jul 02, 2023 14:47:52 CDT
 */

#ifndef WORDFINDER_H

#define WORDFINDER_H

#include <string>

using namespace std;

class WordFinder
{
public:
	WordFinder();
	~WordFinder();

	int countWords(const string &szText);
};


#endif /* end of include guard WORDFINDER_H */

