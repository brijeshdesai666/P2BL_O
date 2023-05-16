# include <stdio.h>
void tran(int mat[3][3],int res[3][3],int row,int col){
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res[j][i] = mat[i][j];
            }            
        }
}
  int main() {
        int mat[3][3], res[3][3], row,col;
        printf("Enter row and coloum for matrix\n");
        scanf("%d %d",&row,&col);

        printf("Enter Matrix\n");
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                scanf("%d",&mat[i][j]);        
            }            
        }
        tran(mat,res,row,col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d \t",res[i][j]);
            }
            printf("\n");
        }
        
        
  return 0;
  }