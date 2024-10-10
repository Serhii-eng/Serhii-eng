#ifndef STRING_PLUS_H_INCLUDED
#define STRING_PLUS_H_INCLUDED

int is_space(char c);
void remove_symbol(char *s, int pos);
void left_trim(char *s);
void right_trim(char *s);
void all_trim(char *s);
void normalize(char *s);
void character_insertion(char *s);

#endif // STRING_PLUS_H_INCLUDED
