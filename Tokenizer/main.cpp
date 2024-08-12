#include "Tokenizer.h"

int main() {
    std::string input = R"(
        si (x == 10) {
            reditus verus;
        } dum (x < 10) {
            x = x + 1;
        }
        // This is a comment
        /* Multi-line
           comment */
    )";

    std::vector<Token> tokens = tokenize(input);
    printTokens(tokens);

    return 0;

}