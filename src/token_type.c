enum token_type {
    // single character
    L_PAR,
    R_PAR,
    L_SQB,
    R_SQB,
    SEMIC, // semicolon
    COMMA, // arrays
    COLON, // type specification
        
    // multiple characters

    // literals
    IDENT, // identifier
    STRIN, 
    INTEG, 
    FLOAT, 
    TRUE,  // true
    FALS,  // false
    
    // keywords
    SET,
    FUN,
    CAL,
    NIL
};

typedef enum token_type token_type;
