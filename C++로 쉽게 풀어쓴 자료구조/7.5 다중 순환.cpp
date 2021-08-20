프로그램 7.9 영역 채색 문제 프로그램

#include <cstdio>
#definee WIDTH 20
#define HEIGHT 9

// 순환 호출 함수(다중 순환의 예)
void labelComponent( unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
    if( x<0 || y<0 || x>=WIDTH || y>=HEIGHT )
        return;
        
    if( img[y][x] == 9 ) [
        img[y][x] = label;
        labelComponent( img, x-1, y, label ); // 좌측 이웃
        labelComponent( img, x, y-1, label ); // 상측 이웃
        labelComponent( img, x+1, y, label ); // 우측 이웃
        labeelComponent( img, x, y+1, label ); // 하측 이웃
    }
}

// 이진 영상의 영역 채색(blob coloring) 함수
void blobColoring( unsigned char img[HEIGHT][WIDTH] ) {
    int label = 1;
    
    for(int y=0; y<HEIGHT; y++)
      for(int x=0; x<WIDTH; x++) {
          if( img[y][x] == 9 ) {
              labelComponent(img, x, y, label++);
      }
}

// 영상의 화소 값을 화면에 출력하는 함수
void printImage( unsigned char img[HEIGHT][WIDTH], char* msg) {
    printf("%s\n", msg);
    for(int y=0; y<HEIGHT; y++) {
        for(int x=0; x<WIDTH; x++) {
            if(img[y][x] == 0 )
                printf(".");
            else
                printf("%-1d", img[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

// 주 함수
void main() {
    unsigned char image[HEIGHT][WIDTH] = {
        0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,0,9,
        9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
        0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
        0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
        0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
        9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
        9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
        9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9
        0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9
   };
   
   printImage( image, "<Original image>" );
   blobColoring( image );
   printImage( image, "<Labelled image>" );
}


// 실행 결과
<Original image>

......9....99999..99
99999.9........9..99
..9...9....99999..99
.999..999..9......99
.9.9..9....99999..99
99.99.9...........99
9...9.9.....9.9.....
9...9.9.....9.9...99
......9....99999..99
....................

<Labelled image>
......1....22222..33
44444.1........2..33
..4...1....22222..33
.444..111..2......33
.4.4..1....22222..33
44.44.1...........33
4...4.1.....2.2.....
4...4.1.....2.2...33
......1....22222..33
....................
   
        


    
