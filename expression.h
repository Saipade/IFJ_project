/**
 * PROJECT: Implementation of imperative IFJ21 programming language compiler
 * PART: Expression processing
 * 
 * AUTHOR(S): Maksim Tikhonov (xtikho00)
 *            Sadovskyi Dmytro (xsadov06)
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "parser.h"

#define IS_I(SYMBOL)						    \
	   SYMBOL == INT						    \
	|| SYMBOL == NUM						    \
	|| SYMBOL == STR					        \
	|| SYMBOL == NIL                            \
    || SYMBOL == IDE


typedef enum {

    S,                  // shift
    R,                  // reduce
    E,                  // equal
    B,                  // blank -- not defined

} pt_operation;

typedef enum {

    INT,                // integer
    NUM,                // number
    STR,                // string
    BOO,                // boolean  
    NIL,                // nil

    NDA,                // not defined

    IDE,                // identifier
    NONTERM,            // non-terminal

    ADD,                // +
    SUB,                // -
    MUL,                // *
    DIV,                // /
    IDI,                // //
    CAT,                // ..
    LEN,                // #

    LTH,                // <
    LET,                // <=
    MTH,                // >
    MET,                // >= 
    EQU,                // ==
    NEQ,                // ~=

    LBR,                // (
    RBR,                // )

    DOL,                // $
    STOP,               // stop sign
    

} pt_symbol;

typedef enum {

    E_RULE,            // E -> i

    LEN_E,             // E -> # E

    E_PLUS_E,         // E -> E + E
    E_MINUS_E,        // E -> E - E
    E_MUL_E,          // E -> E * E
    E_DIV_E,          // E -> E / E
    E_IDIV_E,         // E -> E // E
    E_CAT_E,          // E -> E .. E

    E_LTH_E,          // E -> E < E
    E_LET_E,          // E -> E <= E
    E_MTH_E,          // E -> E > E
    E_MET_E,          // E -> E >= E
    E_EQU_E,          // E -> E == E
    E_NEQ_E,          // E -> E ~= E

    LBR_E_RBR,        // E -> ( E )

    ND_RULE,

} pt_rule;

typedef enum {

    I_PLUSMINUS,
    I_MULDIV,
    I_CMP,
    I_LBR,
    I_RBR,
    I_i,
    I_LEN,
    I_CAT,
    I_DOLLAR,

} pt_index;

/**
 * @brief Auxiliary function, converts token to symbol
 * @param parserData contains token information
 * @return Symbol
 */
pt_symbol convert_token2symbol ( Parser_data *parserData );

/**
 * @brief Auxiliary function, converts token to data type
 * @param parserData contains token information
 * @return Data type
 */
Data_type convert_token2type( Parser_data *parserData );

/**
 * @brief Auxiliary function, checks if token's value is zero
 * @param parserData contains token information
 * @return True if value is zero
 */
bool check_if_zero ( Parser_data *parserData );

/**
 * @brief Converts given symbol to precedence table index
 * @param symbol symbol
 * @return Precedence table index
 */
pt_index get_pt_index ( pt_symbol symbol );

/**
 * @brief Applies <expression> rule
 * @param parserData contains all required information
 * @return Error code
 */
int rule_expression ( Parser_data *parserData );

#endif