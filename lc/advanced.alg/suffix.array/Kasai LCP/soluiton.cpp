/*
LCP Array is an array of size n (like Suffix Array). A value lcp[i] indicates length of the longest common prefix 
of the suffixes inexed by suffix[i] and suffix[i+1]

txt[0..n-1] = "banana"
suffix[]  = {5, 3, 1, 0, 4, 2| 
lcp[]     = {1, 3, 0, 0, 2, 0}

Suffixes represented by suffix array in order are:
{"a", "ana", "anana", "banana", "na", "nana"}


lcp[0] = Longest Common Prefix of "a" and "ana"     = 1
lcp[1] = Longest Common Prefix of "ana" and "anana" = 3
lcp[2] = Longest Common Prefix of "anana" and "banana" = 0
lcp[3] = Longest Common Prefix of "banana" and "na" = 0
lcp[4] = Longest Common Prefix of "na" and "nana" = 2
lcp[5] = Longest Common Prefix of "nana" and None = 0
*/

// ####    kasai’s Algorithm  ####

// C++ program for building LCP array for given text 
#include <bits/stdc++.h> 
using namespace std; 

// Structure to store information of a suffix 
struct suffix 
{ 
	int index; // To store original index 
	int rank[2]; // To store ranks and next rank pair 
}; 

// A comparison function used by sort() to compare two suffixes 
// Compares two pairs, returns 1 if first pair is smaller 
int cmp(struct suffix a, struct suffix b) 
{ 
	return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): 
		(a.rank[0] < b.rank[0] ?1: 0); 
} 

// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
vector<int> buildSuffixArray(string txt, int n) 
{ 
	// A structure to store suffixes and their indexes 
	struct suffix suffixes[n]; 

	// Store suffixes and their indexes in an array of structures. 
	// The structure is needed to sort the suffixes alphabatically 
	// and maintain their old indexes while sorting 
	for (int i = 0; i < n; i++) 
	{ 
		suffixes[i].index = i; 
		suffixes[i].rank[0] = txt[i] - 'a'; 
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
	} 

	// Sort the suffixes using the comparison function 
	// defined above. 
	sort(suffixes, suffixes+n, cmp); 

	// At his point, all suffixes are sorted according to first 
	// 2 characters. Let us sort suffixes according to first 4 
	// characters, then first 8 and so on 
	int ind[n]; // This array is needed to get the index in suffixes[] 
	// from original index. This mapping is needed to get 
	// next suffix. 
	for (int k = 4; k < 2*n; k = k*2) 
	{ 
		// Assigning rank and index values to first suffix 
		int rank = 0; 
		int prev_rank = suffixes[0].rank[0]; 
		suffixes[0].rank[0] = rank; 
		ind[suffixes[0].index] = 0; 

		// Assigning rank to suffixes 
		for (int i = 1; i < n; i++) 
		{ 
			// If first rank and next ranks are same as that of previous 
			// suffix in array, assign the same new rank to this suffix 
			if (suffixes[i].rank[0] == prev_rank && 
					suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
			{ 
				prev_rank = suffixes[i].rank[0]; 
				suffixes[i].rank[0] = rank; 
			} 
			else // Otherwise increment rank and assign 
			{ 
				prev_rank = suffixes[i].rank[0]; 
				suffixes[i].rank[0] = ++rank; 
			} 
			ind[suffixes[i].index] = i; 
		} 

		// Assign next rank to every suffix 
		for (int i = 0; i < n; i++) 
		{ 
			int nextindex = suffixes[i].index + k/2; 
			suffixes[i].rank[1] = (nextindex < n)? 
								suffixes[ind[nextindex]].rank[0]: -1; 
		} 

		// Sort the suffixes according to first k characters 
		sort(suffixes, suffixes+n, cmp); 
	} 

	// Store indexes of all sorted suffixes in the suffix array 
	vector<int>suffixArr; 
	for (int i = 0; i < n; i++) 
		suffixArr.push_back(suffixes[i].index); 

	// Return the suffix array 
	return suffixArr; 
} 

/* To construct and return LCP */
vector<int> kasai(string txt, vector<int> suffixArr) 
{ 
	int n = suffixArr.size(); 

	// To store LCP array 
	vector<int> lcp(n, 0); 

	// An auxiliary array to store inverse of suffix array 
	// elements. For example if suffixArr[0] is 5, the 
	// invSuff[5] would store 0. This is used to get next 
	// suffix string from suffix array. 
	vector<int> invSuff(n, 0); 

	// Fill values in invSuff[] 
	for (int i=0; i < n; i++) 
		invSuff[suffixArr[i]] = i; 

	// Initialize length of previous LCP 
	int k = 0; 

	// Process all suffixes one by one starting from 
	// first suffix in txt[] 
	for (int i=0; i<n; i++) 
	{ 
		/* If the current suffix is at n-1, then we don’t 
		have next substring to consider. So lcp is not 
		defined for this substring, we put zero. */
		if (invSuff[i] == n-1) 
		{ 
			k = 0; 
			continue; 
		} 

		/* j contains index of the next substring to 
		be considered to compare with the present 
		substring, i.e., next string in suffix array 
		 把第几个与位数的互换。注意后面存的是 invSuff[i].
		 比如从i=0开始，banana, 用invSuff[0] 找到banana在原来的数组中是第3位，然后+1找到后面那个是什么（算法是跟sufffix[i+1]做比较）*/
		int j = suffixArr[invSuff[i]+1]; 

		// Directly start matching from k'th index as 
		// at-least k-1 characters will match 
		// 这个算法主要就是这步，为了直接用txt来比较，space可以优化
		while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
			k++; 

		lcp[invSuff[i]] = k; // 注意这里不是存i, 而是存 invSuff[i].  

		// Deleting the starting character from the string. 
		if (k>0) 
			k--; 
	} 

	// return the constructed lcp array 
	return lcp; 
} 

// Utility function to print an array 
void printArr(vector<int>arr, int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program 
int main() 
{ 
	string str = "banana"; 

	vector<int>suffixArr = buildSuffixArray(str, str.length()); 
	int n = suffixArr.size(); 

	cout << "Suffix Array : \n"; 
	printArr(suffixArr, n); 

	vector<int>lcp = kasai(str, suffixArr); 

	cout << "\nLCP Array : \n"; 
	printArr(lcp, n); 
	return 0; 
} 














