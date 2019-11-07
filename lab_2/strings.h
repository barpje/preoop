#ifndef strings_h
#define strings_h
typedef struct {
     const char* str;
     int length;
}String;

String *StringInit(const char *s);

void PrintString(String *c);
void RemoveStrings();

#endif

