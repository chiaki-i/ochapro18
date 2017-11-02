#include<string>
#include<iostream>

///// 1.1 /////
bool isUniqueChars(std::string str){
    std::sort(str.begin(), str.end());
    for(std::string::iterator itr = str.begin(); itr != str.end(); ++itr){
        std::string::iterator next = itr;
        next++;
        if(*itr == *next){
            return false;
        }
    }
    return true;
}

///// 1.2 /////
bool isPermutation(std::string str1, std::string str2){
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1 == str2){
        return true;
    } else {
        return false;
    }
}

///// 1.3 /////
std::string urlify(std::string str, int len){
    str.erase(len); // delete space(s) at the end
    int spaces = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            spaces++;
        }
    }
    int answerlen = len + spaces*2;
    for (int i = 0; i < answerlen; i++){
        if(str[i] == ' '){
            str.erase(str.begin() + i);
            str.insert(i, "%20");
        }
    }
    return str;
}

///// test /////
void test1(std::string arg, bool expected){
    bool answer = isUniqueChars(arg);
    if (answer == expected){
        std::cout << "PASS. " << arg << ": " << answer << "\n";
    } else {
        std::cout << "FAIL. " << arg << " should be " << expected;
        std::cout << " but was " << answer << "\n";
    }
}

void test2(std::string arg1, std::string arg2, bool expected){
    bool answer = isPermutation(arg1, arg2);
    if (answer == expected){
        std::cout << "PASS. " << arg1 << " & " << arg2 << ": " << answer << "\n";
    } else {
        std::cout << "FAIL. " << arg1 << " & " << arg2 << " should be " << expected;
        std::cout << " but was " << answer << "\n";
    }
}

void test3(std::string arg1, int arg2, std::string expected){
    std::string answer = urlify(arg1, arg2);
    if (answer == expected){
        std::cout << "PASS. " << arg1 << " (" << arg2 << "): " << answer << "\n";
    } else {
        std::cout << "FAIL. " << arg1 << " (" << arg2 << ") should be " << expected;
        std::cout << " but was " << answer << "\n";
    }
}

int main(){
    std::cout << std::boolalpha;
    std::cout << "=== 1.1 started ==== \n";
    test1(" ", true);
    test1("a", true);
    test1("ab", true);
    test1("aa", false);
    test1("abca", false);
    test1("pqbex", true);
    std::cout << "=== 1.1 finished === \n";
    std::cout << "=== 1.2 started ==== \n";
    test2("a", "a", true);
    test2("a", "b", false);
    test2("a", "aa", false);
    test2("ab", "ba", true);
    test2("pcak", "pack", true);
    test2("eel", "feel", false);
    std::cout << "=== 1.2 finished === \n";
    std::cout << "=== 1.3 started ==== \n";
    test3(" ", 0, "");
    test3("a", 1, "a");
    test3("a ", 1, "a");
    test3(" a ", 2, "%20a");
    test3("a b ", 3, "a%20b");
    test3("Mr John Smith ", 13, "Mr%20John%20Smith");
    std::cout << "=== 1.3 finished === \n";
    
    return 0;
}
