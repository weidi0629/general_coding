/* sort the suffix

  Let the given string be "banana".

  0 banana                          5 a
  1 anana     Sort the Suffixes     3 ana
  2 nana      ---------------->     1 anana  
  3 ana        alphabetically       0 banana  
  4 na                              4 na   
  5 a                               2 nana

  So the suffix array for "banana" is {5, 3, 1, 0, 4, 2}
  
  */
  
  // Naive algorithm for building suffix array of a given text 
#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

// Structure to store information of a suffix 
struct suffix 
{ 
	int index; 
	char *suff; 
}; 

// A comparison function used by sort() to compare two suffixes 
int cmp(struct suffix a, struct suffix b) 
{ 
	return strcmp(a.suff, b.suff) < 0? 1 : 0; // sorting is nlogn, then strcmp is n, so n^2*logn 
} 

// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
int *buildSuffixArray(char *txt, int n) 
{ 
	// A structure to store suffixes and their indexes 
	struct suffix suffixes[n]; 

	// Store suffixes and their indexes in an array of structures. 
	// The structure is needed to sort the suffixes alphabatically 
	// and maintain their old indexes while sorting 
	for (int i = 0; i < n; i++) 
	{ 
		suffixes[i].index = i; 
		suffixes[i].suff = (txt+i);  // 是一个char*, +i 就是它的起始位置
	} 

	// Sort the suffixes using the comparison function 
	// defined above. 
	sort(suffixes, suffixes+n, cmp); 

	// Store indexes of all sorted suffixes in the suffix array 
	int *suffixArr = new int[n]; 
	for (int i = 0; i < n; i++) 
		suffixArr[i] = suffixes[i].index; 

	// Return the suffix array 
	return suffixArr; 
} 

// A utility function to print an array of given size 
void printArr(int arr[], int n) 
{ 
	for(int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	char txt[] = "banana"; 
	int n = strlen(txt); 
	int *suffixArr = buildSuffixArray(txt, n); 
	cout << "Following is suffix array for " << txt << endl; 
	printArr(suffixArr, n); 
	return 0; 
} 


###############################  how to search a pattern ##############################

// A suffix array based search function to search a given pattern 
// 'pat' in given text 'txt' using suffix array suffArr[] 
void search(char *pat, char *txt, int *suffArr, int n) 
{ 
	int m = strlen(pat); // get length of pattern, needed for strncmp() 

	// Do simple binary search for the pat in txt using the 
	// built suffix array 
	int l = 0, r = n-1; // Initilize left and right indexes 
	while (l <= r) 
	{ 
		// See if 'pat' is prefix of middle suffix in suffix array 
		int mid = l + (r - l)/2; 
		int res = strncmp(pat, txt+suffArr[mid], m); //指针往前移动的的长度， m 表示只判断 m 位

		// If match found at the middle, print it and return 
		if (res == 0) 
		{ 
			cout << "Pattern found at index " << suffArr[mid]; 
			return; 
		} 

		// Move to left half if pattern is alphabtically less than 
		// the mid suffix 
		if (res < 0) r = mid - 1; 

		// Otherwise move to right half 
		else l = mid + 1; 
	} 

	// We reach here if return statement in loop is not executed 
	cout << "Pattern not found"; 
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "banana"; // text 
	char pat[] = "nan"; // pattern to be searched in text 

	// Build suffix array 
	int n = strlen(txt); 
	int *suffArr = buildSuffixArray(txt, n); 

	// search pat in txt using the built suffix array 
	search(pat, txt, suffArr, n); 

	return 0; 
} 


################### faster way to construct suffix array  ###########################  
/*
https://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/

主要依靠的是所有的都是来自同一个string 的 suffix
struct rank有两列一直在变化。首先靠第一列把大组分好，然后第二列再细分，而第二列在一直以2*i在往前走(logn)，所以比起之前的Strcmp(n)要快.

*/

// C++ program for building suffix array of a given text 
#include <iostream> 
#include <cstring> 
#include <algorithm> 
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
int *buildSuffixArray(char *txt, int n) 
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

	// At this point, all suffixes are sorted according to first 
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
		
		/*
		  这里有个非常tricky的地方： 小的index加多少，就是那个index对应的string. 比如banana index是0， 加上2之后，就是banana第二个字符
		  开始的nana, 也就是index =2 的string. 所以上门ind就是一个记录之前的index现在在suffixes数组里的第几个。也就是大组分好里面分小组，
		  利用了这个tricky的性质，小组已经在分大组时分好了。在此体会下之前tutoril里说的：
		  The idea is to use the fact that strings that are to be sorted are suffixes of a single string.
		  
		  Index       Suffix           
		  5          a                
		  1          anana               
		  3          ana             
		  0          banana           
		  2          nana             
		  4          na             	  
		*/

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
	int *suffixArr = new int[n]; 
	for (int i = 0; i < n; i++) 
		suffixArr[i] = suffixes[i].index; 

	// Return the suffix array 
	return suffixArr; 
} 

// A utility function to print an array of given size 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	char txt[] = "banana"; 
	int n = strlen(txt); 
	int *suffixArr = buildSuffixArray(txt, n); 
	cout << "Following is suffix array for " << txt << endl; 
	printArr(suffixArr, n); 
	return 0; 
} 























