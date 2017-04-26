 #include <stdio.h>
   
      int main(){
	        int i = 0,j = 0,k = 0;
	         for (i = 0;i <= 10;i++){
		           for(j = 0;j <= 5;j++){
		                for(k = 0;k <= 2;k++){
		                     if((i + 2*j +5*k) == 10){
			                      printf("一元%d张 两元%d张 五元%d张\n",i,j,k);
			                   }
			                }
			             }
				       }
				       return 0;
				   }
