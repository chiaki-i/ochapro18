#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

/////// 1.4 ////////
bool isPalindrome(string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    sort(word.begin(), word.end());
    int counter = 0;
    int result_counter = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ' '){
            continue;
        } else if (word[i] == word[i + 1]) {
            counter = (counter + 1) % 2;
        } else {
            counter = (counter + 1) % 2;
            if (counter == 1) {
                result_counter += 1;
                counter = 0;
            }
        }
    }
    if (result_counter <= 1){
        return true;
    } else {
        return false;
    }
}

/////// 1.5 ////////
bool isSame(string word1, string word2){
    if (word1 == word2) {
        return true;
    } else {
        int counter = 0;
        int counter_rev = 0;
        for (int i = 0; i < word1.length(); i++){
            if (word1[i] != word2[i]){
                counter = i;
                break;
            }
        }
        for (int j = 0; j < word1.length(); j++){
            string copied1 = word1;
            string copied2 = word2;
            reverse(copied1.begin(), copied1.end());
            reverse(copied2.begin(), copied2.end());
            if (copied1[j] != copied2[j]) {
                counter_rev = j;
                break;
            }
        }
        if (counter + counter_rev + 1 == word1.length()){
            return true;
        } else {
            return false;
        }
    }
}

bool isLonger(string word1, string word2){
    for (int i = 0; i < word1.length(); i++){
        string copied = word2; //local copy
        copied.insert(i, ".");
        if (isSame(word1, copied)){
            return true;
        }
    }
    return false;
}

bool isOneStep(string word1, string word2){
    int len1 = word1.length();
    int len2 = word2.length();
    if (len1 == len2){
        return isSame(word1, word2);
    } else if (len1 == len2 + 1){
        return isLonger(word1, word2);
    } else if (len1 + 1 == len2){
        return isLonger(word2, word1);
    } else {
        return false;
    }
}

/////// 1.6 ///////
// iterator
string condense(string word){
    string result = "";
    for(string::iterator itr = word.begin(); itr != word.end(); ){
        int counter = 0;
        string::iterator tmp = itr;
        while (*itr == *tmp){
            counter++;
            tmp++;
        }
        result += *itr;
        result += to_string(counter);
        itr = tmp;
    }
    if (word.length() <= result.length()){
        return word;
    } else {
        return result;
    }
}


/////// tests ///////
void test4(string arg, bool expected){
    bool answer = isPalindrome(arg);
    cout << boolalpha; // to show "true" instead of "1"
    if (answer == expected) {
        cout << "PASS. " << arg << ": " << expected << "\n";
    } else {
        cout << "FAIL. " << arg << " should be " << expected << " but was " << answer << "\n";
    }
}

void test5(string arg1, string arg2, bool expected){
    bool answer = isOneStep(arg1, arg2);
    if (answer == expected) {
        cout << boolalpha; // to show "true" instead of "1"
        cout << "PASS. " << arg1 << " and " << arg2 << ": " << expected << "\n";
    } else {
        cout << boolalpha;
        cout << "FAIL. " << arg1 << " and " << arg2 << " should be " << expected << " but was " << answer << "\n";
    }
}

void test6(string arg, string expected){
    string answer = condense(arg);
    if (answer == expected){
        cout << "PASS. " << arg << ": " << expected << "\n";
    } else {
        cout << "FAIL. " << arg << " should be " << expected;
        cout << " but was " << answer << "\n";
    }
}

int main(){
    std::cout << "=== 1.4 started ====\n";
    test4("1", true);
    test4("a", true);
    test4(" ", true);
    test4("aa", true);
    test4("abc", false);
    test4("madam", true);
    test4("madam1", false);
    test4("ootee ", true);
    test4("Tact Coa", true);
    test4("TactCoaPAPA", true);
    std::cout << "=== 1.4 finished ===\n";
    std::cout << "=== 1.5 started ====\n";
    test5("same", "same", true);
    test5("same", "samee", true);
    test5("apple", " apple", true);
    test5("apple", "aple", true);
    test5("bake", "pale", false);
    test5("hippo", "elephant", false);
    std::cout << "=== 1.5 finished ===\n";
    std::cout << "=== 1.6 started ====\n";
    test6("a", "a");
    test6("abc", "abc");
    test6("aabccccc", "a2b1c5");
    test6("ABC", "ABC");
    test6("BBBBB", "B5");
    test6("aabcd", "aabcd"); // a2b1c1d1 is longer
    test6("aabcccccaaa", "a2b1c5a3");
    std::cout << "=== 1.6 finished ===\n";
    return 0;
};

