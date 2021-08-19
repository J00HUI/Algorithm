// 열린 괄호( (,{,[ ) 라면 스택에 푸시, 닫힌 괄호라면 스택의 맨 위에 있는 문자를 pop()
// 꺼낸 문자와 닫힌 괄호가 매칭이 되지 않는다면 오류
// 매칭이 되고, 스택이 비었다면 통과


#include "ArrayStack.h"

bool checkMatching(char* filename){
  FILE *fp = fopen(filename, "r");
  if( fp == NULL)
      error("Error: 파일이 존재하지 않습니다.\n");
  
  int nLine = 1;
  int nChar = 0;
  
  ArrayStack stack;
  char ch;
  
  while( (ch=getc(fp)) != EOF ) {
    if( ch == '\n' ) nLine++;
    nChar++;
    
    if( ch == '[' || ch == '(' || ch == '{' )
      stack.push(ch);
    else if( ch == ']' || ch == ')' || ch == '}' ) {
      int prev = stack.pop();
      if( ( ch == ']' && prev != '[') || ( ch == ')' && prev != '(' ) || ( ch == '}' && prev != '{' )) break;
    }
  }
  
  fclose(fp);
  printf("[%s] 파일 검사 결과:\n", filename);
  if(!stack.isEmpty())
     printf("Error: 문제 발견! (라인수=%d, 문자수="%d)\n\n", nLine, nChar);
  else
     printf(" OK: 괄호 닫기 정상 (라인수=%d, 문자수="%d)\n\n", nLine, nChar);
    
  return stack.isEmpty();
}
void main(){
  checkMatching("ArrayStack.h");
  checkMatching("03장-checkMatching.cpp");
}

