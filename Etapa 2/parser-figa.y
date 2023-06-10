%{
int yyerror(char *s);
%}
       
%token KW_INT           
%token KW_REAL    
%token KW_CHAR            
%token KW_LIT_STRING
%token KW_BOOL           

%token KW_IF             
%token KW_THEN           
%token KW_ELSE           
%token KW_LOOP           
%token KW_INPUT          
%token KW_OUTPUT         
%token KW_RETURN         

%token OPERATOR_LE       
%token OPERATOR_GE       
%token OPERATOR_EQ       
%token OPERATOR_DIF      

%token TK_IDENTIFIER     

%token LIT_INT           
%token LIT_REAL          
%token LIT_CHAR          
%token LIT_STRING      

%token TOKEN_ERROR 

%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_DIF
%left '&' '|' '~'
%left '+' '-'
%left '*' '/'

%start program

%%

program : decleration program                 
        |                             
        ; 

decleration : variable_declaration
            | function_declaration
            ;

variable_declaration : variable_type TK_IDENTIFIER '=' variable_value ';' 
                     | variable_type TK_IDENTIFIER '[' LIT_INT ']' vector_initialization ';'
                     ;
 
variable_type   : KW_INT
                | KW_CHAR  
                | KW_REAL
                ;

variable_value  : LIT_INT
                | LIT_CHAR  
                | LIT_REAL
                ;

vector_initialization   : '=' vector_content 
                        | 
                        ;

vector_content : variable_value vector_content
               |
               ;


function_declaration : variable_type TK_IDENTIFIER '(' parameters ')' block
                     ;

parameter_single : variable_type TK_IDENTIFIER
                 ;

parameter_multiple : ',' parameter_single parameter_multiple
                   |
                   ;
           
parameters  : parameter_single parameter_multiple 
            |
            ;  

block   :   
        | '{' command_sequence '}'  
        ;
 
command_sequence: command ';' command_sequence  
                |
                ;

command : block
        | command_attribution
        | command_control
        | command_output
        | command_return
        ; 

command_output  : KW_OUTPUT output_type
                | KW_OUTPUT output_multiple
                ;

output_type : LIT_STRING 
            | LIT_INT
            ; 

output_multiple : output_type ',' output_multiple
                | output_type
                ;

command_attribution : TK_IDENTIFIER '=' expression
                    | TK_IDENTIFIER '[' expression_int ']' '=' expression 
                    ;

command_return  : KW_RETURN expression
                ;


function_call   : TK_IDENTIFIER '(' call_parameters ')'
                ;
 

call_parameters : expression
                : expression ',' call_parameters
                ;

expression  : expression operator expression
            | '(' expression ')' 
            | TK_IDENTIFIER
            | TK_IDENTIFIER '[' expression_int ']'
            | variable_value
            | function_call
            | KW_INPUT '(' variable_type ')'
            ;
 

operator: '+'
        | '-'
        | '*'
        | '/'
        | '>'
        | '<'
        | OPERATOR_LE
        | OPERATOR_GE
        | OPERATOR_EQ
        | OPERATOR_DIF
        | '&'
        | '|'
        | '~'
        ; 
        
operator_int    : '+'
                | '-'
                | '*'
                | '/' 
                | '&'
                | '|'
                | '~'
                ; 


expression_int  : expression_int operator_int expression_int
                | '(' expression_int ')'
                | TK_IDENTIFIER
                | TK_IDENTIFIER '[' expression_int ']'
                | LIT_INT
                | function_call
                ;
   
command_control : KW_IF '(' expression ')' command
                | KW_IF '(' expression ')' command KW_THEN command
                | KW_IF '(' expression ')' KW_LOOP command
                ;
 
%%

int yyerror(char *error)
{
     fprintf("syrax error in line %d", getlinenumber());
     exit(3); //3 por razões do professor. Erro de sintaxe.
}