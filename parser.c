#include "parser.h"

Program* parseProgram(FILE *file) {
    Token *token = getNextToken(file);

    // Expecting "return" keyword
    if (token && token->type == RETURN) {
        token = getNextToken(file);
        if (token && token->type == CONSTANT) {
            // Create the AST for the return statement
            Expression *exp = createConstant(token->value);
            Statement *stmt = createReturnStatement(exp);
            Function *func = createFunction("main", stmt);
            Program *prog = createProgram(func);
            freeToken(token);  // Free token after using it
            return prog;
        }
    }

    return NULL;  // Invalid program
}
