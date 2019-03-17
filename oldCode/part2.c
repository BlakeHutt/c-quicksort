int partition(int array[], int left, int right){
    //printf("Partition\n");
    int pivot = left;
    left++;
    
    while(left<=right && array[left] <= array[pivot]){
        left++;
        //printf("left\n");
    }
        while(left<=right && array[right]>= array[pivot]){
            right--;
            //printf("right\n");
        }
             if (array[left]==array[pivot]){
               // break;
              // printf("if1\n");
            } else if(array[right]==array[pivot]){
                //break;
                //printf("if2\n");
            }else {
            //printf("else\n");
            int k = array[left];
            array[left] = array[right];
            array[right] = k;
            left++, right--;
            }

