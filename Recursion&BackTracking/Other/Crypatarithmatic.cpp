#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
private:
    // State variables for the backtracking process
    map<char, int> letters_to_digits;
    vector<bool> digits_is_used;
    set<char> leading_letters;

    // Helper function to convert a word to its number value
    long long wordToNumber(const string& word) {
        long long number = 0;
        for (char c : word) {
            number = number * 10 + letters_to_digits[c];
        }
        return number;
    }

    // The main recursive backtracking function
    bool solve(const vector<char>& unique_letters, int index, const vector<string>& puzzles) {
        // --- Base Case: All unique letters have been assigned a digit ---
        if (index == unique_letters.size()) {
            // Now, verify if the equation holds true.
            long long val1 = wordToNumber(puzzles[0]);
            long long val2 = wordToNumber(puzzles[1]);
            long long val3 = wordToNumber(puzzles[2]);

            if (val1 + val2 == val3) {
                // Solution found! Print it.
                cout << "Solution found: ";
                for (auto const& pair : letters_to_digits) {
                    cout << pair.first << " = " << pair.second << ", ";
                }
                cout << endl;
                return true; // Signal that we found a solution
            }
            // This assignment was incorrect.
            return false;
        }

        // --- Recursive Step: Try to assign a digit to the current letter ---
        char current_letter = unique_letters[index];

        // Loop through all possible digits (0-9)
        for (int digit = 0; digit <= 9; digit++) {
            // Constraint 1: Check if the digit is already used.
            if (digits_is_used[digit]) {
                continue;
            }

            // Constraint 2: Check for leading zeros.
            if (leading_letters.find(current_letter) != leading_letters.end() && digit == 0) {
                continue;
            }

            // --- Choose ---
            letters_to_digits[current_letter] = digit;
            digits_is_used[digit] = true;

            // --- Explore ---
            if (solve(unique_letters, index + 1, puzzles)) {
                return true; // If a solution is found down this path, we're done.
            }

            // --- Unchoose (Backtrack) ---
            // If the exploration failed, undo the choice.
            digits_is_used[digit] = false;
        }

        // If no digit worked for the current letter, this path fails.
        return false;
    }

public:
    // Public entry function to set up and start the process.
    void solveCryptarithmetic(const vector<string>& puzzles) {
        set<char> unique_chars_set;
        // Preprocessing: Get unique letters and identify leading letters.
        for (const string& word : puzzles) {
            if (word.length() > 0) {
                leading_letters.insert(word[0]);
            }
            for (char c : word) {
                unique_chars_set.insert(c);
            }
        }
        
        vector<char> unique_letters(unique_chars_set.begin(), unique_chars_set.end());
        digits_is_used.assign(10, false); // Reset used digits vector

        // Start the recursive backtracking process.
        if (!solve(unique_letters, 0, puzzles)) {
            cout << "No solution found." << endl;
        }
    }
};

int main() {
    vector<string> puzzles = {"SEND", "MORE", "MONEY"};
    Solution s;
    s.solveCryptarithmetic(puzzles);

    return 0;
}