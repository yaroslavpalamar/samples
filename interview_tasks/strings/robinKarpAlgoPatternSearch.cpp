/* Following program is a C implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include<stdio.h> 
#include<string.h> 

/*
 * Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], 
 char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.
 
 Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. 
 But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of
 current substring of text, and if the hash values match then only it starts matching individual characters. 
 So Rabin Karp algorithm needs to calculate hash values for following strings.
 
Examples:
Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10
Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12
 
hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
hash( txt[s .. s+m-1] ) : Hash value at shift s.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet
q: A prime number
h: d^(m-1)
 
 * */

#include <bits/stdc++.h> 
using namespace std; 
void naiveSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j; 
		
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            cout << "Pattern found at index "
                 << i << endl; 
    }
}

// CPP program to print all occurrences of a pattern 
// in a text 
void printOccurrencesCPP(string pat, string txt) 
{ 
    int found = txt.find(pat); 
    while (found != string::npos) { //npos means not found or end of string
        cout << "Pattern found at index " << found << endl; 
        found = txt.find(pat, found + 1); 
    } 
} 
  
  
// d is the number of characters in the input alphabet 
#define d 256 
/* pat -> pattern 
    txt -> text 
    q -> A prime number 
*/
void robinKarpSearch(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 
  
    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M-1; i++) 
        h = (h*d)%q; 
  
    // Calculate the hash value of pattern and first 
    // window of text 
    for (i = 0; i < M; i++) 
    { 
        p = (d*p + pat[i])%q; 
        t = (d*t + txt[i])%q; 
    } 
  
    // Slide the pattern over text one by one 
    for (i = 0; i <= N - M; i++) 
    {
        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one 
        if ( p == t ) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                printf("Pattern found at index %d \n", i); 
        } 
  
        // Calculate hash value for next window of text: Remove 
        // leading digit, add trailing digit 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
  
            // We might get negative value of t, converting it 
            // to positive 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    char txt[] = "TEST 1 AND TEST 2 AND TEST3 4TEST"; 
    char pat[] = "TEST"; 
    int q = 101; // A prime number 
	
	// naive Search impl
    naiveSearch(pat, txt); 
	cout <<endl;
	
	// Robin Karp C impl
	robinKarpSearch(pat, txt, q); 
	cout <<endl;

	//cpp lib impl
	printOccurrencesCPP(pat, txt); 
    return 0; 
} 

