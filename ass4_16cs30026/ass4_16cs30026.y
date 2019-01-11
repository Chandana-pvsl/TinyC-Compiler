%{
	#define YYSTYPE double
	#include <ctype.h>
	#include <stdio.h>
	void yyerror(const char*);
	extern int yylex();

%}
%token TYPEDEF EXTERN STATIC AUTO REGISTER INLINE RESTRICT
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token BOOL COMPLEX IMAGINARY
%token STRUCT UNION ENUM
%token BREAK CASE CONTINUE DEFAULT DO IF ELSE FOR GOTO WHILE SWITCH SIZEOF
%token RETURN
%token IDENTIFIER  STRING_LITERAL
%token INTEGER_CONSTANT FLOATING_CONSTANT ENUM_CONSTANT CHAR_CONSTANT
%token ELLIPSE ASSIGN ASSIGN_RS ASSIGN_LS ASSIGN_ADD ASSIGN_SUB ASSIGN_MUL 
%token ASSIGN_DIV ASSIGN_MODULO ASSIGN_BIT_AND ASSIGN_BIT_XOR ASSIGN_BIT_OR RS LS 
%token INCREMENT DECREMENT  AND OR LTE GTE EQ NEQ LT GT ARROW
%token BIT_AND BIT_OR BIT_XOR


%start translation_unit
%right THEN ELSE

%%
primary_expression:
			IDENTIFIER 					{printf("primary_expression-> identifier \n");}
			|constant 					{printf("primary_expression-> constant \n");}
			|STRING_LITERAL 			{printf("primary_expression-> string literal \n");}
			|'(' expression ')' 		{printf("primary_expression-> expression \n");}

;

constant:
		INTEGER_CONSTANT 		{printf("constant->integer constant \n");}
		|FLOATING_CONSTANT 		{printf("constant->floating constant \n");}
		|ENUM_CONSTANT			{printf("constant->enumeration constant \n");}
		|CHAR_CONSTANT			{printf("constant->character constant \n");}
;
postfix_expression:
			primary_expression 								{printf("postfix expression-> primary expression\n");}
			|postfix_expression '[' expression ']' 			{printf("postfix expression-> postfix_expression [expression] \n");}
			|postfix_expression '(' argument_expression_list_opt ')' 	{printf("postfix expression-> postfix_expression (argument_expression_list_opt) \n");}         
			|postfix_expression '.' IDENTIFIER 				{printf("postfix expression-> postfix_expression.IDENTIFIER \n");}	
			|postfix_expression ARROW IDENTIFIER  			{printf("postfix expression-> postfix_expression ARROW IDENTIFIER \n");}	
			|postfix_expression INCREMENT 					{printf("postfix expression-> postfix_expression INCREMENT \n");}	
			|postfix_expression DECREMENT 					{printf("postfix expression-> postfix_expression DECREMENT \n");}	
			|'(' type_name ')' '{' initializer_list '}' 	{printf("postfix expression-> (type_name) {initializer_list} \n");}	
			|'(' type_name ')' '{'initializer_list ',' '}' 	{printf("postfix expression-> (type_name)  {initializer_list,} \n");}	
;

argument_expression_list_opt:
			argument_expression_list 					{printf("argument_expression_list \n");}	
			|
;

argument_expression_list:
			assignment_expression 						{printf("argument_expression \n");}
			|argument_expression_list ',' assignment_expression  		{printf("argument_expression_list, assignment_expression \n");}
;

unary_expression:
			postfix_expression 						{printf("unary expression -> postfix_expression");}
			|INCREMENT unary_expression 			{printf("unary expression -> ++unary_expression");}
			|DECREMENT unary_expression 			{printf("unary expression -> --unary_expression");}
			|unary_operator cast_expression 		{printf("unary expression -> unary_operator cast_expression");}
			|SIZEOF unary_expression 				{printf("unary expression -> sizeof unary_expression");}
			|SIZEOF '(' type_name ')' 				{printf("unary expression -> sizeof (type-name) ");}
;

unary_operator:
			BIT_AND  								{printf("unary operator-> &\n");}
			|'*'									{printf("unary operator-> *\n");}
			|'+' 									{printf("unary operator-> +\n");}
			|'-' 									{printf("unary operator-> -\n");}
			|'~'									{printf("unary operator-> ~\n");}
			|'!'									{printf("unary operator-> !\n");}
;

cast_expression:
			unary_expression 						{printf("cast-expression-> unary-expression\n");}
			|'(' type_name ')' cast_expression 		{printf("cast-expression-> (type_name) cast_expression n\n");}
;

multiplicative_expression:
			cast_expression 						{printf("multiplicative-expression-> cast-expression\n");}
			|multiplicative_expression'*' cast_expression 		{printf("multiplicative-expression->multiplicative-expression * cast-expression\n");}
			|multiplicative_expression '/' cast_expression 		{printf("multiplicative-expression-> multiplicative-expression / cast-expression\n");}
			|multiplicative_expression '%' cast_expression 		{printf("multiplicative-expression-> multiplicative-expression %% cast-expression\n");}

additive_expression:
			multiplicative_expression 						{printf("additive-expression-> multiplicative-expression\n");}
			|additive_expression '+' multiplicative_expression 	{printf("additive-expression-> additive-expression + multiplicative-expression\n");}
			|additive_expression '-' multiplicative_expression 	{printf("additive-expression-> additive-expression - multiplicative-expression\n");}
;

shift_expression:
			additive_expression 							{printf("shift-expression-> additive-expression\n");}
			|shift_expression LS additive_expression 		{printf("shift-expression-> shift_expression << additive-expression\n");}
			|shift_expression RS additive_expression 		{printf("shift-expression-> shift_expression >>additive-expression\n");}
;

relational_expression:
			shift_expression 								{printf("relational-expression -> shift-expression\n");}
			|relational_expression LT shift_expression  	{printf("relational-expression -> relational_expression < shift-expression\n");}
			|relational_expression GT shift_expression 		{printf("relational-expression -> relational_expression > shift-expression\n");}
			|relational_expression LTE shift_expression 	{printf("relational-expression -> relational_expression <=  shift-expression\n");}
			|relational_expression GTE shift_expression 	{printf("relational-expression -> relational_expression >= shift-expression\n");}
;

equality_expression:
			relational_expression 							{printf("equality-expression -> relational_expression\n");}
			|equality_expression EQ relational_expression 	{printf("equality-expression -> equality_expression == relational-expression\n");}
			|equality_expression NEQ relational_expression 	{printf("equality-expression -> equality_expression != relational-expression\n");}
;

AND_expression:
			equality_expression 							{printf("AND-expression -> equality-expression\n");}
			|AND_expression BIT_AND equality_expression 	{printf("AND-expression -> AND_expression & equality_expression \n");}
;

exclusive_OR_expression:
			AND_expression 									{printf("exclusive_OR_expression -> AND_expression \n");}	
			|exclusive_OR_expression BIT_XOR AND_expression {printf("exclusive_OR_expression -> exclusive_OR_expression ^ AND_expression \n");}
;

inclusive_OR_expression:
			exclusive_OR_expression 						{printf("inclusive_OR_expression->exclusive_OR_expression\n");}
			|inclusive_OR_expression BIT_OR exclusive_OR_expression 	{printf("inclusive_OR_expression->inclusive_OR_expression | exclusive_OR_expression\n");}
;

logical_AND_expression:
			inclusive_OR_expression 				{printf("logical_AND_expression->inclusive_OR_expression\n");}		
			|logical_AND_expression AND inclusive_OR_expression 		{printf("logical_AND_expression->logical_AND_expression && inclusive_OR_expression\n");}
;

logical_OR_expression:
			logical_AND_expression 			{printf("logical_OR_expression->logical_AND_expression\n");}
			|logical_OR_expression OR logical_AND_expression 		{printf("logical_OR_expression->logical_OR_expression || logical_AND_expression\n");}
;

conditional_expression:
			logical_OR_expression 			{printf("conditional-expression->logical_OR_expression\n");}
			|logical_OR_expression '?' expression ':' conditional_expression 	{printf("conditional-expression->logical_OR_expression ? expression : conditional_expression\n");}
;


assignment_expression:
			conditional_expression 			{printf("assignment_expression->conditional_expression\n");}
			|unary_expression assignment_operator assignment_expression 		{printf("assignment_expression->unary_expression assignment_operator assignment_expression\n");}
;

assignment_operator:
			ASSIGN 				{printf("assignment_operator-> = \n");}
			|ASSIGN_MUL 		{printf("assignment_operator-> *= \n");}
			|ASSIGN_DIV  		{printf("assignment_operator-> /= \n");}
			|ASSIGN_MODULO 		{printf("assignment_operator-> %%= \n");}
			|ASSIGN_ADD			{printf("assignment_operator-> += \n");}
			|ASSIGN_SUB			{printf("assignment_operator-> -= \n");}
			|ASSIGN_LS			{printf("assignment_operator-> <<= \n");}
			|ASSIGN_RS 			{printf("assignment_operator-> >>= \n");}
			|ASSIGN_BIT_AND 	{printf("assignment_operator-> &= \n");}
			|ASSIGN_BIT_XOR 	{printf("assignment_operator-> ^= \n");}
			|ASSIGN_BIT_OR 		{printf("assignment_operator-> |= \n");}
;

expression_opt:
		expression 				{printf("expression_opt -> expression \n");}
		| 						{printf("expression_opt -> empty \n");}
;

expression:
			assignment_expression 	{printf("expression -> assignment-expression \n");}
			|expression ',' assignment_expression 	{printf("expression -> expression , assignment-expression \n");}
;

constant_expression:
			conditional_expression 			{printf("constant-expression \n");}
;

declaration:
			declaration_specifiers init_declarator_list ';' {printf("declaration ->declaration_specifiers initializer_list; \n");}
			|declaration_specifiers ';' 		{printf("declaration -> declaration_specifiers ; \n");}

;


declaration_specifiers:
			storage_class_specifier declaration_specifiers {printf("declaration_specifiers -> storage_class_specifier declaration_specifiers \n");}
			|storage_class_specifier 						{printf("declaration_specifiers -> storage_class_specifier \n");}
			|type_specifier declaration_specifiers 			{printf("declaration_specifiers -> type_specifier declaration_specifiers \n");}
			|type_specifier 								{printf("declaration_specifiers -> type_specifier \n");}
			|type_qualifier declaration_specifiers 			{printf("declaration_specifiers -> type_qualifier declaration_specifiers \n");}
			|type_qualifier 								{printf("declaration_specifiers -> type_qualifier \n");}
			|function_specifier declaration_specifiers 		{printf("declaration_specifiers -> function_specifier declaration_specifiers \n");}
			|function_specifier 								{printf("declaration_specifiers -> type_qualifier \n");}
;

init_declarator_list:
			init_declarator 								{printf("init_declarator_list -> init_declarator");}
			|init_declarator_list ',' init_declarator 		{printf("init_declarator_list -> init_declarator_list , init_declarator \n");}
;

init_declarator:
			declarator 										{printf("init-declarator -> declarator\n");}
			|declarator ASSIGN initializer 					{printf("init-declarator -> declarator = initializer\n");}
;

storage_class_specifier:
			EXTERN 							{printf("storage_class_specifier -> extern\n");}
			|STATIC 						{printf("storage_class_specifier -> static\n");}
			|AUTO   						{printf("storage_class_specifier -> auto\n");}
			|REGISTER						{printf("storage_class_specifier -> register\n");}
;

type_specifier:
			VOID 			{printf("type_specifier -> void\n");}
			|CHAR 			{printf("type_specifier -> char\n");}
			|SHORT 			{printf("type_specifier -> short\n");}
			|INT 			{printf("type_specifier -> int\n");}
			|LONG 			{printf("type_specifier -> long\n");}
			|FLOAT 			{printf("type_specifier -> float\n");}
			|DOUBLE 		{printf("type_specifier -> double\n");}
			|SIGNED 		{printf("type_specifier -> signed\n");}
			|UNSIGNED 		{printf("type_specifier -> unsigned\n");}
			|BOOL 			{printf("type_specifier -> _bool\n");}
			|COMPLEX 		{printf("type_specifier -> _complex\n");}
			|IMAGINARY 		{printf("type_specifier -> _imaginary\n");}
			|enum_specifier {printf("type_specifier -> enum_specifier\n");}
;

specifier_qualifier_list_opt:
			specifier_qualifier_list 	{printf("specifier_qualifier_list_opt-> specifier_qualifier_list\n");}
			|
;

specifier_qualifier_list:
			type_specifier specifier_qualifier_list_opt 		{printf("specifier_qualifier_list -> type_specifier specifier_qualifier_list_opt\n");}
			|type_qualifier specifier_qualifier_list_opt 		{printf("specifier_qualifier_list -> type_qualifier specifier_qualifier_list_opt\n");}
;


enum_specifier:
			ENUM identifier_opt '{' enumerator_list '}' 		{printf("enum specifier -> ENUM identifier_opt { enumerator_list }\n");}
			|ENUM identifier_opt '{' enumerator_list ',' '}'  	{printf("enum specifier -> ENUM identifier_opt { enumerator_list , }\n");}
			|ENUM IDENTIFIER 			{printf("enum specifier -> ENUM identifier\n");}
;

identifier_opt:
 			IDENTIFIER 				{printf("identifier_opt -> identifier\n");}
 			|
;

enumerator_list:
			enumerator 				{printf("enumerator_list -> enumerator \n");}
			|enumerator_list ',' enumerator 	{printf(" enumerator_list-> enumerator_list , enumerator \n");}
;

enumerator:
			IDENTIFIER 				{printf(" enumerator -> identifier \n");}
			|IDENTIFIER ASSIGN constant_expression 	{printf(" enumerator -> identifier = constant_expression \n");}
;

type_qualifier:
			CONST 				{printf(" type_qualifier -> const \n");} 				
			|RESTRICT 			{printf(" type_qualifier -> restrict \n");} 
			|VOLATILE 			{printf(" type_qualifier -> volatile \n");} 
;

function_specifier:
			INLINE 				{printf(" function-specifier -> inline \n");} 
;

declarator:
			pointer_opt direct_declarator {printf(" declarator -> pointer_opt direct_declarator \n");} 
;


direct_declarator:
			IDENTIFIER 					{printf(" direct_declarator -> identifier \n");} 
			|'(' declarator ')' 		{printf(" direct_declarator -> ( direct_declarator)\n");} 
			|direct_declarator '[' type_qualifier_list_opt assignment_expression ']' 		{printf(" direct_declarator-> [type_qualifier_list_opt assignment_expression ] \n");} 
			|direct_declarator '[' type_qualifier_list_opt ']' 		{printf(" direct_declarator-> [type_qualifier_list_opt ] \n");} 
			|direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression']' 	{printf(" direct_declarator-> [static type_qualifier_list_opt assignment_expression ] \n");} 
			|direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' 	{printf(" direct_declarator-> [type_qualifier_list static assignment_expression ] \n");} 
			|direct_declarator '[' type_qualifier_list_opt '*' ']' 	{printf(" direct_declarator-> [type_qualifier_list_opt *] \n");} 
			|direct_declarator '(' parameter_type_list ')' 	{printf(" direct_declarator-> direct_declarator (parameter_list)\n");} 
			|direct_declarator '('identifier_list_opt ')'  	{printf(" direct_declarator-> direct_declarator (identifier_list_opt)\n");} 
;

pointer_opt:
			pointer 			{printf(" pointer_opt -> pointer\n");} 
			|					{printf(" pointer_opt -> empty\n");} 
;

pointer:
			'*' type_qualifier_list_opt 		{printf(" pointer -> *type_qualifier_list_opt\n");} 
			|'*' type_qualifier_list_opt pointer {printf(" pointer -> *type_qualifier_list_opt pointer\n");} 
;

type_qualifier_list_opt:
			type_qualifier_list 			{printf(" type_qualifier_list_opt-> type_qualifier_list\n");} 
			|
;

type_qualifier_list:
			type_qualifier 					{printf(" type_qualifier_list-> type_qualifier\n");} 
			|type_qualifier_list type_qualifier  	{printf(" type_qualifier_list-> type_qualifier_list type_qualifier\n");} 
;

parameter_type_list:
			parameter_list 					{printf(" parameter_type_list-> parameter_list\n");} 
			|parameter_list ',' ELLIPSE 	{printf(" parameter_type_list-> parameter_list, ...\n");}

parameter_list:
			parameter_declaration 			{printf(" parameter_list-> parameter_declaration\n");}
			|parameter_list ',' parameter_declaration 	{printf(" parameter_list-> parameter_list, parameter_declaration\n");}
;

parameter_declaration:
			declaration_specifiers declarator 		{printf(" parameter_declaration-> declaration_specifiers declarator\n");}
			|declaration_specifiers  				{printf(" parameter_declaration-> declaration_specifiers \n");}
;

identifier_list_opt:
			identifier_list 					{printf(" identifier_list_opt-> identifier_list \n");}
			| 									{printf(" identifier_list_opt-> empty\n");}
;

identifier_list:
			IDENTIFIER 							{printf(" identifier_list-> identifier \n");}
			|identifier_list ',' IDENTIFIER 	{printf(" identifier_list-> identifier_list , identifier \n");}
;

type_name:
 			specifier_qualifier_list 			{printf(" type_name->specifier_qualifier_list \n");}
;

initializer:
			assignment_expression 				{printf("initializer-> assignment_expression \n");}
			|'{' initializer_list '}' 			{printf(" initializer->{initializer-list} \n");}
			| '{' initializer_list ',' '}'		{printf(" initializer->{initializer-list ,} \n");}
;

initializer_list:
			initializer 						{printf(" initializer_list->initializer \n");}
			|designation initializer 			 {printf(" initializer_list->designation initializer \n");}
			|initializer_list ',' initializer    {printf(" initializer_list->initializer_list , initializer \n");}
			|initializer_list ',' designation initializer 	{printf(" initializer_list->initializer_list, designation initializer \n");}
;

designation:
			designator_list ASSIGN 		{printf(" designation-> designator_list =  \n");}
;

designator_list:
			designator 						{printf(" designator_list-> designator\n");}
			|designator_list designator 		{printf(" designator_list-> designator_list designator\n");}
;

designator:
			'[' constant_expression ']' 		 {printf(" designator->[constant expression]\n");}
			|'.' IDENTIFIER 					 {printf(" designator-> .identifier\n");}
;

statement:
			labeled_statement 					{printf(" statement->labeled_statement\n");}
			|compound_statement		{printf(" statement->compound_statement\n");}
			|expression_statement	{printf(" statement->expression_statement\n");}
			|selection_statement 	{printf(" statement->selection_statement\n");}
			|iteration_statement 	{printf(" statement->iteration_statement\n");}
			|jump_statement 		{printf(" statement->jump_statement\n");}
;

labeled_statement:
			IDENTIFIER ':' statement 		{printf(" labeled_statement -> identifier : statement\n");}
			|CASE constant_expression ':' statement 	{printf(" labeled_statement ->CASE constant_expression ':' statement \n");}
			|DEFAULT ':' statement 		{printf(" labeled_statement -> DEFAULT : statement\n");}
;

compound_statement:
			'{' block_item_list '}'			 {printf(" compund_statement -> {block_item_list}	\n");}
			|'{' '}'						 {printf(" compund_statement -> {}	\n");}
;


block_item_list:
			block_item 					 {printf(" block_item_list -> block_item	\n");}
			|block_item_list block_item  {printf(" block_item_list -> block_item_list block_item	\n");}
;

block_item:
			declaration 				{printf(" block_item -> declaration	\n");}
			|statement 					{printf(" block_item ->statement\n");}
;

expression_statement: 					
			expression_opt ';' 			{printf(" expression_statement-> expression_opt	\n");}
;

selection_statement_base:
			IF '(' expression ')' statement 	{printf("selection_statement_base-> if (expression) statement	\n");}
;

selection_statement:
			selection_statement_base %prec THEN 		
			|selection_statement_base ELSE statement 	 {printf("selection_statement-> selection_statement_base else statement\n");}
			|SWITCH '(' expression ')' statement 		{printf("selection_statement-> switch (expression) statement\n");}
;

iteration_statement:
			WHILE '(' expression ')' statement 		 	{printf("iteration_statement-> while (expression) statement 	\n");}	
			|DO statement WHILE '(' expression ')' ';' 	{printf("iteration_statement-> do statement while (expression);	\n");}	
			|FOR '(' expression_opt ';'  expression_opt ';'  expression_opt ')' statement   {printf("iteration_statement-> for(expression_opt;expression_opt ;expression_opt ) statement \n");}	
			|FOR '(' declaration  expression_opt ';'  expression_opt ')' statement 		{printf("iteration_statement->for(declaration  expression_opt ;  expression_opt ) statement\n");}	
;

jump_statement:
			GOTO IDENTIFIER ';' 		{printf("jump_statement-> GOTO IDENTIFIER ; 	\n");}	
			|CONTINUE ';' 				{printf("jump_statement-> CONTINUE ;	\n");}	
			|BREAK ';' 					{printf("jump_statement-> BREAK ;	\n");}	
			|RETURN expression_opt ';' 	{printf("jump_statement-> RETURN expression_opt;	\n");}
;

translation_unit:
			external_declaration 		{printf("translational_unit->external_declaration\n");}
			|translation_unit external_declaration {printf("translational_unit->translational_unit external_declaration\n");}
;

external_declaration:
			function_definition 		{printf("external_declaration -> function_definition 	\n");}	
			|declaration 				{printf("external_declaration -> declaration	\n");}
;

function_definition:
			declaration_specifiers declarator declaration_list compound_statement 	{printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement 	\n");}
			|declaration_specifiers declarator compound_statement 		{printf("function_definition -> declaration_specifiers declarator compound_statement 	\n");}
;


declaration_list:
			declaration 		{printf("decalaration_list -> declaration\n");}
			|declaration_list declaration 	{printf("decalaration_list -> declaration_list declaration\n");}
;

%%

void yyerror (const char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}
