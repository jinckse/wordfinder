/**
 * @author      : jinckse (jinckse@imogen)
 * @file        : wordfinder
 * @created     : Sunday Jul 02, 2023 14:47:35 CDT
 */

#include "wordfinder.h"
#include <thread>
#include <stdio.h>
#include <iostream>
#include <exception>
#include <fstream>
#include <vector>
#include <sstream>
#include <pthread.h>

WordFinder::WordFinder()
{
    
}

WordFinder::~WordFinder()
{
}

struct ThreadInfo 
{
	    std::string message;
		    int id;
};

int WordFinder::countWords(const string &szText) 
{
	stringstream ss(szText);
	string szWord;
	int nCount = 0;
	
	while (ss >> szWord) 
	{
		nCount++;
	}
	
	return nCount;
}

// void printThreadInfo(const ThreadInfo& info) {
void workerThreadDoWork(const ThreadInfo &info)
{
	cout << "Hello from thread" << endl;
}

// Function to be executed in a separate thread
// void printThreadInfo(const ThreadInfo& info) {
//     std::cout << "Thread ID: " << info.id << ", Message: " << info.message << std::endl;
//     }
//     

int main(int argc, char **vargs)
{
	// Store user provided target word
	// and how many workers to spawn		
	string szTargetWord, szNumWorkers, szInputFileName;
	szTargetWord = vargs[1];
	szNumWorkers = vargs[2];
	szInputFileName = vargs[3];
	vector <string> vInputTextWords;
	vector <string*> vInputTextBins;
	WordFinder *wordFinder = new WordFinder();
    
	// Open target text and get total count of words
	fstream fs;
	fs.open(szInputFileName);
	if (fs.good())
	{
		cout << "Opened file successfully" << endl;
		string szLine;
		string szText;
			        
		while (getline(fs, szLine)) 
		{
			szText += szLine + "\n";
		}
			
		int nWordcount = wordFinder->countWords(szText);	

		cout << "Read " << nWordcount << " words" << endl;

		ThreadInfo info;
		info.message = "Hello from thread!";
		info.id = 1;

		std::thread t1(workerThreadDoWork, info);

		t1.join();
	
	// Calulate how target text is to be divied up
	// between threads
	
	// If the total and the target are even we can 
	// evenly divide all the words
	
	// Else if the total is odd we treat it as even
	// by subtracting 1 and adding one more word for the
	// last thread to search

	// Create thread pool of worker threads

	// Spawn each thread, and have each maintain
	// a tally for the total occurance of the target
	// word
	
	// Join all threads, and output the total number of 
	// target word occurances and the time taken to
	// compute

	}
	else
	{
		cout << "Failed to open file" << endl;
	}

	return 0;
}
