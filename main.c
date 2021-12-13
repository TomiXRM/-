/*---------------------------------------------------
    
    Written by TomiXRM
    ロシア農民計算
    Please input two values like this
    
    566 877
 ---------------------------------------------------*/

#include <stdio.h>
#define BUFF 32
int A = 13;
int B = 237;
int i = 0;
int oddCount = 0;

int datumA[BUFF];//Aの割っていくデータを入れる配列
int datumB[BUFF];//Aのかけていくデータを入れる配列
char isOddNumber[BUFF];//奇数だった時の配列番号を記憶する変数
int answer = 0;//掛け算の答え
int main (){
	   // -------入力処理-------
        do {//計算短縮のための変数入れ替え処理(Aが小さい数になる)
            printf("Please input two numbers(InputEX:18 136)>\r\n");
            scanf("%d%d",&A,&B);//受け取り
            printf("\r\nYou entered A:%d B:%d\r\n",A,B);
            if(A < 0 || B < 0) {//追加課題.負の入力で再入力を求める
                  printf("please enter the number isn't negative　value!!!\r\n");
            }else{
                  if(A > B){//追加課題
                      int tmp = A;
                      A = B;
                      B = tmp;
                      printf("values were swapped!!!\r\n");//追加課題
                  } 
            }
        } while(A < 0 || B < 0);

        //-------ロシア農民計算-------
        datumA[0] = A;
        datumB[0] = B;
        printf(" ----------------\r\n");
        while (i <= BUFF-1) {
                i++;
                datumA[i] = datumA[i-1] / 2;
                datumB[i] = datumB[i-1] * 2;
                if (datumA[i] % 2 == 1) {
                        printf("*");
                        isOddNumber[oddCount] = i;//奇数だった時の配列番号記憶
                        oddCount++;//奇数の出た数インクリメント
                }else{
                        printf(" ");
                }
                printf(" - A:%d B:%d\r\n",datumA[i],datumB[i]);
                if (datumA[i] == 1) break;//割って1が出た時の処理
        }
        if(i == BUFF - 1){//配列の数を超えた時にエラーを出す
           printf("Error:Buffer overflow!!! Set BUFF value more lager\r\n"); 
           return -1;
        }
        for (int n = 0; n < oddCount; n++){//奇数を足す
                answer += datumB[isOddNumber[n]];
        }
        printf(" ----------------\r\n");
        printf("answer: %d*%d=%d",A,B,answer);
        return 0;
}