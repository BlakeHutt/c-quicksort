int partion(int left, int right, int array[]){

    int pivot = left;
    left++;
    while(left<=right && array[left] <= array[pivot]){
        left++;
    }
    while(right>=left && array[right]>= array[pivot]){
        right--;
    }
    if (array[left]==array[pivot]){

    } else if(array[right]==array[pivot]){

    } else {
        int k = array[left];
        array[left] = array[right];
        array[right] = k;
    }
    left++, right--;

    return pivot;
}

