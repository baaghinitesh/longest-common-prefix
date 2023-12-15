// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize <= 0) {
        return "";  // Return an empty string if the array is empty
    }

    // Allocate memory for the result array
    char *charArray = (char *)malloc(200 * sizeof(char));

    int count = 0;

    // Iterate through characters of the first string
    while (strs[0][count] != '\0') {
        charArray[count] = strs[0][count];
        count++;
    }

    // Reset the count
    count = 0;

    // Iterate through each string in the array
    for (int i = 0; i < strsSize; i++) {
        int j;

        // Iterate through characters of the current string
        for (j = 0; strs[i][j] != '\0'; j++) {
            if (charArray[j] != '\0') {
                if (strs[i][j] != charArray[j]) {
                    break;  // Break if a mismatch is found
                }
            } else {
                break;  // Break if we reach the end of the current prefix
            }
        }

        // Set null terminator at the end of the common prefix
        charArray[j] = '\0';

        // Update the count to the length of the new common prefix
        count = j;
    }

    return charArray;
}