%{
	#define COMMENT    9
	#define KEYWORD   10
	#define IDENTIFIER 11
	#define CONSTANT   12
	#define PUNCTUATOR  13
	#define STRING_LITERAL 14
	
%}

Multi-line-Comment	[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
Single-line-Comment	[/][/][^\n]*[\n]
comment 			{Multi-line-Comment}|{Single-line-Comment}

keyword 			"auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"	

digit 				[0-9]
identifier-nondigit [A-Za-z]|"_"
identifier   		{identifier-nondigit}({identifier-nondigit}|{digit})*

escape-sequence         "\'"|"\""|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
c-char                  [^("\'"|"\\"|"\n")]|{escape-sequence}
c-char-sequence         {c-char}+
character-constant	 "\'"{c-char-sequence}"\'"


nonzero-digit 		[1-9]
sign 				[+-]
digit-sequence		{digit}+
enumeration-constant	{identifier}
fractional-constant	({digit-sequence}?"."{digit-sequence})|({digit-sequence}".")
exponent-part 		([eE]{sign}?{digit-sequence})
integer-constant 	{nonzero-digit}({digit})*
floating-constant 	({fractional-constant}{exponent-part}?)|({integer-constant}{exponent-part})
constant 			{integer-constant}|{floating-constant}|{enumeration-constant}|{character-constant}


s-char 				[^("\"""\\""\n")]|{escape-sequence}
s-char-sequence		{s-char}+
string-literal		("\""{s-char-sequence}?"\"")
whitespace		[\t\n]


punctuator			"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"

%%

{Multi-line-Comment} 		{return COMMENT ;}
{Single-line-Comment} 		{return COMMENT;}
{keyword}           		{return KEYWORD;}
{identifier}			{return IDENTIFIER;}
{constant}			{return CONSTANT;}
{punctuator}			{return PUNCTUATOR;}
{string-literal}		{return STRING_LITERAL;}
{whitespace}			{/*ignore whitespace*/}
			
%%


