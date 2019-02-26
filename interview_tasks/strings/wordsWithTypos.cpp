// Read input from stdin, write output to stdout
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
/*
	1. You are given a text T consisting of words in which there may be typos.
	2. Your task is to count how many times a given word W is used in this text.
	3. However, you need to include in this count the cases in which this word was written with a typo.
	4. It's hard to say if a word contains a typo or not, especially if you don't have a good dictionary. 
		For this task, a word W' in T is considered to be an instance of W if:
			it's exactly the same as W
			it has the same length as W and up to 2 letters are different
			W' can be obtained from W by removing or adding 1 letter
			For example if W = banana the following words are instances of it with typos:
				bamama (2 letters are changed)
				bananas (one added letter)
				banna (one letter was missed out)
	5. The length of W will be in the range [5, 20]. The input text T will be no longer than 10,000 symbols. 
			It will contain only lower case latin letters and spaces used to separate the words.
 */

bool one_letter_off(const string& a, const string& b) {
    if ( abs( int( b.size() - a.size() ) ) != 1 )
        return false;

        
    int ai = 0, bi = 0;
    while( ai < a.size() && bi < b.size() ) {
        if( a[ai] == b[bi] ) {
            ++ai;
            ++bi;
        } else {
            b.size() > a.size() ? ++bi : ++ai;
            if( abs( ai-bi ) > 1 )
                return false;
        }
    }
    
    return true;
}

bool misMatch( const string& a, const string& b ) {
    if ( a.size() != b.size() ) return false;
    
    int err = 0;
    for( int i = 0; i < a.size(); ++i ) {
        if( a[i] != b[i] ) {
            ++err;
            if( err > 2 ) return false;
        }
    }
    return true;
}

int count_typos(const string& t, const string& w) {
  stringstream text(t);

  int count{0};
  string tmp;
  while (text >> tmp) {
    if ( misMatch( tmp, w ) || one_letter_off(tmp, w) )
      ++count;
  }

  return count;
}

int main() {
  string w;
  getline(cin, w);

  string t;
  getline(cin, t);

  cout << count_typos(t, w) << endl;
}
