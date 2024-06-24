#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the shortest transformation sequence
// from startWord to endWord using the wordList
int wordLadder(string startWord, string endWord, vector<string>& wordList) {
    // Initialize an unordered set with the words from wordList
    unordered_set<string> st(wordList.begin(), wordList.end());
    
    // If endWord is not in the wordList, return 0
    if (st.find(endWord) == st.end()) return 0;

    // Initialize a queue for BFS with startWord and step count 1
    queue<pair<string, int>> q;
    q.push({startWord, 1});

    // Erase startWord from the set to avoid revisiting
    st.erase(startWord);

    // BFS loop
    while (!q.empty()) {
        // Get the front element from the queue
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        // If the current word is the endWord, return the number of steps
        if (word == endWord) return steps;

        // Try changing each character of the word to find all possible transformations
        for (int i = 0; i < word.length(); i++) {
            char original = word[i]; // Save the original character

            // Change the character to every possible lowercase letter
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                // If the new word is in the set, add it to the queue and remove from set
                if (st.find(word) != st.end()) {
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }

            word[i] = original; // Restore the original character
        }
    }

    // If there is no transformation sequence, return 0
    return 0;
}

int main() {
    // Define the startWord, endWord, and wordList for testing
    string startWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    // Call the wordLadder function and print the result
    int result = wordLadder(startWord, endWord, wordList);
    cout << "The length of the shortest transformation sequence is: " << result << endl;

    return 0;
}
